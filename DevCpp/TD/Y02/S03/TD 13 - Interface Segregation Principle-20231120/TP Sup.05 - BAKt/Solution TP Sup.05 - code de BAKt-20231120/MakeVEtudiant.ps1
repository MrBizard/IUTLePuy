function end_progress()
{
    $callstack = Get-PSCallStack
    $lst = new-object System.Collections.Generic.HashSet[string]
    foreach($call in $callstack)
    {
        [void]$lst.Add($call.ScriptName)
    }
    Write-Progress -Activity ([System.IO.Path]::GetFileNameWithoutExtension($MyInvocation.PSCommandPath)) -Completed -Id $lst.Count
}

function progress([string] $message)
{
    $callstack = Get-PSCallStack
    $lst = new-object System.Collections.Generic.HashSet[string]
    foreach($call in $callstack)
    {
        [void]$lst.Add($call.ScriptName)
    }

    if($VerbosePreference -ne [System.Management.Automation.ActionPreference]::SilentlyContinue) {
        Write-Output $message
    }
    Write-Progress -Activity ([System.IO.Path]::GetFileNameWithoutExtension($MyInvocation.PSCommandPath)) -CurrentOperation $message -Id $lst.Count
}

function GetVSInstances {
    $vswhere = Get-ChildItem -Path "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer" -Recurse -Filter vswhere.exe
    & $vswhere.FullName -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -format json | ConvertFrom-Json
}

function GetToolsetVersion {
    Param ([string] $VSInstanceDir)

    $fullVersion = Get-Content $VSInstanceDir\VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt
    $version = $fullVersion.Split('.')
    return $version[0] + $version[1].Substring(0,1)
}

function GetConnanfiles {
    param ([System.IO.FileInfo] $SolutionFile)

    $SolutionContent = Get-Content $SolutionFile.FullName
    $Connanfiles = [System.Collections.ArrayList]@()

    $Connanfile = (Join-Path $SolutionFile.Directory.FullName 'conanfile.txt')
    if(Test-Path $Connanfile) {
        $Connanfiles.Add($Connanfile) | Out-Null
    }
    foreach ($line in $SolutionContent) {
        if ($line.StartsWith("Project")) {
            $ProjectPath = Split-Path (($line -split '=')[1] -split ',')[1].Trim(' ').Trim('"')
            $Connanfile = (Join-Path $SolutionFile.Directory.FullName $ProjectPath 'conanfile.txt')
            if(Test-Path $Connanfile) {
                $Connanfiles.Add($Connanfile) | Out-Null
            }
        }
    }
    return $Connanfiles
}

#Compilation
function make {
Param([System.IO.FileInfo]$SolutionFile, [string]$c, [int]$v)

    $VSInstances = GetVSInstances
    foreach($vsi in $VSInstances) {
        if($v -eq (GetToolsetVersion $vsi.installationPath)) {
            $VSInstance = $vsi
        }
    }

    #Test voir si msbuild est accessible
    progress "Définition de l'environnement de développement..."
    try {
        [void](msbuild -version -nologo)
    } catch {
        Import-Module ([System.IO.Path]::Combine($VSInstance.installationPath, 'Common7\Tools\Microsoft.VisualStudio.DevShell.dll'))
        Enter-VsDevShell -VsInstanceId $VSInstance.instanceId -StartInPath $PWD
    }
    if(!$env:VCINSTALLDIR) {
        Write-Error "Impossible de définir les variables d'environnement de Visual Studio." -Category InvalidOperation
        return $false
    }

    Push-Location -Path $SolutionFile.Directory.FullName
    progress "Compilation de $($SolutionFile.Name) en mode $c avec le toolset v$v..."
    if($c -eq "Debug") {
        $runtime = "MDd"
    } else {
        $runtime = "MD"
    }
    $Connanfiles = GetConnanfiles $SolutionFile
    if($VerbosePreference) {
        foreach($Connanfile in $Connanfiles) {
            conan install $Connanfile -g visual_studio --install-folder "$($SolutionFile.Directory.FullName)\x64\$c\.conan" -s arch=x86_64 -s build_type=$c -s compiler.toolset=v$v -s compiler.version=17 -s compiler.runtime=$runtime --build=missing --update | Out-Host
            if($LastExitCode -ne 0) {
                break;
            }
        }
        if($LastExitCode -eq 0) {
            msbuild.exe $SolutionFile "-property:Configuration=$c;PlatformToolset=v$v" -m | Out-Host
        }
    } else {
        foreach($Connanfile in $Connanfiles) {
            $out = conan install $Connanfile -g visual_studio --install-folder "$($SolutionFile.Directory.FullName)\x64\$c\.conan" -s arch=x86_64 -s build_type=$c -s compiler.toolset=v$v -s compiler.version=17 -s compiler.runtime=$runtime --build=missing --update | Out-Host
            if($LastExitCode -ne 0) {
                break;
            }
        }
        if($LastExitCode -eq 0) {
            $out = msbuild $SolutionFile "-property:Configuration=$c;PlatformToolset=v$v" -m "-consoleLoggerParameters:ForceNoAlign;ErrorsOnly" -nologo
        }
    }

    if($LastExitCode -ge 1) {
        Write-Error "La génération de $($SolutionFile.Name) en mode $c a échoué pour la version v$v. Les erreurs étaient :`n$out" -Category InvalidOperation
        Pop-Location
        return $false
    }
    Pop-Location 
    return $true
}

function CreateVEtudiant(
    [System.IO.DirectoryInfo] $DestDir,
    [System.IO.DirectoryInfo] $Dir,
    [String] $RelPath = '.\')
{
	# Si le répertoire doit etre ignoré (Debug, ipch, etc...) -> on sort de la procédure
    if(@('DOCUMENTATION', 'DEBUG', 'RELEASE', 'IPCH', 'DOC').Contains($Dir.Name.ToUpper()) -or 
       $MakeVEtudiantParams.DoNotDiffuse.Contains($RelPath)) {
        return
    }

    if($RelPath -ne '.\') {
        [void](New-Item (Join-Path $DestDir $RelPath) -ItemType Directory)
    }

    # Pour chaque fichier : copie ou nettoyage des parties solutions en fonction de l'extension
    $Files = Get-ChildItem $Dir.FullName -File
    foreach($file in $Files) {
        if($MakeVEtudiantParams.DoNotDiffuse.Contains((Join-Path $RelPath $file.Name))) {
            continue;
        }
        if(@('.cpp','.h','.hpp').Contains($file.Extension.ToLower())) {
            progress "Nettoyage de $(Join-Path $RelPath $file.Name)"
            CleanSolution $file (Join-Path $DestDir $RelPath)
        } elseif(!@('.sdf','.vbs','.suo','.user','.opensdf').Contains($file.Extension.ToLower()) -and 
                 !@('makevetudiant.ps1', 'filestorelease.csv', 'makevetudiant-params.json').Contains($file.Name.ToLower())) {
            progress "Copie de $(Join-Path $RelPath $file.Name)"
            if(!(Test-Path (Join-Path $DestDir $RelPath))) {
                New-Item (Join-Path $DestDir $RelPath) -ItemType Directory
            }
            Copy-Item $file.FullName (Join-Path $DestDir $RelPath)
        }
    }

    # Pour chaque sous répertoire
    $SubDirs = Get-ChildItem $Dir.FullName -Directory
    foreach($SubDir in $SubDirs) {
        CreateVEtudiant $DestDir $SubDir (Join-Path $RelPath $SubDir.Name) 
    }
}

function CleanSolution(
    [System.IO.FileInfo] $InFile,
    [System.IO.DirectoryInfo] $OutDir)
{
    $NbSpecialComment = 0
    $CleanContent = [System.IO.File]::ReadAllLines($InFile.FullName) | ForEach-Object {
        if($_.Trim().ToUpper() -eq "//SOLUTION") {
            $NbSpecialComment++
        } elseif($_.Trim().ToUpper() -eq "//FIN SOLUTION") {
            $NbSpecialComment--
        } elseif($NbSpecialComment -eq 0) {
            $_
        }
    }

    if($CleanContent.Count -eq 0) {
        $CleanContent = ""
    }
    [System.IO.File]::WriteAllLines((Join-Path $OutDir.FullName $InFile.Name), $CleanContent)

    if($NbSpecialComment -ne 0) {
        Write-Error "$($InFile.FullName) : $([System.IO.Path]::GetFileNameWithoutExtension($MyInvocation.PSCommandPath)) error 0001 : Un commentaire `"//Fin Solution`" est manquant" -Category SyntaxError
    }

}



if(!(test-path $MyInvocation.MyCommand.Name)){
    Write-Error "Ce script doit être exécuté depuis son répertoire" -Category InvalidOperation 
    Exit 
}
[System.IO.Directory]::SetCurrentDirectory($PWD);

if(Test-Path .\MakeVEtudiant-params.json) {
    $MakeVEtudiantParams = Get-Content .\MakeVEtudiant-params.json | ConvertFrom-Json
}
else {
    $MakeVEtudiantParams = [PSCustomObject]@{
        DoNotCompile = @()
        DoNotDiffuse = @()
    }
}
$VEtudiantDir = [System.IO.DirectoryInfo]'..\VEtudiant'

$SolutionFiles = Get-Item .\*.sln

$depth = ($PWD -split [System.IO.Path]::DirectorySeparatorChar, 0, "SimpleMatch").Count
for($i=0; $i -lt $depth; $i++) {
    $vsVersionPath = '.\VsVersions.json'
    for($j = 0; $j -lt $i; $j++) {
        $vsVersionPath = "..\$vsVersionPath"
    }
    if(Test-Path $vsVersionPath) {
        break
    }
}
if(!(Test-Path $vsVersionPath)) {
    Write-Error "Le fichier 'VsVersions.json' est introuvable" -Category ObjectNotFound
    Exit
}
$vsVersions = Get-Content $vsVersionPath | ConvertFrom-Json

$lessonRootPath = ([System.IO.FileInfo]$vsVersionPath).Directory


#Création du répertoire VEtudiant
if($VEtudiantDir.Exists) {
    Remove-Item -Path $VEtudiantDir -Recurse -Force
}

[void](New-Item $VEtudiantDir -ItemType Directory)
CreateVEtudiant $VEtudiantDir ".\"

#Création de la documentation de la VEtudiant
if(Test-Path (Join-Path $VEtudiantDir MakeDox.ps1)) {
    Push-Location $VEtudiantDir
    .\MakeDox.ps1
    Pop-Location
}

#Compilation de la solution en mode Release
foreach($SolutionFile in $SolutionFiles) {
    if($MakeVEtudiantParams.DoNotCompile.Contains((Resolve-Path $SolutionFile -Relative))) {
        continue;
    }
    if(make $SolutionFile 'Release' $vsVersions.installVersion) {
        if(-not (Test-Path $VEtudiantDir\Résultat)) {
            [void](New-Item $VEtudiantDir\Résultat -ItemType Directory)
        }
        Copy-Item -Path .\x64\Release\* -Destination "$VEtudiantDir\Résultat" -Recurse -Force
        if(Test-Path "$VEtudiantDir\Résultat\.conan") {
            Remove-Item "$VEtudiantDir\Résultat\.conan" -Recurse -Force
        }
    }
}

#Compilation de la solution pour Linux (si un Makefile est présent)
if(Test-Path Makefile) {
    wsl make
    if($LASTEXITCODE -eq 0) {
        if(-not (Test-Path $VEtudiantDir\Résultat)) {
            [void](New-Item $VEtudiantDir\Résultat -ItemType Directory)
        }
        Copy-Item -Path .\out\* -Destination "$VEtudiantDir\Résultat" -Recurse
    }
}

if(Test-Path 'FilesToRelease.csv') {
    $FilesToRelease = Get-Content .\FilesToRelease.csv -Encoding UTF8 | ForEach-Object {if(!($_ -match '^#')) {$_}} | ConvertFrom-Csv
    foreach($file in $FilesToRelease) {
        if($file.Source.EndsWith('*')) {
            if(!(Test-Path (Join-Path $VEtudiantDir $file.Destination))) {
                [void](New-Item (Join-Path $VEtudiantDir $file.Destination) -ItemType Directory)
            }
        } else {
            $DestDir = [System.IO.Path]::GetDirectoryName((Join-Path $VEtudiantDir $file.Destination))
            if(!(Test-Path $DestDir)){
                [void](New-Item $DestDir -ItemType Directory)
            }
        }
        
        Copy-Item -Path $file.Source -Destination (Join-Path $VEtudiantDir $file.Destination) -Recurse -Force
    }
}

end_progress
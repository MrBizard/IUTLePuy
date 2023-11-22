/*!
 * \file "prog.cpp"
 * Programme principal.
 * 
 * Copyright (c) 2015 by Benjamin ALBOUY-KISSI
 */
#include <Windows.h>
#include <tchar.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <LibGraph2.h>
#include "maze.h"

#include <iostream>
using namespace std;
using namespace LibGraph2;

/*!\mainpage
 * Référez-vous au sujet du TP.
 */


const CSize g_szCase{ 30, 30 }; //!<\brief Taille de l'affichage des cases

//!\if include
//![main]
//!\endif

/*!\todo 1) Créer 4 objets de types CCase A, B, C et D disposées en carré au commentaire <CODE>//A faire 1)</CODE> dans la fonction _tWinMain()\n
 * La première ligne est A - B, la seconde ligne est C - D.\n
 * Les connexions entre les cases doivent être : B à droite de A, D en dessous de B, C à gauche de D.
 */

/*!\todo 2) Afficher les quatres cases A, B, C, D au commentaire <CODE>//A faire 2)</CODE> dans la fonction _tWinMain()\n
* Pour cela, vous créerez une fonction \p drawCase() qui réalisera le travail pour la case passée en paramètre\n
* Les côtés des cases doivent être affichées si le passage vers sa voisine est impossible. Utiliser pour cela
* <CODE>libgraph->setPen(MakeARGB(20, 0, 0, 0), 0.5f);</CODE> et <CODE>libgraph->setPen(MakeARGB(255, 0, 0, 0), 2.0f);</CODE>
* pour respectivement rendre le stylo translucide ou opaque.\n
* Pour le moment, le fond des cases reste transparent : <CODE>libgraph->setSolidBrush(MakeARGB(0, 0, 0, 0));</CODE>
*/

/*!\todo 3) Commentez les créations et utilisation des cases A, B, C, D que vous venez de tester dans la fonction _tWinMain()
 */

/*!\todo 4) Créer un objet de type CMaze au commentaire <CODE>//A faire 4)</CODE> dans la fonction _tWinMain()
 */

/*!\todo 5) Initialisez les variables \p nNbCasesX et \p nNbCasesY en fonction des données internes de l'objet maze au commentaire <CODE>//A faire 5)</CODE> dans la fonction _tWinMain()
 */

/*!\todo 6) Dessiner chaque case du labyrinthe au commentaire <CODE>//A faire 6)</CODE> dans la fonction _tWinMain()\n
 * \n
 * Les cases normales doivent être affichées en fond transparent en utilisant <CODE>libgraph->setSolidBrush(MakeARGB(0, 0, 0, 0));</CODE>\n
 * Les cases visitées doivent être affichées en fond jaune en utilisant <CODE>libgraph->setSolidBrush(MakeARGB(255, 255, 255, 0));</CODE>\n
 * Les cases de mauvais chemin doivent être affichées en fond rouge en utilisant <CODE>libgraph->setSolidBrush(MakeARGB(255, 255, 0, 0));</CODE>\n
 * \n
 * Les côtés des cases doivent être affiché si le passage vers sa voisine est impossible. Utiliser pour cela
 * <CODE>libgraph->setPen(MakeARGB(20, 0, 0, 0), 0.5f);</CODE> et <CODE>libgraph->setPen(MakeARGB(255, 0, 0, 0), 2.0f);</CODE>
 * pour respectivement rendre le stylo translucide ou opaque
 *
 */

/*!\todo 7) Réaliser un pas de l'algorithme de résolution du labyrinthe au commentaire <CODE>//A faire 7)</CODE> dans la fonction _tWinMain()
 */

/*!\todo 8) Dessiner le chemin de résolution du labyrinthe au commentaire <CODE>//A faire 8)</CODE> dans la fonction _tWinMain()\n
 * \n
 * Pour cela, tracez un trait vert (<CODE>libgraph->setPen(MakeARGB(255, 0, 192, 0), 1.0f);</CODE>)
 * le long du parcours déterminé par l'algorithme de résolution du labyrinthe.
 */

/*!\todo 9) Afficher les images des cases de départ d'arrivée et en cours au commentaire <CODE>//A faire 9)</CODE> dans la fonction _tWinMain()\n
 * L'image de la case de départ est dans le fichier \p start.png\n
 * L'image de la case d'arrivée est dans le fichier \p exit.png\n
 * L'image de la case en cours (fin du chemin) est dans le fichier \p me.png
 */

/*!
 * \brief
 * Point d'entrée principal.
 * 
 * \param hInstance
 * Ignoré.
 * 
 * \param hPrevInstance
 * Ignoré.
 * 
 * \param lpCmdLine
 * Ignoré.
 * 
 * \param nCmdShow
 * Ignoré.
 * 
 * \returns
 * 0
 * 
 * \snippet prog.cpp main
 */
int APIENTRY _tWinMain(HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPTSTR lpCmdLine,
  int nCmdShow)
{
  UNREFERENCED_PARAMETER(hInstance);
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  UNREFERENCED_PARAMETER(nCmdShow);

  //Récupération de l'objet principal de LibGraph 2
  ILibGraph2* libgraph = GetLibGraph2();

  //Nombre de cases dans le labyrinthe (configure la taille de la fenêtre)
  size_t nNbCasesX = 1;
  size_t nNbCasesY = 1;

  //A faire 1)

  //A faire 4)

  //A faire 5)

  //Affiche un message d'aide succint
  libgraph->guiMessageBox("Aide", "Appuyez sur la barre d'espace pour faire un pas dans l'algorithme de résolution", msgbtn_types::MsgBtnOK, msgicon_types::MsgIcnInformation);
  //Affiche la fenêtre graphique avec une taille par défaut
  libgraph->show(CSize{ nNbCasesX*g_szCase.m_fWidth, nNbCasesY*g_szCase.m_fHeight });

  evt e;  //Evénement LibGraph 2
  //Boucle principale d'événements
  while (libgraph->waitForEvent(e))
  {
    switch (e.type)  //En fonction du type d'événement
    {
    case evt_type::evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
      //Utilisation des fonctions libgraph->beginPaint() / libgraph->endPaint() pour activer le backbuffer
      libgraph->beginPaint();
      {
        //A faire 2)

        //A faire 6)
        
        //A faire 8)

        //A faire 9)
      }
      libgraph->endPaint();
      break;
    case evt_type::evtKeyDown:  //Enfoncement d'une touche
      switch (e.vkKeyCode) //En fonction de la touche enfoncée
      {
      case VK_SPACE:
        //A faire 7)

        libgraph->askForRefresh();
        break;
      }
      break;
    }
  }
  //Libération de l'objet principal de LibGraph 2
  ReleaseLibGraph2();
  return 0;
}
//!\if include
//![main]
//!\endif



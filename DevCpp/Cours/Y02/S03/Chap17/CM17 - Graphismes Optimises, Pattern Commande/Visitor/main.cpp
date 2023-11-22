
#include <QtCore/QCoreApplication>
#include <iostream>
#include "data.h"
#include "serializationclasses.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Les informations visitées
    CData data;
    CData data2;

    //Les visiteurs
    CStdInReader stdInReader;//Saisie depuis la console
    CStdOutWriter stdOutWriterReader;//Sortie vers la console

    cout << "Saisie des informations depuis la console :" << endl;
    data.acceptSerializer(stdInReader);
    cout << "Vous avez saisi :" << endl;
    data.acceptSerializer(stdOutWriterReader);
    cout << "Sortie vers un fichier JSON..." << endl;
    {
      CJsonWriter JsonWriter("save.json");//Sortie vers un fichier json
      data.acceptSerializer(JsonWriter);
    }
    cout << "Relecture du fichier JSON..." << endl;
    {
      CJsonReader JsonReader("save.json");//Lecture depuis un fichier json
      data2.acceptSerializer(JsonReader);
    }
    cout << "Les informations relues sont :" << endl;
    data2.acceptSerializer(stdOutWriterReader);
    return 0;
}

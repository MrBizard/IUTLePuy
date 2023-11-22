
#include <QtDebug>
#include "qvase.h"
#include "qcontroleur.h"

int main(int argc, char *argv[])
{
  //La sortie de ce programme se fait dans la fen�tre du d�buggueur
  // - Placer un point d'arr�t en fin d'ex�cution
  // - Ex�cuter avec le d�buggueur
  // - Afficher la fen�tre de sortie du d�buggueur (Alt + 2)

  qDebug()<<"Debut du programme";
  QVase monVase;
  QControleur monControle;
  QObject::connect(&monVase, &QVase::plein, &monControle, &QControleur::ArreterRemplir);

  while(monControle.peutRemplir())
    monVase.Remplir();

  qDebug()<<"Fin du programme";
  return 0;
}

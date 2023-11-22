
#include <QtDebug>
#include "qvase.h"
#include "qcontroleur.h"

int main(int argc, char *argv[])
{
  //La sortie de ce programme se fait dans la fenêtre du débuggueur
  // - Placer un point d'arrêt en fin d'exécution
  // - Exécuter avec le débuggueur
  // - Afficher la fenêtre de sortie du débuggueur (Alt + 2)

  qDebug()<<"Debut du programme";
  QVase monVase;
  QControleur monControle;
  QObject::connect(&monVase, &QVase::plein, &monControle, &QControleur::ArreterRemplir);

  while(monControle.peutRemplir())
    monVase.Remplir();

  qDebug()<<"Fin du programme";
  return 0;
}

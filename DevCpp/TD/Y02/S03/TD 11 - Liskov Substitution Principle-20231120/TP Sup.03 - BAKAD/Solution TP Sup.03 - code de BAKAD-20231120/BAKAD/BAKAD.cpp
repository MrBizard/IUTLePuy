/*****************************************************************//**
 * \file   BAKAD.cpp
 * \brief  Programme principal
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include <Windows.h>
#include <LibGraph2.h>
#include <iostream>
#include <memory>
#include <cassert>
#include <list>
#include "AfficheurConsole.h"
#include "AfficheurLibGraph.h"
#include "AfficheurQPicture.h"
#include "Forme.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Carre.h"
#include "Cercle.h"
#include "QWidgetAfficheur.h"
#include <QApplication>

void setPerimetre(CRectangle* pRect, int perim);

/**
 * Fonction principale du programme.
 * 
 * \param argc Nombre d'élément du tableau argv
 * \param argv Tableau des paramètres de ligne de commande
 * \return 0 en cas de succès
 */
int main(int argc, char* argv[])
{
  SetConsoleOutputCP(65001);
  std::unique_ptr<IAfficheur> pAff = std::make_unique<CAfficheurConsole>();
  CForme::setAfficheur(pAff);
  std::list<std::unique_ptr<CForme>> lstFormes;

  lstFormes.push_back(std::make_unique<CRectangle>(10, 20));
  lstFormes.push_back(std::make_unique<CEllipse>(30, 40));
  lstFormes.push_back(std::make_unique<CCarre>(30));
  lstFormes.push_back(std::make_unique<CCercle>(42));

  for (auto& forme : lstFormes)
    forme->afficher();

  //Pour chaque objet, s'il correspond à un rectangle, lui définir un périmètre de 100
  for (auto& forme : lstFormes)
  {
    CRectangle* pRect = dynamic_cast<CRectangle*>(forme.get());
    if (pRect)
      setPerimetre(pRect, 100);
  }

  std::cout << "\nAprès modification des rectangles : \n\n";
  for (auto& forme : lstFormes)
    forme->afficher();


  //Mode d'affichage par libGraph2
  auto pLibgraph = LibGraph2::GetLibGraph2();
  pLibgraph->show(LibGraph2::CSize( 100.0f,100.0f ));
  LibGraph2::evt e;

  pAff = std::make_unique<CAfficheurLibGraph>(pLibgraph);
  CForme::setAfficheur(pAff);

  while (pLibgraph->waitForEvent(e))
  {
    switch (e.type)
    {
    case LibGraph2::evt_type::evtRefresh:
      pLibgraph->beginPaint();
      for (auto& forme : lstFormes)
        forme->afficher();
      pLibgraph->endPaint();
    default:
      break;
    }
  }
  LibGraph2::ReleaseLibGraph2();


  QApplication app(argc, argv);
  QWidgetAfficheur w;
  pAff = std::make_unique<CAfficheurQPicture>(&w);

  CForme::setAfficheur(pAff);

  w.show();
  for (auto& forme : lstFormes)
    forme->afficher();

  return app.exec();
}

/** 
 * \brief
 * Définit le périmètre d'un rectangle en modifiant sa largeur.
 *
 * \param pRect
 * Le rectangle à modifier.
 *
 * \param perim
 * Nouveau périmètre du rectangle.
 *
 * \pre perim doit être pair
 * \pre pRect doit être non nul
 * \post le nouveau périmètre de pRect est perim
 * \invariant la hauteur de pRect est inchangée
 */
void setPerimetre(CRectangle* pRect, int perim)
{
  assert(perim % 2 == 0);
  assert(pRect);

  int nLargeur = perim / 2 - pRect->getHauteur();
  if (nLargeur <= 0)
    throw std::invalid_argument("Le périmètre ne peut pas être inférieur "
      "à deux fois la hauteur du rectangle");
  pRect->setLargeur(perim / 2 - pRect->getHauteur());

  assert((pRect->getHauteur() + pRect->getLargeur()) * 2 == perim);
}



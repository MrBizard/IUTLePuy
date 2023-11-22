#pragma once
#include "Laboratoire.h"
#include "Composante.h"

//!\brief Représente une Université.
// Pour simplifier l'exemple, on considère qu'une université n'a que 2 laboratoires et 3 
// composantes, toujours identiques quelle que soit l'Université créée.
class CUniversite
{
  //!\brief Tableau de 2 laboratoires dans l'Université
  //Le tableau est fait de façon statique pour simplifier l'exemple
  CLaboratoire m_Laboratoires[2];
  //!\brief Tableau de 3 composantes dans l'Université
  //Le tableau est fait de façon statique pour simplifier l'exemple
  CComposante m_Composantes[3];

public:
  //!\brief Construction de l'université
  // Initialise les tableaux membres à des valeurs exemples
  CUniversite(void);
  //!\brief retourne la composante dont la représentation graphique est pointée par le point pos
  // Retourne nullptr si aucune composante n'est présente à cette position.
  CComposante* GetSelectedComp(const LibGraph2::CPoint & pos);
  //!\brief retourne le laboratoire dont la représentation graphique est pointée par le point pos
  // Retourne nullptr si aucun laboratoire n'est présente à cette position.
  CLaboratoire* GetSelectedLab(const LibGraph2::CPoint & pos);

  //!\brief Représente l'Université à l'écran
  void Draw() const;
};


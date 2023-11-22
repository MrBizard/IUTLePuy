/*****************************************************************//**
 * \file   Forme.h
 * \brief  Déclaration de la classe CForme
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include <memory>
#include "Afficheur.h"

/**
 * \brief Classe générique de gestion d'une forme.
 * 
 * Cette classe est rendue abstraite par la fonction virtuelle pure afficher.
 * 
 * Elle contient un pointeur statique vers un objet implémentant l'interface 
 * IAfficheur. Cette objet sera utilisé par les classes filles afin de réaliser
 * leur affichage.
 */
class CForme
{
protected:
  static std::unique_ptr<IAfficheur> s_pAfficheur;
public:
  static void setAfficheur(std::unique_ptr<IAfficheur>& pAfficheur);
  virtual void afficher() const = 0;
};


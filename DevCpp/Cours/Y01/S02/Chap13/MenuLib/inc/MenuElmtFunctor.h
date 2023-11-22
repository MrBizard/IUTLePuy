/*!
* \file  inc\MenuElmtFunctor.h
*
* \brief Déclaration / Définition de la classe CMenuElmtFunctor.
*
* \author Benjamin ALBOUY-KISSI
* \date 2016
* \version 2
*/
#pragma once

#include "MenuElmt.h"
#include <functional>

/*!
* \class CMenuElmtFunctor
*
* \brief Un élément de menu basée sur une fonction.
*
* \author Benjamin ALBOUY-KISSI
* \date 2016
*
* Cette classe permet d'afficher un élément de menu qui, une fois activé, appelle une fonction passée en paramètre de la construction. 
*/
class CMenuElmtFunctor
  : public CMenuElmt
{
  //!\brief Foncteur appelé lors de l'activation de ce menu
  std::function<void()> m_fn;

public:
  /*!
  * \brief Constructeur.
  *
  * \param [in]  c     Le caractère affecté à l'élément de menu.
  * \param [in]  texte Texte affiché pour cet élément de menu.
  * \param [in]  fn    Fonction à appeler lors de l'activation du menu.
  */
  CMenuElmtFunctor(char c, const std::string& texte, const std::function<void()>& fn)
    : CMenuElmt(c, texte), m_fn{ fn } {}
  /*!
  * \brief  Opérateur d'exécution de l'élément de menu.
  *
  * Appelle la fonction passée en paramètre de la construction.
  */
  virtual void operator()(){ m_fn(); }
};


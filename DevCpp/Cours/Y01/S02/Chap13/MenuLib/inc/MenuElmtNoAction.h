/*!
 * \file  inc\MenuElmtNoAction.h
 *
 * \brief Déclaration de la classe CMenuElmtNoAction. 
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 * \version 2
 */
#ifndef MENUELMTNOACTION_H
#define MENUELMTNOACTION_H

#include "MenuElmt.h"

/*!
 * \class CMenuElmtNoAction
 *
 * \brief Un élément de menu qui ne fait rien. 
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 *
 * Cette classe permet d'afficher un élément de menu qui ne fait rien. Cette classe est utilisée pour
 * les éléments CMenu::m_Quit des menus. Cela peut également être utilisé pour afficher un
 * séparateur. 
 */
class CMenuElmtNoAction
  : public CMenuElmt
{
public:

  /*!
   *
   * \brief Constructeur. 
   *
   * \param c           Le caractère affecté à l'élément de menu. 
   * \param [in]  texte Texte affiché pour cet élément de menu. 
   */
  CMenuElmtNoAction(char c, const std::string& texte) : CMenuElmt(c, texte) {}
  /*!
   *
   * \brief  Opérateur d'exécution de l'élément de menu. 
   *
   * Ne fait rien.
   */
  virtual void operator()(){}
};

#endif // MENUELMTNOACTION_H

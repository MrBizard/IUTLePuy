/*!
 * \file  inc\MenuElmtSousMenu.h
 *
 * \brief Déclaration de la classe CMenuElmtSousMenu.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 * \version 2
 */
#ifndef MENUELMTSOUSMENU_H
#define MENUELMTSOUSMENU_H

#include "menu.h"
#include "MenuElmt.h"
#include <memory>

/*!
 * \class CMenuElmtSousMenu
 *
 * \brief Gestion d'un sous-menu dans un menu supérieur.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 *
 * Cette classe est un élément de menu qui affiche un nouveau menu. Elle permet ainsi de gérer des
 * sous-menus. Elle contient une donnée membre publique CMenuElmtSousMenu::m_Menu de type CMenu.
 * Cette donnée permet de gérer le sous menu comme un menu normal.
 *
 * Par défaut, l'élément CMenu::m_Quit de CMenuElmtSousMenu::m_Menu est initialisé avec la touche 'r'
 * et affiche le message "Retour". L'opérateur operator()() exécute la fonction CMenu::MenuLoop() de
 * CMenuElmtSousMenu::m_Menu.
 */
class CMenuElmtSousMenu
  : public CMenuElmt
{
public:
  //! Une référence vers le sous-menu. Son élément CMenu::m_Quit est initialisé avec la touche 'r' et
  //  le texte "Retour".
  std::shared_ptr<CMenu> m_pMenu;

public:
  CMenuElmtSousMenu(char c, const std::string& texte, std::shared_ptr<CMenu> menu);

  /*!
   *
   * \brief  Opérateur d'exécution de l'élément de menu.
   *
   * Exécute la fonction CMenu::MenuLoop() de CMenuElmtSousMenu::m_Menu afin de lancer le sous-menu.
   */
  virtual void operator()(){m_pMenu->MenuLoop();}
};

#endif // MENUELMTSOUSMENU_H

/*!
 * \file  inc\menu.h
 *
 * \brief Declaration de la classe CMenu.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 * \version 2
 */
#ifndef MENU_H
#define MENU_H

#include "MenuElmt.h"
#include "MenuElmtNoAction.h"
#include <stdexcept>
#include <string>
#include <memory>
#include <vector>

/*!
* \brief  Fonction attendant l'appuie d'une touche au clavier dans la console
*
* \return  Le code du caractère de la touche enfoncée
*/
int waitchar(void);

/*!
 * \class CMenu
 *
 * \brief Menu.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 *
 * La classe CMenu gère un menu texte en mode console. Les éléments du menu sont définis à l'aide de
 * la fonction AjouterElement() ou de l'opérateur operator<<(). Pour exécuter le menu, il suffit
 * d'appeler la fonction MenuLoop(). Cette fonction affiche le menu puis attend la saisie d'un
 * élément du menu. \n
 * Il est possible de dériver cette classe afin de lui offrir la possibilité d'effectuer une
 * opération avant l'affichage du menu, et également de modifier la façon de récupérer les
 * touches clavier. Il suffit de redéfinir respectivement les fonctions CMenu::AvantAfficher et
 * CMenu::WaitKey.\n
 */
class CMenu
{
private:
  //! Tableau de pointeur vers des élément de menu. Il s'agit d'un tableau de pointeur car la classe
  //! CMenuElmt étant abstraite, il ne serait pas possible d'instancier un tableau de CMenuElmt. Par
  //! ailleurs, les pointeurs stockées dans ce tableau sont des pointeurs vers des objets appartenant
  //! à ce CMenu. Ainsi la destruction du menu détruit les élément du menu.
  std::vector<std::shared_ptr<CMenuElmt>> m_vpElmts;
  //! Titre du menu. Ce titre est affiché en tête de menu.
  std::string m_strTitre;

  void Afficher();

  //! Rend l'objet incopiable
  CMenu(const CMenu&) = delete;
  //! Rend l'objet incopiable
  CMenu& operator=(const CMenu&) = delete;

public:
  //!\brief Constructeur
  CMenu(std::string strTitre = std::string{});

  //! Elément du menu affiché en dernier qui permet de quitter le menu ou de retourner au menu
  //! supérieur s'il s'agit d'un sous-menu. Il n'exécute aucun action.
  CMenuElmtNoAction m_Quit;

  void AjouterElement(std::shared_ptr<CMenuElmt> e, int nAvant=-1);

  /*!
   *
   * \brief  Ajoute un élément de menu à la fin du menu
   *
   * \return  Une référence vers le menu de façon à pouvoir cascader les appels
   */
  CMenu& operator<<(std::shared_ptr<CMenuElmt> e) { AjouterElement(e); return *this; }
  void MenuLoop();

public:

  //!\name Fonction surchargeable
  //@{
  /*!
   *
   * \brief Appelée juste avant l'affichage du menu.
   *
   * Cette fonction est appelée avant que le menu ne soit affiché. L'implémentation par défaut de
   * cette fonction dans la classe CMenu ne fait rien. Après l'appel de cette fonction, le menu
   * s'affiche puis la fonction WaitKey est appelée.
   */
  virtual void AvantAfficher() {}

  /*!
   *
   * \brief Attend l'appuie sur une touche.
   *
   * \return Le code de la touche enfoncée.
   *
   * L'implémentation par défaut de cette fonction dans la classe CMenu est équivalent à l'appel de
   * la fonction _getche() de la bibliothèque conio.h.
   */
  virtual char WaitKey() {return (char)waitchar();}
  //@}
};

#endif //MENU_H

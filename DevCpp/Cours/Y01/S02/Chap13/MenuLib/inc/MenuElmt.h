/*!
 * \file  inc\MenuElmt.h
 *
 * \brief Declaration de la classe CMenuElmt.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 * \version 2
 */
#ifndef MENUELMT_H
#define MENUELMT_H

#include <iostream>
#include <typeinfo>
#include <stdexcept>
#include <string>

/*!
 * \class CMenuElmt
 *
 * \brief Un élément de menu.
 *
 * \author Benjamin ALBOUY-KISSI
 * \date 2016
 *
 * Cette classe représente un élément de menu. Un élément de menu est muni d'un caractère d'appel
 * accessible à l'aide des fonction SetTouche() et GetTouche(). Ce caractère correspond à la touche
 * qui doit être enfoncée pour que l'élément soit activé. Lorsque l'élément est activé, alors
 * l'opérateur operator()() est appelé.
 *
 * Si la touche associé à l'élément esst le caractère nul, alors l'élément est considéré comme un
 * élément de séparation. C'est-à-dire que son texte est directement affiché sans espace réservé pour
 * sa touche.
 *
 * Pour créer un élément de menu, vous devez dériver cette classe de façon à implémenter l'opérateur
 * operator()(). 
 *
 * Chaque élément de menu est identifié auprès de l'utilisateur par une chaîne de caractères. Vous
 * pouvez accéder à cette chaîne de caractères par les fonction GetTexte() et SetTexte().
 *
 * La classe CMenuElmtSousMenu est un bon exemple de dérivation de cette classe.
 */
class CMenuElmt
{

private:
  //! Caractère d'appel de l'élément de menu.
  char m_cTouche;
  //! Chaîne de caractères affiché à l'utilisateur pour identifier l'élément dans le menu..
  std::string m_strText;

  //! Rend l'objet incopiable
  CMenuElmt(const CMenuElmt&) = delete;
  //! Rend l'objet incopiable
  CMenuElmt& operator =(const CMenuElmt&) = delete;

public:
  CMenuElmt(char c, const std::string& texte);

  //! Définit la touche affectée à cet élément de menu.
  void SetTouche(char c) { m_cTouche = c; }
  //! Définit le texte affiché pour cet élément de menu.
  void SetTexte(const std::string& texte) { m_strText = texte; }

  //! Retourne la touche affectée à cet élément de menu.
  char               GetTouche()const {return m_cTouche;}
  //! Retourne le texte affiché pour cet élément de menu.
  const std::string& GetTexte()const {return m_strText;}

  /*!
   * \brief  Opérateur d'exécution de l'élément de menu.
   *
   * Redéfinissez cet opérateur dans vos classes filles avec le code à exécuter sur l'appel de
   * l'élément de menu.
   */
  virtual void operator()()=0;
};

std::ostream& operator<<(std::ostream& out, const CMenuElmt &e);

#endif //MENUELMT_H

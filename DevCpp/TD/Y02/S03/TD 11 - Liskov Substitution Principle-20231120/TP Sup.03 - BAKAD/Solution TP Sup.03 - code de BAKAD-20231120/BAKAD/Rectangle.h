/*****************************************************************//**
 * \file   Rectangle.h
 * \brief  Déclaration de la classe CRectangle
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Forme.h"

/**
 * \brief Classe de gestion d'un rectangle.
 */
class CRectangle :
  public CForme
{
  int m_nLargeur; ///< Largeur du rectangle
  int m_nHauteur; ///< Hauteur du rectangle

public:
  /**
   * \brief Constructeur.
   * 
   * \param nLargeur Largeur du rectangle
   * \param nHauteur Hauteur du rectangle
   */
  CRectangle(int nLargeur, int nHauteur)
    : m_nLargeur(nLargeur)
    , m_nHauteur(nHauteur)
  {}

  void afficher() const override;

  /**
   * \brief Accesseur en lecture vers la largeur du rectangle.
   * 
   * \return la largeur du rectangle.
   */
  virtual int getLargeur() const { return m_nLargeur; }

  /**
   * \brief Accesseur en lecture vers la hauteur du rectangle.
   *
   * \return la hauteur du rectangle.
   */
  virtual int getHauteur() const { return m_nHauteur; }

  /**
   * \brief Accesseur en écriture vers la largeur du rectangle.
   *
   * \param nLargeur la nouvelle largeur du rectangle.
   */
  virtual void setLargeur(int nLargeur) { m_nLargeur = nLargeur; }

  /**
   * \brief Accesseur en écriture vers la hauteur du rectangle.
   *
   * \param nHauteur la nouvelle hauteur du rectangle.
   */
  virtual void setHauteur(int nHauteur) { m_nHauteur = nHauteur; }
};


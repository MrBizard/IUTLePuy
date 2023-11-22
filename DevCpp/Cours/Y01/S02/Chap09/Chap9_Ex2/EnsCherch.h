#pragma once
#include "incLibGraph2.h"

//!\brief Représente un enseignant-chercheur
class CEnsCherch
{
  //!\brief Couleur qui représente l'enseignant-chercheur
  LibGraph2::ARGB m_Color;
  //!\brief Position de l'enseignant-chercheur
  LibGraph2::CPoint m_Position;
  //!\brief Spécifie si l'enseignant-chercheur doit être affiché "sélectionné"
  bool m_bShowBoundingBox;

public:
  //!\brief Constructeur
  CEnsCherch(const LibGraph2::CPoint& pos=LibGraph2::CPoint());
  //!\brief Affiche l'enseignant-chercheur à l'écran
  void Draw() const;
  //!\brief Accesseur de la position
  const LibGraph2::CPoint& GetPosition() const {return m_Position;}
  //!\brief Modificateur de la position
  CEnsCherch& SetPosition(const LibGraph2::CPoint& pos) {m_Position = pos; return *this;}
  //!\brief Modificateur de l'affichage "sélectionné"
  void ShowBoundingBox(bool bShow=true) {m_bShowBoundingBox = bShow;}
  //!\brief Vérifie si les coordonnées d'un point sont dans la représentation graphique de cet enseignant-chercheur.
  bool IsInside(const LibGraph2::CPoint& pos) const;
};


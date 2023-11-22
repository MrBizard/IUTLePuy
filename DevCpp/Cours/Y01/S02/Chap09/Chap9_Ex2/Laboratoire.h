#pragma once
#include <list>
#include <memory>
#include "incLibGraph2.h"
#include "EnsCherch.h"

//!\brief Représente un laboratoire d'Université
class CLaboratoire
{
  //!\brief Nom de le laboratoire
  LibGraph2::CString m_strName;
  //!\brief Rectangle représentant le laboratoire à l'écran
  LibGraph2::CRectangle m_rect;
  //!\brief Liste de pointeurs vers des enseignants-chercheurs
  // Représente une relation d'agrégation entre la classe CLaboratoire et la classe CEnsCherch.
  // Les objets CEnsCherch peuvent exister sans instance de CLaboratoire
  std::list<std::shared_ptr<CEnsCherch>> m_pEnsCherchs;
public:
  //!\brief Constructeur
  CLaboratoire(const LibGraph2::CString& strName = "", const LibGraph2::CRectangle& rect = LibGraph2::CRectangle());
  //!\brief Associe un enseignant-chercheur à ce laboratoire
  void Associer(std::shared_ptr<CEnsCherch> pEnsCherch);
  //!\brief Dissocie un enseignant-chercheur de ce laboratoire
  void Dissocier(std::shared_ptr<CEnsCherch> pEnsCherch);
  //!\brief Dessine le laboratoire à l'écran avec des segments la reliant à chaque enseignant-chercheur associé
  void Draw() const;
  //!\brief Vérifie si les coordonnées d'un point sont dans la représentation graphique de ce laboratoire.
  bool IsInside(const LibGraph2::CPoint& pos) const;
  //!\brief Retourne le point central de la représentation de ce laboratoire.
  LibGraph2::CPoint GetCenter()const {return LibGraph2::CPoint(m_rect.m_ptTopLeft + LibGraph2::CPoint(m_rect.m_szSize.m_fWidth/2, m_rect.m_szSize.m_fHeight/2));}
};


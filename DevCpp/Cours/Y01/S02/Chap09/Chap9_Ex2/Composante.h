#pragma once
#include <list>
#include <memory>
#include "incLibGraph2.h"
#include "EnsCherch.h"

//!\brief Représente une composante d'Université
class CComposante
{
  //!\brief Nom de la composante
  LibGraph2::CString m_strName;
  //!\brief Rectangle représentant la composante à l'écran
  LibGraph2::CRectangle m_rect;
  //!\brief liste de pointeurs vers des enseignants-chercheurs
  // Représente une relation d'agrégation entre la classe CComposante et la classe CEnsCherch.
  // Les objets CEnsCherch peuvent exister sans instance de CComposante
  std::list<std::shared_ptr<CEnsCherch>> m_pEnsCherchs;

public:
  //!\brief Constructeur
  CComposante(const LibGraph2::CString& strName = "", const LibGraph2::CRectangle& rect = LibGraph2::CRectangle());
  //!\brief Associe un enseignant-chercheur à cette composante
  void Associer(std::shared_ptr<CEnsCherch> pEnsCherch);
  //!\brief Dissocie un enseignant-chercheur de cette composante
  void Dissocier(std::shared_ptr<CEnsCherch> pEnsCherch);
  //!\brief Dessine la composante à l'écran avec des segments la reliant à chaque enseignant-chercheur associé
  void Draw() const;
  //!\brief Vérifie si les coordonnées d'un point sont dans la représentation graphique de cette composante.
  bool IsInside(const LibGraph2::CPoint& pos) const;
  //!\brief Retourne le point central de la représentation de cette composante.
  LibGraph2::CPoint GetCenter()const {return m_rect.m_ptTopLeft + LibGraph2::CPoint(m_rect.m_szSize.m_fWidth/2, m_rect.m_szSize.m_fHeight/2);}
};


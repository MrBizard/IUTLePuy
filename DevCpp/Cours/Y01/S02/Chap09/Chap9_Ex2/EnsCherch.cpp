#include "EnsCherch.h"

CEnsCherch::CEnsCherch(const LibGraph2::CPoint& pos)
  : m_Position(pos)
  , m_bShowBoundingBox(false)
{
  m_Color = LibGraph2::MakeARGB(255, rand() % 256, rand() % 256, rand() % 256);
}


void CEnsCherch::Draw() const
{
  LibGraph2::ILibGraph2* pLibGraph = LibGraph2::GetLibGraph2();
  pLibGraph->setPen(m_Color, 5);
  pLibGraph->setSolidBrush(m_Color);

  //corps
  pLibGraph->drawLine(LibGraph2::CPoint(0, -10) + m_Position, LibGraph2::CPoint(0, 20) + m_Position);
  //bras gauche
  pLibGraph->drawLine(LibGraph2::CPoint(0, -10) + m_Position, LibGraph2::CPoint(-15, 5) + m_Position);
  //bras droit
  pLibGraph->drawLine(LibGraph2::CPoint(0, -10) + m_Position, LibGraph2::CPoint(15, 5) + m_Position);
  //jambe gauche
  pLibGraph->drawLine(LibGraph2::CPoint(0, 20) + m_Position, LibGraph2::CPoint(-15, 45) + m_Position);
  //jambe droite
  pLibGraph->drawLine(LibGraph2::CPoint(0, 20) + m_Position, LibGraph2::CPoint(15, 45) + m_Position);
  //tête
  pLibGraph->drawEllipse(LibGraph2::CRectangle(LibGraph2::CPoint(-7, -28) + m_Position, LibGraph2::CSize(14, 14)));

  if (m_bShowBoundingBox)
  {
    LibGraph2::CRectangle BoundingBox(m_Position + LibGraph2::CPoint(-17, -30), LibGraph2::CSize(34, 77));
    pLibGraph->setPen(LibGraph2::MakeARGB(255, 255, 0, 0), 2, LibGraph2::pen_DashStyles::Dash);
    pLibGraph->setSolidBrush(LibGraph2::MakeARGB(50, 0, 127, 255));
    pLibGraph->drawRectangle(BoundingBox);
  }
}

bool CEnsCherch::IsInside(const LibGraph2::CPoint& pos) const
{
  LibGraph2::CRectangle BoundingBox(m_Position + LibGraph2::CPoint(-17, -30), LibGraph2::CSize(34, 77));

  return (pos.m_fX >= BoundingBox.m_ptTopLeft.m_fX && pos.m_fX <= BoundingBox.m_ptTopLeft.m_fX + BoundingBox.m_szSize.m_fWidth
          && pos.m_fY >= BoundingBox.m_ptTopLeft.m_fY && pos.m_fY <= BoundingBox.m_ptTopLeft.m_fY + BoundingBox.m_szSize.m_fHeight);
}
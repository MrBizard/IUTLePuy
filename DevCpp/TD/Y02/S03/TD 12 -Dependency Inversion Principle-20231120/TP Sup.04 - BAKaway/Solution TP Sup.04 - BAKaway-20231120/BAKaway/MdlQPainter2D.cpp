#include "MdlQPainter2D.h"
//Solution
#include "Position2D.h"
#include <cassert>

void CMdlQPainter2D::afficher(CPosition::const_ptr pos) const
{
  auto pos2D = std::dynamic_pointer_cast<const CPosition2D>(pos);
  if(pos2D)
    m_painter.drawPixmap(pos2D->getX()-m_size.width()/2, pos2D->getY()-m_size.height()/2, m_size.width(), m_size.height(), m_pixmap);
  else
    m_painter.drawPixmap(25 - m_size.width() / 2, 25 - m_size.height() / 2, m_size.width(), m_size.height(), m_pixmap);
}

/*
//Fin Solution
void CMdlQPainter2D::afficher() const
{
  m_painter.drawPixmap(25 - m_size.width() / 2, 25 - m_size.height() / 2, m_size.width(), m_size.height(), m_pixmap);
}
//Solution
*/
//Fin Solution
#include "Laboratoire.h"

CLaboratoire::CLaboratoire(const LibGraph2::CString& strName, const LibGraph2::CRectangle& rect)
  : m_strName(strName)
  , m_rect(rect)
{
}

void CLaboratoire::Associer(std::shared_ptr<CEnsCherch> pEnsCherch)
{
  Dissocier(pEnsCherch);
  m_pEnsCherchs.push_back(pEnsCherch);
}

void CLaboratoire::Dissocier(std::shared_ptr<CEnsCherch> pEnsCherch)
{
  auto itWhere = find(m_pEnsCherchs.begin(), m_pEnsCherchs.end(), pEnsCherch);
  if (itWhere != m_pEnsCherchs.end())
    m_pEnsCherchs.erase(itWhere);
}

void CLaboratoire::Draw() const
{
  LibGraph2::ILibGraph2* pLibGraph = LibGraph2::GetLibGraph2();
  pLibGraph->setPen(LibGraph2::MakeARGB(255, 0, 0, 0), 3, LibGraph2::pen_DashStyles::Dash);
  pLibGraph->setSolidBrush(LibGraph2::MakeARGB(0, 0, 0, 0));

  pLibGraph->drawRectangle(m_rect);

  pLibGraph->setFont("Calibri", 12, LibGraph2::FontStyleBold);

  LibGraph2::CRectangle textBounds;
  pLibGraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
  pLibGraph->getStringDimension(m_strName, m_rect.m_ptTopLeft, textBounds);
  pLibGraph->drawString(m_strName, m_rect.m_ptTopLeft + LibGraph2::CPoint((m_rect.m_szSize.m_fWidth - textBounds.m_szSize.m_fWidth) / 2, textBounds.m_szSize.m_fHeight));

  pLibGraph->setPen(LibGraph2::MakeARGB(255, 255, 0, 0), 3, LibGraph2::pen_DashStyles::Dot);
  LibGraph2::CPoint center(m_rect.m_ptTopLeft + LibGraph2::CPoint(m_rect.m_szSize.m_fWidth / 2, m_rect.m_szSize.m_fHeight / 2));
  pLibGraph->setPen(LibGraph2::MakeARGB(255, 255, 0, 0), 3, LibGraph2::pen_DashStyles::Dot);
  for (auto pEnsCherch : m_pEnsCherchs)
  {
    pLibGraph->drawLine(GetCenter(), pEnsCherch->GetPosition());
  }
}

bool CLaboratoire::IsInside(const LibGraph2::CPoint& pos) const
{
  return (pos.m_fX >= m_rect.m_ptTopLeft.m_fX && pos.m_fX <= m_rect.m_ptTopLeft.m_fX + m_rect.m_szSize.m_fWidth
          && pos.m_fY >= m_rect.m_ptTopLeft.m_fY && pos.m_fY <= m_rect.m_ptTopLeft.m_fY + m_rect.m_szSize.m_fHeight);
}


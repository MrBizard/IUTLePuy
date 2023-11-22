#include "Universite.h"

CUniversite::CUniversite(void)
{
  LibGraph2::ILibGraph2* pLibGraph = LibGraph2::GetLibGraph2();
  LibGraph2::CSize szWnd = pLibGraph->getSize();

  m_Laboratoires[0] = CLaboratoire("Institut Pascal", LibGraph2::CRectangle(LibGraph2::CPoint(10, 40), LibGraph2::CSize(szWnd.m_fWidth / 3 - 120, (szWnd.m_fHeight - 40) / 2 - 10)));
  m_Laboratoires[1] = CLaboratoire("LIMOS", LibGraph2::CRectangle(LibGraph2::CPoint(10, (szWnd.m_fHeight - 40) / 2 + 40), LibGraph2::CSize(szWnd.m_fWidth / 3 - 120, (szWnd.m_fHeight - 40) / 2 - 10)));

  m_Composantes[0] = CComposante("IUT", LibGraph2::CRectangle(LibGraph2::CPoint(2 * szWnd.m_fWidth / 3 + 110, 40), LibGraph2::CSize(szWnd.m_fWidth / 3 - 120, (szWnd.m_fHeight - 40) / 3 - 10)));
  m_Composantes[1] = CComposante("Fac de médecine", LibGraph2::CRectangle(LibGraph2::CPoint(2 * szWnd.m_fWidth / 3 + 110, (szWnd.m_fHeight - 40) / 3 + 40), LibGraph2::CSize(szWnd.m_fWidth / 3 - 120, (szWnd.m_fHeight - 40) / 3 - 10)));
  m_Composantes[2] = CComposante("Ecole de droit", LibGraph2::CRectangle(LibGraph2::CPoint(2 * szWnd.m_fWidth / 3 + 110, 2 * (szWnd.m_fHeight - 40) / 3 + 40), LibGraph2::CSize(szWnd.m_fWidth / 3 - 120, (szWnd.m_fHeight - 40) / 3 - 10)));
}


void CUniversite::Draw() const
{
  LibGraph2::ILibGraph2* pLibGraph = LibGraph2::GetLibGraph2();
  LibGraph2::CSize szWnd = pLibGraph->getSize();

  pLibGraph->setFont("Calibri", 16, LibGraph2::FontStyleBold);

  LibGraph2::CRectangle textBounds;
  pLibGraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
  pLibGraph->getStringDimension("LABORATOIRES", LibGraph2::CPoint(0, 0), textBounds);
  pLibGraph->drawString("LABORATOIRES", LibGraph2::CPoint((szWnd.m_fWidth / 3 - 120 - textBounds.m_szSize.m_fWidth) / 2 + 10, (40 - textBounds.m_szSize.m_fHeight) / 2));

  pLibGraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
  pLibGraph->getStringDimension("COMPOSANTES", LibGraph2::CPoint(0, 0), textBounds);
  pLibGraph->drawString("COMPOSANTES", LibGraph2::CPoint(2 * szWnd.m_fWidth / 3 + 110 + (szWnd.m_fWidth / 3 - 120 - textBounds.m_szSize.m_fWidth) / 2 + 10, (40 - textBounds.m_szSize.m_fHeight) / 2));

  for (int i = 0; i < 3; ++i)
    m_Composantes[i].Draw();

  for (int i = 0; i < 2; ++i)
    m_Laboratoires[i].Draw();
}

CComposante* CUniversite::GetSelectedComp(const LibGraph2::CPoint& pos)
{
  for (int i = 0; i < 3; ++i)
  {
    if (m_Composantes[i].IsInside(pos))
      return &m_Composantes[i];
  }
  return nullptr;
}

CLaboratoire* CUniversite::GetSelectedLab(const LibGraph2::CPoint& pos)
{
  for (int i = 0; i < 2; ++i)
  {
    if (m_Laboratoires[i].IsInside(pos))
      return &m_Laboratoires[i];
  }
  return nullptr;
}

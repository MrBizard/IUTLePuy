#include "Doc.h"
#include "incLibGraph2.h"

#include <fstream>

CDoc::CDoc(const std::string& strFileName)
{
  std::string txt;
  std::ifstream ifs{ strFileName };
  ifs >> txt;
  //txt should be "Text"

  char c;
  ifs >> c >> std::noskipws;
  //c should be '\"'
  ifs >> c;
  //c should be the first letter of font name
  while (c != '\"')
  {
    m_fontName.push_back(c);
    ifs >> c;
  }

  ifs >> std::skipws >> m_fFontSize;
  unsigned int val;
  ifs >> val;
  m_uiFontStyle = (LibGraph2::font_styles)val;

  ifs >> c >> std::noskipws;
  //c should be '\"'
  ifs >> c;
  //c should be the first letter of text
  while (c != '\"')
  {
    m_strText.push_back(c);
    ifs >> c;
  }

  ifs >> std::skipws >> m_ptPos.m_fX;
  ifs >> m_ptPos.m_fY;

  unsigned short a, r, g, b;
  ifs >> a >> r >> g >> b;
  m_coul = LibGraph2::MakeARGB(static_cast<BYTE>(a), static_cast<BYTE>(r), static_cast<BYTE>(g), static_cast<BYTE>(b));
}


void CDoc::DrawIt()
{
  LibGraph2::ILibGraph2* pLibGraph = LibGraph2::GetLibGraph2();
  pLibGraph->setFont(m_fontName, m_fFontSize, m_uiFontStyle);
  pLibGraph->setSolidBrush(m_coul);
  pLibGraph->drawString(m_strText, m_ptPos);
}

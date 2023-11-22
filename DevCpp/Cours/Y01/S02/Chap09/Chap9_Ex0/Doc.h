#pragma once
#include <string>
#include <LibGraph2.h>
#include <iostream>
class CDoc
{
public:
private:
  std::string m_strText;
  std::string m_fontName;
  float m_fFontSize;
  LibGraph2::font_styles m_uiFontStyle;
  LibGraph2::CPoint m_ptPos;
  LibGraph2::ARGB m_coul;

public:

  CDoc(const std::string& strFileName);
  void DrawIt();
};


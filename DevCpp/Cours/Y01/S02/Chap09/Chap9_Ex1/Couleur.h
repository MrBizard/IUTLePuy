#pragma once

#include <iostream>

class CCouleur
{
public:
  unsigned char m_R;
  unsigned char m_G;
  unsigned char m_B;

  CCouleur(unsigned char r=0, unsigned char g=0, unsigned char b=0);
};

std::ostream& operator<<(std::ostream& o, const CCouleur& coul);

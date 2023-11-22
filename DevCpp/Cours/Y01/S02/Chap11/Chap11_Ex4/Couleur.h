#pragma once

#include <iostream>

class CCouleur
{
public:
  unsigned char m_R;
  unsigned char m_G;
  unsigned char m_B;

  CCouleur(unsigned char r=0, unsigned char g=0, unsigned char b=0)
    : m_R{ r }, m_G{ g }, m_B{ b }{}
};

std::ostream& operator<<(std::ostream& o, const CCouleur& coul);
std::istream& operator>>(std::istream& i, CCouleur& coul);

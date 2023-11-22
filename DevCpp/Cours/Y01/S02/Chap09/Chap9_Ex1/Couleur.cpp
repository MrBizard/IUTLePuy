#include "couleur.h"
#include <iostream>

CCouleur::CCouleur(unsigned char r, unsigned char g, unsigned char b)
  : m_R(r)
  , m_G(g)
  , m_B(b)
{
  std::cout << "Construction d'une couleur de valeur " << *this << '\n';
}

std::ostream& operator<<(std::ostream& o, const CCouleur& coul)
{
  return o << "(" << (int)coul.m_R << ", " << (int)coul.m_G << ", " << (int)coul.m_B << ")";
}

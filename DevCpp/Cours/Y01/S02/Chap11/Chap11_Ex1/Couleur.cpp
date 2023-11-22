#include "couleur.h"

std::ostream& operator<<(std::ostream& o, const CCouleur& coul)
{
  return o << "(" << (int)coul.m_R << ", " << (int)coul.m_G << ", " << (int)coul.m_B << ")";
}
#include <Windows.h>
#include "inc_libgraph2.h"
#include "vecteur2D.h"
#include "carre.h"
#include <iostream>

int main(void)
{
  SPoint2D point1;  SPoint2D point2;  SPoint2D point3;  SPoint2D point4;
  point1.m_dX = 0;  point2.m_dX = 1;  point3.m_dX = 1;  point4.m_dX = 0;
  point1.m_dY = 0;  point2.m_dY = 0;  point3.m_dY = 1;  point4.m_dY = 1;

  SCarre carre;
  carre.Creer(point1, point2);
  std::cout << "Le p‚rimŠtre de carre vaut : " << carre.Perimetre() << '\n';

  SCarre carre2;
  carre2.Copier(carre);
  std::cout << "Le p‚rimŠtre de carre2 vaut : " << carre2.Perimetre() << '\n';

  return 0;
}

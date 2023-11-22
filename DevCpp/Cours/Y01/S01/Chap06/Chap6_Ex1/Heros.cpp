#include "Heros.h"

#include <iostream>

void SHeros::Init(std::string strImage)
{
  x = 0;
  y = 0;
  strHeros = strImage;
}

void SHeros::Deplacer(int xDeplacement, int yDeplacement)
{
  x += xDeplacement;
  y += yDeplacement;
}

void SHeros::Afficher()
{
  std::cout << "Je suis un h‚ros." << std::endl;
  std::cout << "Je suis … la position x=" << x << " y=" << y << '\n';
  std::cout << "L'image qui me repr‚sente est stock‚e dans le fichier " << strHeros << '\n';
  std::cout << '\n';
}

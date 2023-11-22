#include <iostream>
using namespace std;

#include "tableau.h"

void main()
{
  CTableau2D<float> tabDeFloat{ 3, 4 }; //Un tableau 2D de float
  CTableau2D<int> tabDeInt;             //Un tableau 2D de int

  for (size_t i = 0; i < tabDeFloat.getNbRows(); i++)
    for (size_t j = 0; j < tabDeFloat.getNbCols(); j++)
      tabDeFloat.at(i, j) = i*tabDeFloat.getNbCols() + j + 0.1f;

  cout << "Le tableau de flottants : " << endl
       << tabDeFloat << endl
       << endl;

  tabDeInt.Copier(tabDeFloat);

  cout << "Le tableau d'entiers : " << endl
       << tabDeInt << endl
       << endl;

  tabDeFloat = tabDeInt;

  cout << "Le tableau de flottants apres tabDeFloat = tabDeInt : " << endl
       << tabDeFloat << endl
       << endl;

}

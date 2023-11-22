#include "stdafx.h"
#include "fonctions.h"

unsigned long long fibonacci_rec(unsigned int n)
{
  if (n == 0)
    return 0;
  if (n <= 1)
    return 1;
  return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

unsigned long long fibonacci_it(unsigned int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  unsigned long long Fn_2 = 0, Fn_1 = 1, Fn;

  for (unsigned int i = 2; i <= n; ++i)
  {
    //Calcul de Fn
    Fn = Fn_2 + Fn_1;
    //Calcul de Fn_1 et Fn_2 pour l'itération suivante
    Fn_2 = Fn_1;
    Fn_1 = Fn;
  }
  return Fn;
}

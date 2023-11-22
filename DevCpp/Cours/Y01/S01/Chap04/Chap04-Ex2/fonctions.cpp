#include "fonctions.h"
#include <cmath>

/**
 *  Calcule la division entière de deux nombres.
 *
 * \param dividende
 * \param diviseur
 * \return un tableau de deux entiers contenant dans cet ordre le quotient et le reste
 */
std::array<int, 2> DivisionEntiere(unsigned int dividende, int diviseur)
{
  int signe = 1;
  if (diviseur < 0)
  {
    signe = -1;
    diviseur = -diviseur;
  }
  int quotient = 0;
  int reste = dividende;
  while (reste >= diviseur)
  {
    reste -= diviseur;
    quotient += signe;
  }
  std::array res = { quotient, reste };
  return res;
}

/**
 *  Calcule un nombre de la suite de Fibonacci.
 *
 * \param n Valeur de l'indice de la suite de Fibonacci
 * \return La valeur du nombre de la suite de Fibonacci à l'indice n.
 */
unsigned long long Fibonacci(unsigned int n)
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

/**
 *  Fonction qui inverse l'ordre des chiffres d'un nombre.
 *
 * \param n Nombre dont les chiffres doivent être inversés.
 * \return Le nombre dont les chiffres ont été inversés.
 */
unsigned int InverserNombre(unsigned int n)
{
  unsigned int ret = 0;
  while (n != 0)
  {
    ret *= 10;
    unsigned int chiffre = n - (n / 10) * 10;
    ret += chiffre;
    n /= 10;
  }
  return ret;
}

/**
 *  Trouve tous les nombres premiers inférieurs à une limite.
 *
 * \param max Limite max de la recherche
 * \return Un tableau d'entier contenant tous les nombres premiers inférieurs à la limite max.
 */
std::vector<unsigned int> TrouverNombrePremier(unsigned int max)
{
  std::vector<unsigned int> premiers;
  for (unsigned int n = 2; n <= max; n++)
  {
    bool bPremier = true;
    for (unsigned int diviseur = 2; diviseur <= std::sqrt(n); ++diviseur)
    {
      if (n % diviseur == 0)
      {
        bPremier = false;
        break;
      }
    }
    if (bPremier)
      premiers.push_back(n);
  }
  return premiers;
}

/**
 *  Trouve tous les nombres parfaits inférieurs à une limite.
 *
 * \param max Limite max de la recherche
 * \return Un tableau d'entier contenant tous les nombres parfaits inférieurs à la limite max.
 */
std::vector<unsigned int> TrouverNombreParfait(unsigned int max)
{
  std::vector<unsigned int> parfaits;
  for (unsigned int n = 2; n <= max; n++)
  {
    unsigned int somme = 0;
    for (unsigned int diviseur = 1; diviseur <= n / 2; ++diviseur)
    {
      if (n % diviseur == 0)
        somme += diviseur;
    }
    if (somme == n)
      parfaits.push_back(n);
  }
  return parfaits;
}



#include "fonctions.h"
#include <sstream>

double plus(double a, double b) {
	return a + b;
}
double moins(double a, double b) {
	return a - b;
}
double fois(double a, double b) {
	return a * b;
}
double divise(double a, double b) {
	return a / b;
}

/**
 *  Décode une chaine de caractères représentant un calcul.
 * 
 * \param[in] calcul La chaine de caractères à décoder
 * \param[out] operandes Tableau des opérandes (nombres) dans l'ordre du calcul 
 * \param[out] operateurs Tableau des opérateurs à appliquer dans l'ordre du calcul
 * 
 * \remark La chaine doit être bien formée, aucune vérification n'est faite dans cette fonction.
 * Elle doit comporter une alternance opérande - opérateur et ne comporter aucun espace.
 */
void decodeCalcul(const std::string& calcul, std::vector<double>& operandes, std::vector<OperatorFunc>& operateurs)
{
  std::stringstream ss(calcul);
	operandes.clear();
	operateurs.clear();
	bool bAttendOperande = true;
	while (!ss.eof())
	{
		bool bBadOperation = false;
		if(bAttendOperande)
		{
			double operande;
			ss >> operande;
			if (ss.fail())
				bBadOperation = true;
			operandes.push_back(operande);
			bAttendOperande = false;
		}
		else
		{
			char operateur;
			ss >> operateur;
			if (ss.fail())
				bBadOperation = true;
			if (!ss.fail())
			{
				switch (operateur)
				{
				case '+':
					operateurs.push_back(plus);
					break;
				case '-':
					operateurs.push_back(moins);
					break;
				case '*':
					operateurs.push_back(fois);
					break;
				case '/':
					operateurs.push_back(divise);
					break;
				default:
					bBadOperation = true;
				}
			}
			bAttendOperande = true;
		}
		if(bBadOperation)
		{
			operandes = { std::numeric_limits<double>::quiet_NaN() };
			operateurs.clear();
			return;
		}
	}
}

/**
 *  Calcule une expression mathématique composée d'opérandes et d'opérateurs en alternance.
 * 
 * Le tableau d'opérande doit comporter un élément de plus que le tableau d'opérateur.
 * L'expression la plus courte étant seulement un nombre sans aucun opérateur.
 * 
 * \param operandes Un tableau d'opérande
 * \param operateurs Un tableau d'opérateurs
 * \return Le résultat du calcul.
 */
double calcule(const std::vector<double>& operandes, const std::vector<OperatorFunc>& operateurs)
{
	double res = operandes.front();
	for (size_t i = 0; i < operateurs.size(); ++i)
	{
		res = operateurs[i](res, operandes[i + 1]);
	}
	return res;
}

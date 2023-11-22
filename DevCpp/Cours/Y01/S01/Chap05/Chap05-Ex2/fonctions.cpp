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
 *  D�code une chaine de caract�res repr�sentant un calcul.
 * 
 * \param[in] calcul La chaine de caract�res � d�coder
 * \param[out] operandes Tableau des op�randes (nombres) dans l'ordre du calcul 
 * \param[out] operateurs Tableau des op�rateurs � appliquer dans l'ordre du calcul
 * 
 * \remark La chaine doit �tre bien form�e, aucune v�rification n'est faite dans cette fonction.
 * Elle doit comporter une alternance op�rande - op�rateur et ne comporter aucun espace.
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
 *  Calcule une expression math�matique compos�e d'op�randes et d'op�rateurs en alternance.
 * 
 * Le tableau d'op�rande doit comporter un �l�ment de plus que le tableau d'op�rateur.
 * L'expression la plus courte �tant seulement un nombre sans aucun op�rateur.
 * 
 * \param operandes Un tableau d'op�rande
 * \param operateurs Un tableau d'op�rateurs
 * \return Le r�sultat du calcul.
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

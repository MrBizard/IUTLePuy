#include <iostream>
#include <cmath>
#include <Windows.h>

#define _N std::cout << '\n';

#define Pi 3.141592653589793238462643383

#define DegToRad(angle)angle * Pi / 180.0

#define Tronc(value,tronc)double(int(value * tronc))/1000.0

#define ToLower(c)char((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ? c - 'A' + 'a' : c)

#define ToUpper(c)char(c - 'a' + 'A')

#define InvertInt(a,b){int c = a;a = b;b = c;}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int n = 1;
	while (n != 0)
	{
		_N; std::cout << "donne moi le numéro d'éxercice entre 1 et 5 (0 pour fermer ce programme) : "; _N;
		std::cin >> n;
		switch (n)
		{
		case 1:
			//exo 1
			_N; std::cout << "Exo1 : "; _N;
			{
				//1.1
				_N; std::cout << "1.1"; _N;
				{
					//variable
					double dD = 1;
					double dE = 2;
					double dF = 3;
					//calcul
					std::cout << "dD + dE + dF : " << dD + dE + dF; _N;
					std::cout << "dD + dE * dF : " << dD + dE * dF; _N;
					std::cout << "dD + dE / dF : " << dD + dE / dF; _N;
				}



				//1.2
				_N; std::cout << "1.2"; _N;
				{
					//variable
					int nA = 1;
					int nB = 2;
					int	nC = 3;
					//Calculs
					std::cout << "nA + nB + nC : " << nA + nB + nC; _N;
					std::cout << "nA + nB * nC : " << nA + nB * nC; _N;
					std::cout << "nA + nB / nC : " << nA + nB / nC; _N;
				}

				//1.3
				_N; std::cout << "1.3"; _N;
				{
					//variable
					int nA = 1;
					int nB = 2;
					int nC = 3;
					int dD = 4.1;
					int dE = 5.1;
					//Calculs
					std::cout << "nA + nB + dD : " << nA + nB + dD; _N;
					std::cout << "nA + nB * dD : " << nA + nB * dD; _N;
					std::cout << "nA + dD * dE : " << nA + dD * dE; _N;
					std::cout << "dD + nB / nC : " << dD + nB / nC; _N;
				}
			}
			break;

		case 2:
			//exo 2
			_N; std::cout << "Exo2 : "; _N;
			{
				int nA = 0, nB = 0;
				std::cout << "Donne moi deux valeur separer par un espace !"; _N;
				std::cin >> nA >> nB;
				std::cout << "Voici le produit des deux : " << nA * nB; _N;
				nA = -2147483648, nB = 2;
				std::cout << "Voici le produit de -2147483648 et 2 : " << nA * nB; _N;
				nB = 3;
				std::cout << "Voici le produit de -2147483648 et 3 : " << nA * nB; _N;
			}
			break;

		case 3:
			//exo 3
			_N; std::cout << "Exo3 : "; _N;
			{
				long double pi = 3.141592653589793238462643383;
				double dA;
				std::cout << "Donne moi la valeur d'un angle !"; _N;
				std::cin >> dA;
				dA = dA * pi / 180.0;
				std::cout << "Voici son cosinus: " << cos(dA); _N;
				std::cout << "Voici son sinus : " << sin(dA); _N;
				std::cout << "Voici sa tangente : " << tan(dA); _N; _N;
				dA = DegToRad(0);
				std::cout << "Voici le cosinus d'un angle de 0 degrées : " << cos(dA); _N;
				std::cout << "Voici le sinus d'un angle de 0 degrées: " << sin(dA); _N;
				std::cout << "Voici la tangente d'un angle de 0 degrées: " << tan(dA); _N;	_N;
				dA = DegToRad(90);
				std::cout << "Voici le cosinus d'un angle de 90 degrées : " << cos(dA); _N;
				std::cout << "Voici le sinus d'un angle de 90 degrées: " << sin(dA); _N;
				std::cout << "Voici la tangente d'un angle de 90 degrées: " << tan(dA); _N;	_N;
				dA = DegToRad(180);
				std::cout << "Voici le cosinus d'un angle de 180 degrées : " << cos(dA); _N;
				std::cout << "Voici le sinus d'un angle de 180 degrées: " << sin(dA); _N;
				std::cout << "Voici la tangente d'un angle de 180 degrées: " << tan(dA); _N;	_N;
				dA = DegToRad(270);
				std::cout << "Voici le cosinus d'un angle de 270 degrées : " << cos(dA); _N;
				std::cout << "Voici le sinus d'un angle de 270 degrées: " << sin(dA); _N;
				std::cout << "Voici la tangente d'un angle de 270 degrées: " << tan(dA); _N;	_N;
			}
			break;
		case 4:
			//exo 4
			_N; std::cout << "Exo4 : "; _N;
			{
				double a, b, c;
				std::cout << "Etude de la fonction f(x) = a*x² + b*x + c\n"
					<< "Veuillez entrer dans l'ordre les valeurs de a, b et c : ";
				//std::cin >> a >> c >> b;
				std::cin >> a >> b >> c; //le c et le b qui sont inversé !
				std::cout << "f(x) = " << a << "*x² + " << b << "*x + " << c << "\n";
				std::cout << "Sa dérivée est f'(x) = " << 2 * a << "*x + " << b << "\n";
				//double xmin = -b / a * 2;
				double xmin = -b / (a * 2);//manque les parenthèse !
				//std::cout << "Son minimum (ou son maximum si a est négatif) est atteint pour x = " << -b / a * 2
				std::cout << "Son minimum (ou son maximum si a est négatif) est atteint pour x = " << -b / (a * 2)//manque les parenthèse !
					<< " et vaut " << a * xmin * xmin + b * xmin + c << "\n";
				double delta = b * b - 4 * a * c;
				//double x1 = -b - std::sqrt(delta) / (a * 2);
				double x1 = (-b - std::sqrt(delta)) / (a * 2); //manque les parenthèse !
				//double x2 = -b + std::sqrt(delta) / (a * 2);
				double x2 = (-b + std::sqrt(delta)) / (a * 2); //manque les parenthèse !
				std::cout << "Elle vaut 0 pour x = " << x1 << " ou " << x2 << "\n";

			}
			break;
		case 5:
			//exo 5
			_N; std::cout << "Exo5 : "; _N;
			{
				//5.1
				_N; std::cout << "5.1"; _N;
				{
					int indiceDeTronc = 1000;
					double dA = 1.1234;
					std::cout << dA << " : ";
					dA = double(int(dA * indiceDeTronc))/1000.0;
					std::cout << dA; _N;
					double dB = 1.9999;
					std::cout << dB << " : ";
					dB = Tronc(dB, indiceDeTronc);
					std::cout << dB; _N;

				}

				//5.2
				_N; std::cout << "5.2"; _N;
				{
					char c = 'A';
					std::cout << c << " > min : " << char(c - 'A' + 'a'); _N;
					c = 'Z';
					std::cout << c << " > min : " << ToLower(c); _N;
					c = 'd';
					std::cout << c << " > maj : " << ToUpper(c); _N;
				}

				//5.3
				_N; std::cout << "5.3"; _N;
				{
					int a = 0, b = 10;
					std::cout << "a = " << a << " et b = " << b; _N;
					{
						int c = a;
						a = b;
						b = c;
					}
					std::cout << "Maintenant : a = " << a << " et b = " << b; _N; _N;
					a = 5, b = 15;
					std::cout << "a = " << a << " et b = " << b; _N;
					InvertInt(a, b);
					std::cout << "Maintenant : a = " << a << " et b = " << b;
				}
			}
			break;
		default :
			break;
		}
	}
}
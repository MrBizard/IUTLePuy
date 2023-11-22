#include <iostream>
#include <cmath>
#include <Windows.h>
#include <vector>
#include <string>

#define _N std::cout << '\n';

#define BoolReturn(b) (b ? "true" : "false")

#define ICharToInt(c) (c - '0')

bool testBissextile(int n)
{
	bool bis;
	if (n % 4 == 0)
		if (n % 100 == 0)
			if (n % 400 == 0) bis = true; 
			else bis = false; 
		else bis = true; 
	else bis = false; 
	return bis;
}


int main()
{

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int TestBase = 1;
	while (TestBase != -1)
	{
		_N; std::cout << "donne moi le numéro d'éxercice entre 1 et 2 (0 pour fermer ce programme) : "; _N;
		std::cin >> TestBase;
		switch (TestBase)
		{
		case 1:
			//exo 1
			_N; std::cout << "Exo1 : "; _N;
			{
				int TestExo1 = 1;
				while (TestExo1 != -1)
				{
					_N; std::cout << "Donne moi le numéro d'éxercice entre 1 et 6 (0 pour fermer le programme,-1 pour revenir en arrière) : "; _N;
					std::cin >> TestExo1;
					switch (TestExo1)
					{
					case 1:
						//1.1
						std::cout << "1.1"; _N;
						{
							int n;
							std::cout << "Donne moi un nombre : "; _N;
							std::cin >> n;
							if (n >= 100 && n <= 1000)
							{
								std::cout << n << " se trouve entre 100 et 1000 compris !"; _N;
							}
							else
							{
								std::cout << n << " ne se trouve pas entre 100 et 1000 compris !"; _N;
							}
						}
						break;
					case 2:
						//1.2
						std::cout << "1.2"; _N;
						{
							double na, nb, nc, nd;
							std::cout << "Donne moi 4 nombre séparer par des espaces(4 réel) : "; _N;
							std::cin >> na >> nb >> nc >> nd;
							std::cout << "La somme des 4 est : " << na + nb + nc + nd; _N;
							double min = na;
							if (na < nb && na < nc && na < nd)
								min = na;
							else if (nb < nc && nb < nd)
								min = nb;
							else if (nc < nd)
								min = nc;
							else min = nd;
							std::cout << "Le minimum des 4 est : " << min; _N;
							std::cout << "La maximum des 4 est : " << ((na > nb ? na : nb) > (nc > nd ? nc : nd) ? (na > nb ? na : nb) : (nc > nd ? nc : nd)); _N;
							std::cout << "La moyenne des 4 est : " << double(na + nb + nc + nd) / 4.0; _N;
						}
						break;
					case 3:
						//1.3
						std::cout << "1.3"; _N;
						{
							{
								int n;
								std::cout << "Donne moi une année : "; _N;
								std::cin >> n;
								bool bis = false;
								if (n % 4 == 0)
									if (n % 100 == 0)
										if (n % 400 == 0) bis = true;
										else bis = false;
									else bis = true;
								else bis = false;
								if (bis) { std::cout << n << " est bissextile !"; _N; }
								else { std::cout << n << " n'est pas bissextile !"; _N; }
							}
							{
								//test
								std::cout << "voici le caractère bissextile de certaine année : "; _N;
								bool bis = false;
								int n = 1900;
								bis = testBissextile(n);
								std::cout << n << " : " << BoolReturn(bis); _N;
								n = 2000;
								bis = testBissextile(n);
								std::cout << n << " : " << BoolReturn(bis); _N;
								n = 1999;
								bis = testBissextile(n);
								std::cout << n << " : " << BoolReturn(bis); _N;
								n = 2004;
								bis = testBissextile(n);
								std::cout << n << " : " << BoolReturn(bis); _N;
								n = 2023;
								bis = testBissextile(n);
								std::cout << n << " : " << BoolReturn(bis); _N;
							}
						}
						break;
					case 4:
						//1.4
						std::cout << "1.4"; _N;
						{
							int annee = 0, imois = 1, nbJour = 0;
							std::string smois = "";
							_N; std::cout << "donne moi une année puis un mois en chiffre séparer par des espace : "; _N;
							std::cin >> annee >> imois;
							bool bis = testBissextile(annee);
							switch (imois)
							{
							case 2:
								nbJour = 28;
								smois = "février";
							case 1:
								smois = (smois == "" ? "janvier" : "");
							case 3:
								smois = (smois == "" ? "mars" : "");
							case 5:
								smois = (smois == "" ? "mai" : "");
							case 7:
								smois = (smois == "" ? "juillet" : "");
							case 8:
								smois = (smois == "" ? "aout" : "");
							case 10:
								smois = (smois == "" ? "octobre" : "");
							case 12:
								smois = (smois == "" ? "octobre" : "");
								nbJour = (nbJour == 0 ? 31 : nbJour);
							case 4:
								smois = (smois == "" ? "avril" : "");
							case 6:
								smois = (smois == "" ? "juin" : "");
							case 9:
								smois = (smois == "" ? "septembre" : "");
							case 11:
								nbJour = (nbJour == 0 ? 30 : nbJour);
								smois = (smois == "" ? "novembre" : "");
								std::cout << "Le mois de " << smois << " de l'année " << annee << " possède " << (bis && imois == 2 ? 1 : 0) + nbJour << "jour !"; _N;
								break;
							default:
								std::cout << "l'indice du mois est invalide il doit être compris entre 1 et 12"; _N;
								break;
							}
						}
						break;
					case 5:
						//1.5
						std::cout << "1.5"; _N;
						{
							int jour, mois, annee;
							int JourMax = 0;
							std::string date;
							_N; std::cout << "donne moi une date sans espace au format exact JJ/MM/AAAA : "; _N;
							std::cin >> date;
							jour = ICharToInt(date[0]) * 10 + ICharToInt(date[1]);
							mois = ICharToInt(date[3]) * 10 + ICharToInt(date[4]);
							annee = ICharToInt(date[6]) * 1000 + ICharToInt(date[7]) * 100 + ICharToInt(date[8]) * 10 + ICharToInt(date[9]);
							std::cout << date << ':' << jour << '/' << mois << '/' << annee;
							bool bis = testBissextile(annee); _N;
							switch (mois)
							{
							case 2:
								JourMax = 28;
								if (bis) JourMax = 29;
							case 1:
							case 3:
							case 5:
							case 7:
							case 8:
							case 10:
							case 12:
								JourMax = (JourMax == 0 ? 31 : JourMax);
							case 4:
							case 6:
							case 9:
							case 11:
								JourMax = (JourMax == 0 ? 30 : JourMax);
								break;
							default:
								break;
							}
							std::cout << jour << " " << JourMax; _N;
							if (jour == JourMax)
							{
								jour = 1;
								if (mois == 12)
								{
									annee++;
									mois = 1;
								}
								else mois++;
								
							}
							else jour++;
							std::cout << "Le Jour suivant " << date << " est : " << (jour < 10 ? "0" : "") << jour << '/' << (mois < 10 ? "0" : "") << mois << '/' << annee; _N;
						}
						break;
					case 6:
						//1.6
						std::cout << "1.6"; _N;
						{
							double nb;
							_N; std::cout << "Donne moi un double, je vais l'arrondir au centième : "; _N;
							std::cin >> nb;
							std::cout << "voila : " << double(int(nb * 100.0) + ((double(int(nb * 1000.0) % 10) >= 5 ? 1.0 : 0.0))) / 100.0; _N;
						}
						break;
					case 0:
						return 0;
						break;
					default:
						break;
					}

				}
			}
			break;


		case 2:
			//exo 2
			std::cout << "Exo2 : "; _N;
			{
				//2.8
				int TestExo2 = 1;
				while (TestExo2 != 0)
				{
					_N; std::cout << "Donne moi le numéro d'éxercice entre 1 et 8 (0 pour fermer le programme,-1 pour revenir en arrière) : "; _N;
					std::cin >> TestExo2;
					switch (TestExo2)
					{
					case 1:
						//2.1
						std::cout << "2.1"; _N;
						{
							int nb, i = 2;
							_N; std::cout << "Donne moi une valeur : "; _N;
							std::cin >> nb;
							std::cout << i;
							while (i * 2 <= nb)
							{
								i = i * 2;
								std::cout << " / " << i;
							}
							_N;
						}
						break;
					case 2:
						//2.2
						std::cout << "2.2 : "; _N;
						{
							int w,h,nbO = 1;
							char o = 'o', t = '-';
							_N; std::cout << "Donne moi une longueur et une hauteur séparer par un espace(la largeur de taille impair de préférence) : "; _N;
							std::cin >> w >> h;
							for (int y = 0;y < h;y++)
							{
								for (int i = 0; i < (w - nbO) / 2; i++)
								{
									std::cout << t;
								}
								for (int i = 0; i < (nbO <= w ? nbO : w); i++)
								{
									std::cout << o;
								}
								for (int i = 0; i < (w - nbO) / 2; i++)
								{
									std::cout << t;
								}
								std::cout << '\n';
								nbO = nbO + 2;
							}
						}
						break;
					case 3:
						//2.3
						std::cout << "2.3 : "; _N;
						{
							int M,N;
							_N; std::cout << "Donne moi deux valeur : "; _N;
							std::cin >> M >> N;
							int r = M, q = 0;
							while (r - N >= 0)
							{
								r -= N;
								q++;
							}
							std::cout << M << '/' << N << " : " << "\nquotient : " << q << "\nreste : " << r; _N;

						}
						break;
					case 4:
						//2.4
						std::cout << "2.4 : "; _N;
						{
							int n;
							_N; std::cout << "Donne moi une valeur : "; _N;
							std::cin >> n;
							int Fn0 = 0, Fn1 = 1;
							if (n == 0)Fn1 = Fn0;
							for (int i = 2; i <= n; i++)
							{
								int temp = Fn0;
								Fn0 = Fn1;
								Fn1 = Fn0 + temp;
							}
							std::cout << "Fibonacci de " << n << " est " << Fn1; _N;
						}
						break;
					case 5:
						//2.5
						std::cout << "2.5 : "; _N; 
						{
							std::string nb1, nb2 = "";
							_N; std::cout << "Donne moi une valeur : "; _N;
							std::cin >> nb1;
							for (int i = nb1.length() - 1; i >= 0; i--)
							{
								nb2 += nb1[i];
							}
							std::cout << nb2; _N;
						}
						break;
					case 6:
						//2.6
						std::cout << "2.6 : "; _N; 
						{
							int n;
							_N; std::cout << "Donne moi une valeur : "; _N;
							std::cin >> n;
							std::cout << "1 n'est pas premier !";
							for (int i = 2; i < n; i++)
							{
								bool Premier = true;
								for (int y = 2; y < i; y++)
								{
									if (i % y == 0)
									{
										Premier = false;
										break;
									}
								}
								if (Premier)
								{
									std::cout << " / " << i;
								}
							}
							_N;
						}
						break;
					case 7:
						//2.7
						std::cout << "2.7 : "; _N;
						{
							int n;
							_N; std::cout << "Donne moi une valeur : "; _N;
							std::cin >> n;
							std::cout << 0;
							for (int i = 1; i <= n; i++)
							{
								int somme = 0;
								for (int y = 1; y < i/2; y++)
								{
									somme += (i % y == 0 ? y : 0);
								}
								if (somme == i) std::cout << " / " << i;
							}
							_N;
						}
						break;
					case 0:
						return 0;
					default:
						break;
					}
				}
			}
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
	return 0;
}

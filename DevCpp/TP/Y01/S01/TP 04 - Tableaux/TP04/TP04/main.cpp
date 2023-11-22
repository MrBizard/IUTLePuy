
#include <iostream>
#include <map>
#include <array>
#include <vector>

int main()
{
	std::array tab = { 0,0,0,0,0,0,0,0,0,0 };
	int cpt = 0;
	while (cpt < 10)
	{
		int n;
		std::cout << "Donne moi un nombre ("<< cpt <<"): \n";
		std::cin >> n;
		tab[cpt] = n;
		
	}

	return 0;
}
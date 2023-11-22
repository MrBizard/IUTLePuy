// LittleTestFramework2.cpp : définit le point d'entrée de l'application.
//

#include "test.h"
#ifdef _WIN32
#include <Windows.h>
#endif

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

	NOTICE("Programme de test des tests");
	BEGIN_TESTS;
		TEST("Un test qui réussi", true, true);
		TEST("Un test qui échoue", true, false);
#ifdef _MSC_VER
		VERIF_IMP_1(youpi, true);
		TEST_IMP(youpi);
#endif //_MSC_VER
	END_TESTS;

	NOTICE("\n\nProgramme de test des tests : uniquement des tests OK");
	BEGIN_TESTS;
		TEST("Un test qui réussi", true, true);
	END_TESTS;

	NOTICE("\n\nProgramme de test des tests : test des exceptions");
	BEGIN_TESTS;
		TEST_EXCEPTION("Lancement d'une exception", throw 4, int);
	END_TESTS;

	return 0;
}

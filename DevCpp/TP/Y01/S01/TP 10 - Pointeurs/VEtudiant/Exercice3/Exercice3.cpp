#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#include <iostream>
#include "fonctions.h"

int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32


}


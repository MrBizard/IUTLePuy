#include <Windows.h>
#include <iostream>
#include <string>

class CMonException
{
private:
  std::string m_strError;
public:
  CMonException(const std::string& strError) : m_strError(strError) {}
};

void MaFonctionQuiLanceUneException()
{
  std::cout << "J'entre dans ma fonction\n";
  throw CMonException("Je lance mon exception");
  std::cout << "Je ne serai jamais ici !\n";
}

int main()
{
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
  std::cout << "J'appelle ma fonction\n";
  MaFonctionQuiLanceUneException();
  std::cout << "J'arrive à la fin de mon programme\n";
}
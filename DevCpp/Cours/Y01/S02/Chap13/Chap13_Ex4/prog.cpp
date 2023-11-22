#include <Windows.h>
#include <iostream>
#include <string>

class CMonException
{
private:
  std::string m_strError;
public:
  CMonException(const std::string& strError) : m_strError(strError) {}
  const std::string& GetError() const { return m_strError; }
};

void MaFonctionQuiLanceUneException(int nExcept)
{
  std::cout << "J'entre dans ma fonction\n";
  switch (nExcept)
  {
  case 1:
    throw CMonException("Je lance mon exception");
  case 2:
    throw 4;
  default:
    throw "C'est ni 1 ni 2 !";
  }
  std::cout << "Je ne serai jamais ici !\n";
}

int main()
{
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
  try
  {
    int nExcept;
    std::cout << "1 ou 2 ? ";
    std::cin >> nExcept;
    std::cout << "J'appelle ma fonction\n";
    MaFonctionQuiLanceUneException(nExcept);
    std::cout << "J'arrive à la fin de mon programme\n";
  }
  catch (CMonException e)
  {
    std::cout << "J'ai attrapé l'exception \"" << e.GetError() << "\"\n";
  }
  catch (int n)
  {
    std::cout << "J'ai reçu l'entier " << n << '\n';
  }
}
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <memory>
using namespace std;

class CMaMere
{
public:
  CMaMere() { cout << "    La mère a été construite ; "; }
  /*virtual*/ ~CMaMere(){ cout << "    La mère a été détruite ; "; }
          void fonc()        { cout << "    fonc de la mère a été appelée ; "; }
  virtual void foncVirtual() { cout << "    foncVirtual de la mère a été appelée ; "; }
};

class CMaFille : public CMaMere
{
public:
  CMaFille() { cout << "    La fille a été construite ; "; }
  ~CMaFille(){ cout << "    La fille a été détruite ; "; }
          void fonc()        { cout << "    fonc de la fille a été appelée ; "; }
  virtual void foncVirtual() { cout << "    foncVirtual de la fille a été appelée ; "; }
};

void main()
{
#ifdef WIN32
  SetConsoleOutputCP(65001);
#endif
  cout << "  {\n";
  {
    cout << "    CMaFille fille; --> ";
    CMaFille fille;
    cout << "\n"; _getch();

    cout << "    fille.fonc(); --> ";
    fille.fonc();
    cout << "\n"; _getch();

    cout << "    fille.foncVirtual(); --> ";
    fille.foncVirtual();
    cout << "\n"; _getch();

    cout << "  } -->";
  }
  cout << "\n"; _getch();


  cout << "  {\n";
  {

    cout << "    shared_ptr<CMaMere> pMereIntel = make_shared<CMaFille>(); --> ";
    shared_ptr<CMaMere> pMereIntel = make_shared<CMaFille>();
    cout << "\n"; _getch();

    cout << "    pMereIntel->fonc(); --> ";
    pMereIntel->fonc();
    cout << "\n"; _getch();
    cout << "    pMereIntel->foncVirtual(); --> ";
    pMereIntel->foncVirtual();
    cout << "\n"; _getch();

    cout << "  } -->";
  }
  cout << "\n"; _getch();

  cout << "  {\n";
  {

    cout << "    CMaMere* pMere = new CMaFille; --> ";
    CMaMere* pMere = new CMaFille;
    cout << "\n"; _getch();

    cout << "    pMere->fonc(); --> ";
    pMere->fonc();
    cout << "\n"; _getch();
    cout << "    pMere->foncVirtual(); --> ";
    pMere->foncVirtual();
    cout << "\n"; _getch();

    cout << "    delete pMere; --> ";
    delete pMere;
    cout << "\n"; _getch();

    cout << "  } -->";
  }
  cout << "\n"; _getch();

}


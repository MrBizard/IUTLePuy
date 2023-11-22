// Afficher le diagramme des classes DiagrammeClasses.cd
//
#include <Windows.h>

#include "segment.h"
#include "cercle.h"

#include <conio.h>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

//Fonction d'affichage d'un tableau de pointeurs intelligents vers des objets
ostream& operator<<(ostream& out, const vector<shared_ptr<CObjetGraphique>>& vecObjs)
{
  out << "Il y a " << vecObjs.size() << " objet" << (vecObjs.size() > 1 ? "s" : "") << " dans la liste :" << endl;
  out << endl;

  for (size_t i = 0; i < vecObjs.size(); ++i)
  {
    out << "Objet #" << i << " : " << endl;
    vecObjs[i]->Afficher();
    out << endl;
  }
  return out;
}

//Fonction de gestion du menu
char menu()
{
  cout << endl
       << "-= Menu =-" << endl
       << "a : Ajoute un segment" << endl
       << "z : Ajoute un cercle" << endl
       << endl
       << "p : Affiche les objets en mode texte" << endl
       << endl
       << "m : Modifier un objet" << endl
       << "s : Supprimer un objet" << endl
       << endl
       << "q : Quitte le programme" << endl;

  char choix = _getch();
  system("cls");
  return choix;
}

/*******************************************************/
/*   Fonctions de création                             */
/*******************************************************/
shared_ptr<CSegment> CreerSegment()
{
  CPoint p1, p2;
  cout << "Entrez les extrémités (x1 y1 x2 y2) : ";
  cin >> p1 >> p2;
  CCouleur c;
  cout << "Entrez la couleur du segment (r g b) : ";
  cin >> c;
  return make_shared<CSegment>(p1, p2, c);
}

shared_ptr<CCercle> CreerCercle()
{
  CPoint p;
  cout << "Entrez le centre du cercle (x y) : ";
  cin >> p;
  int r;
  cout << "Entrez le rayon du cercle (r) : ";
  cin >> r;
  CCouleur c1, c2;
  cout << "Entrez la couleur du cercle (r g b) : ";
  cin >> c1;
  cout << "Entrez la couleur de remplissage du disque (r g b) : ";
  cin >> c2;
  return make_shared<CCercle>(p, r, c1, c2);
}

/*******************************************************/
/*   Fonctions de modification                         */
/*******************************************************/
void ModifierPosition(CObjetGraphique* pObj)
{
  CPoint pt;
  cout << "Entrez la position (x y) : ";
  cin >> pt;
  pObj->BougeVers(pt);
}

void ModifierCouleur(CObjetGraphique* pObj)
{
  CCouleur c;
  cout << "Entrez la couleur (r g b) : ";
  cin >> c;
  pObj->ChangeCouleur(c);
}

void ModifierRayon(CCercle* pCer)
{
  unsigned int unRayon;
  cout << "Entrez le nouveau rayon : ";
  cin >> unRayon;
  pCer->setRayon(unRayon);
}

void ModifierSegment(shared_ptr<CSegment> pSeg)
{
  cout << "Voulez-vous changer les points du segment ? [o/n] ";
  char choix = _getche();
  cout << endl;
  if (choix == 'o')
  {
    CPoint p1, p2;
    cout << "Entrez les extrémités (x1 y1 x2 y2) : ";
    cin >> p1 >> p2;
    pSeg->BougeVers(p1);
    pSeg->setP2(p2);
  }
  cout << "Voulez-vous changer la couleur du segment ? [o/n] ";
  choix = _getche();
  cout << endl;
  if (choix == 'o')
  {
    ModifierCouleur(pSeg.get());
  }
}

void ModifierCercle(CCercle* pCercle)
{
  cout << "Voulez-vous changer la position du cercle ? [o/n] ";
  char choix = _getche();
  cout << endl;
  if (choix == 'o')
    ModifierPosition(pCercle);
  cout << "Voulez-vous changer la couleur du cercle ? [o/n] ";
  choix = _getche();
  cout << endl;
  if (choix == 'o')
    ModifierCouleur(pCercle);
  cout << "Voulez-vous changer le rayon du cercle ? [o/n] ";
  choix = _getche();
  cout << endl;
  if (choix == 'o')
    ModifierRayon(pCercle);
}


/*******************************************************/
/*   Fonction principale de modification               */
/*******************************************************/
void ModifierObjet(shared_ptr<CObjetGraphique> pObj)
{
  //Cast entre des pointeurs intelligents
  shared_ptr<CSegment> pSeg = dynamic_pointer_cast<CSegment>(pObj);
  if (pSeg)
    ModifierSegment(pSeg);
  
  //Cast entre des pointeurs classiques
  CCercle* pCercle = dynamic_cast<CCercle*>(pObj.get());
  if (pCercle)
    ModifierCercle(pCercle);
}


/*******************************************************/
/*   Fonction principale                               */
/*******************************************************/
int main(void)
{
  SetConsoleOutputCP(65001);

  vector<shared_ptr<CObjetGraphique>> vecObjs;
  char choix;

  while((choix = menu()) != 'q')
  {
    switch(choix)
    {
    case 'a':
      vecObjs.push_back(CreerSegment());
      break;
    case 'z':
      vecObjs.push_back(CreerCercle());
      break;
    case 'p':
      cout << vecObjs;
      break;
    case 'm':
    {
      size_t i;
      cout << "Entrez l'indice de l'objet à modifier : ";
      cin >> i;
      if (i < vecObjs.size())
        ModifierObjet(vecObjs[i]);
    }
    break;
    case's':
    {
      size_t i;
      cout << "Entrez l'indice de l'objet à modifier : ";
      cin >> i;
      if (i < vecObjs.size())
        vecObjs.erase(find(vecObjs.begin(), vecObjs.end(), vecObjs[i]));
    }
    break;
    case 'q':
      break;
    default:
      cerr<<"Choix impossible !"<<endl;
      break;
    }
  }
  return 0;
}

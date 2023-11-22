// Afficher le diagramme des classes DiagrammeClasses.cd
//

#include "segment.h"
#include "spline.h"
#include "cercle.h"
#include "polygone.h"

#include <iostream>
using namespace std;

int main(void)
{
  CSegment seg{ CPoint{ 1, 2 }, CPoint{ 10, 20 }, CCouleur{ 1, 2, 3 } };

  CSpline sp;
  sp << CPoint{ 1, 2 } << CPoint{ 3, 4 } << CPoint{ 5, 6 } << CPoint{ 7, 8 } << CPoint{ 9, 10 };

  CCercle cer{ CPoint{ 1, 2 }, 10 };

  CPolygone poly;
  poly << CPoint{ 10, 11 } << CPoint{ 12, 13 } << CPoint{ 14, 15 } << CPoint{ 16, 17 } << CPoint{ 18, 19 };

  //tableau de pointeurs vers des objets graphiques
  CObjetGraphique* ppObjets[4];
  ppObjets[0] = &seg; //o� seg est un objet de classe CSegment
  ppObjets[1] = &sp;  //o� sp est un objet de classe CSpline
  ppObjets[2] = &cer; //o� cer est un objet de classe CCercle
  ppObjets[3] = &poly;//o� poly est un objet de classe CPolygone

  for (size_t i = 0; i < 4; ++i)
  {
    cout << "Affichage de l'objet #" << i << endl;
    ppObjets[i]->Afficher();
  }

  return 0;
}


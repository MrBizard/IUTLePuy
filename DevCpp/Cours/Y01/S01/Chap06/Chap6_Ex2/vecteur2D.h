#include <string>

struct SVecteur2D
{
  double m_dX;
  double m_dY;

  void Afficher();
  void AffichageDetail(const std::string& strNom);

  double Norme();
  double Orientation();

  SVecteur2D Ajouter(const SVecteur2D& v);
  SVecteur2D Soustraire(const SVecteur2D& v);
  SVecteur2D Multiplier(double dScal);
  SVecteur2D Diviser(double dScal);
  bool PlusGrandQue(const SVecteur2D& v);
};

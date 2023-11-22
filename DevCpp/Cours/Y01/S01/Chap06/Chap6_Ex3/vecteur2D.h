#include <string>

struct SVecteur2D
{
  double m_dX;
  double m_dY;

  void Afficher() const;
  void AffichageDetail(const std::string& strNom) const;

  double Norme() const;
  double Orientation() const;

  SVecteur2D Ajouter(const SVecteur2D& v) const;
  SVecteur2D Soustraire(const SVecteur2D& v) const;
  SVecteur2D Multiplier(double dScal) const;
  SVecteur2D Diviser(double dScal) const;
  bool PlusGrandQue(const SVecteur2D& v) const;
};

#pragma once

#include <string>
#include <iostream>
#if __cpp_impl_three_way_comparison >= 201907L
#include <compare>
#endif

class CVecteur2D
{
  double m_dX;  //Abscisse 
  double m_dY;  //Ordonnée
public:
  //Constructeur
  CVecteur2D(double x = 0, double y = 0);

  //Accesseurs en lecture
  double GetX() const;
  double GetY() const;
  void SetX(double x);
  void SetY(double y);

  //Affichage console
  void Afficher() const;
  void AffichageDetail(const std::string& strNom) const;

  //Informations
  double Norme() const;
  double Orientation() const;

  //Opérateurs unaires
  CVecteur2D operator -() const;
  CVecteur2D operator +() const { return *this; };

  //Opérateurs de comparaison
#if __cpp_impl_three_way_comparison >= 201907L
  bool operator==(const CVecteur2D& v) const = default;
  std::partial_ordering operator<=>(const CVecteur2D& v) const;
#else
  bool operator==(const CVecteur2D& v) const;
  bool operator!=(const CVecteur2D& v) const;
  bool operator>(const CVecteur2D& v) const;
  bool operator<(const CVecteur2D& v) const;
  bool operator>=(const CVecteur2D& v) const;
  bool operator<=(const CVecteur2D& v) const;
#endif

  //Opérateurs arithmétiques avec affectation
  CVecteur2D& operator+=(const CVecteur2D & v);
  CVecteur2D& operator-=(const CVecteur2D & v);
  CVecteur2D& operator*=(double dScal);
  CVecteur2D& operator/=(double dScal);

  //Opérateurs arithmétiques
  CVecteur2D operator+(const CVecteur2D& v) const;
  CVecteur2D operator-(const CVecteur2D& v) const;
  CVecteur2D operator*(double dScal) const;
  CVecteur2D operator/(double dScal) const;
};

//Opérateur de sortie vers flux
std::ostream& operator<<(std::ostream& out, const CVecteur2D& v);

using CPoint2D = CVecteur2D;

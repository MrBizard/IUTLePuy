#pragma once

#include <string>

class CVecteur2D
{
  double m_dX;  //Abscisse 
  double m_dY;  //Ordonn�e
public:
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

  //Op�rations math�matiques
  CVecteur2D Ajouter(const CVecteur2D& v) const;
  CVecteur2D Soustraire(const CVecteur2D& v) const;
  CVecteur2D Multiplier(double dScal) const;
  CVecteur2D Diviser(double dScal) const;
  bool PlusGrandQue(const CVecteur2D& v) const;
};

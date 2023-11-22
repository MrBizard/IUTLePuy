#pragma once
//Solution
#include <memory>
class CPosition
  : public std::enable_shared_from_this<CPosition>
{
public:
  using ptr = std::shared_ptr<CPosition>;
  using const_ptr = std::shared_ptr<const CPosition>;

  virtual ptr clone() const =0;
  ptr operator &() { return shared_from_this(); }
  const_ptr operator &() const { return shared_from_this(); }
  virtual ptr normer() =0;
  virtual double norme() const =0;
  virtual double distance(const_ptr pos2) const =0;
  virtual ptr deplacer(const_ptr dir, double dDist) =0;

  virtual ptr operator-(const CPosition& pos2) const =0;
  virtual ptr operator/(double scalar) const =0;
};
//Fin Solution
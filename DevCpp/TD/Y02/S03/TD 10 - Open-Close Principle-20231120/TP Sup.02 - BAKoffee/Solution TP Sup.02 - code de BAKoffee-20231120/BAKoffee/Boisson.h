#pragma once
#include <string>
//Solution
#include <list>
//Fin Solution

class CBoisson
{
public:
  //Solution
  using description = std::list<std::pair<int, std::string> > ;
  /*
  //Fin Solution
  using description = std::string;
  //Solution
  */
  //Fin Solution
protected:
  description m_description;

public:
  //Solution
  CBoisson(const description::value_type& Description)
  {
    m_description.push_back(Description);
  }
  /*
  //Fin Solution
  CBoisson(const description& Description)
  {
    m_description += Description;
  }
  //Solution
  */
  //Fin Solution

  virtual description getDescription() const {return m_description;}
  virtual double getCout() const =0;

};


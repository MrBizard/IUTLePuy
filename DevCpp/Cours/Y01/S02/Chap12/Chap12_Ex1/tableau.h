#pragma once
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>

template<typename T>
class CTableau2D
{
private:
  std::vector<std::vector<T>> m_tab;

  void setSize(size_t nNbRows, size_t nNbCols);

public:
  //Définition de la taille du tableau 2D à la construction
  CTableau2D(size_t nNbRows = 0, size_t nNbCols = 0);
  
  //Construction avec conversion
  template<typename T2>
  CTableau2D(const CTableau2D<T2>& tab);

  //Opérateur d'affectation explicite (permettant le débugage)
  CTableau2D& operator=(const CTableau2D& tab);

  //Copie d'un tableau d'un autre type
  template<typename T2>
  CTableau2D& Copier(const CTableau2D<T2>& tab);
  //Idem, mais avec l'opérateur d'affectation
  template<typename T2>
  CTableau2D& operator=(const CTableau2D<T2>& tab);

  size_t getNbRows() const { return m_tab.size(); }
  size_t getNbCols() const { if (m_tab.empty()) return 0; return m_tab[0].size(); }

  //Accesseur en lecture seule
  const T& at(size_t row, size_t col) const;
  //Accesseur en lecture / écriture
  T& at(size_t row, size_t col);
};

//Opérateur de sortie vers flux pour un CTableau2D
template<typename T>
std::ostream& operator<<(std::ostream& out, const CTableau2D<T>& tab);


template<typename T>
const T& CTableau2D<T>::at(size_t row, size_t col) const
{
  assert(row < m_tab.size());
  assert(col < m_tab[0].size());
  return m_tab[row][col];
}

template<typename T>
T& CTableau2D<T>::at(size_t row, size_t col)
{
  assert(row < m_tab.size());
  assert(col < m_tab[0].size());
  return m_tab[row][col];
}

template<typename T>
void CTableau2D<T>::setSize(size_t nNbRows, size_t nNbCols)
{
  m_tab.resize(nNbRows);
  if (nNbRows > 0)
    for (auto& row : m_tab)
      row.resize(nNbCols);
}

template<typename T>
CTableau2D<T>::CTableau2D(size_t nNbRows /*= 0*/, size_t nNbCols /*= 0*/)
{
  setSize(nNbRows, nNbCols);
}

template<typename T>
CTableau2D<T>& CTableau2D<T>::operator=(const CTableau2D& tab)
{
  //Cette fonction n'a d'utilité que pour voir quand le compilateur appelle l'opérateur =.
  //Son implémentation par défaut serait suffisante.
  if (&tab == this)
    return *this;
  m_tab = tab.m_tab;
  return *this;
}

template<typename T>
template<typename T2>
CTableau2D<T>::CTableau2D(const CTableau2D<T2>& tab)
{
  Copier(tab);
}

template<typename T>
template<typename T2>
CTableau2D<T>& CTableau2D<T>::Copier(const CTableau2D<T2>& tab)
{
  if (reinterpret_cast<const void*>(this) == reinterpret_cast<const void*>(&tab))
    return *this;

  setSize(tab.getNbRows(), tab.getNbCols());

  const size_t nNbRows = getNbRows();
  const size_t nNbCols = getNbCols();
  for (size_t i = 0; i < nNbRows; ++i)
    for (size_t j = 0; j < nNbCols; ++j)
      this->at(i, j) = static_cast<T>(tab.at(i, j));

  return *this;
}

template<typename T>
template<typename T2>
inline CTableau2D<T>& CTableau2D<T>::operator=(const CTableau2D<T2>& tab)
{
  return Copier(tab);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const CTableau2D<T>& tab)
{
  const size_t nNbRows = tab.getNbRows();
  const size_t nNbCols = tab.getNbCols();
  for (size_t i = 0; i < nNbRows; ++i)
  {
    for (size_t j = 0; j < nNbCols; ++j)
      out <<setw(8)<< tab.at(i, j);
    out << endl;
  }
  return out;
}

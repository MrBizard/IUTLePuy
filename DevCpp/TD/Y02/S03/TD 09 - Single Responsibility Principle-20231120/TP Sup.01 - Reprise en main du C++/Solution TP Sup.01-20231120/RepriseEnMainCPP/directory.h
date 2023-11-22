#pragma once
#include "person.h"
#include <set>
#include <iostream>

class CDirectory
{
  std::set<CPerson> m_directory;
public:
  CDirectory() = default;
  CDirectory(const std::set<CPerson>& dir) : m_directory(dir) {}
  void addPerson(const CPerson& person);
  void addPerson(CPerson&& person);
  bool removePerson(const CPerson& person);
  std::set<CPerson> getPersons(const std::regex& last_name_regex, const std::regex& first_name_regex) const;
  std::set<CPerson> getPersons(const CDate& birthdayMin, const CDate& birthdayMax) const;
  const std::set<CPerson>& everyone() const { return m_directory; }
};

inline std::ostream& operator<<(std::ostream& out, const CDirectory& dir)
{
  size_t nMaxLength = 10;
  for(auto& person : dir.everyone())
  {
    nMaxLength = std::max(nMaxLength, person.lastName().length());
    nMaxLength = std::max(nMaxLength, person.firstName().length());
  }
  ++nMaxLength;

  for (auto& person : dir.everyone())
  {
    out.width(nMaxLength);
    out << std::setfill(' ') << person << "\n";
  }
  return out;
}
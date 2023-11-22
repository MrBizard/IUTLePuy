#pragma once
#include <string_view>
#include <string>
#include "date.h"
#include <iostream>

class CPerson
{
  std::string m_strLastname;
  std::string m_strFirstname;
  CDate m_dateBirth;
public:
  CPerson(std::string_view last_name, std::string_view first_name, const CDate& birthday) 
    : m_strLastname(last_name)
    , m_strFirstname(first_name)
    , m_dateBirth(birthday)
  {}

  bool operator==(const CPerson&) const = default;
  std::strong_ordering operator<=>(const CPerson&) const = default;

  std::string_view lastName() const { return m_strLastname; }
  std::string_view firstName() const { return m_strFirstname; }
  const CDate& birthday() const { return m_dateBirth; }
};

inline std::ostream& operator<<(std::ostream& out, const CPerson& person)
{
  std::streamsize width = out.width();
  return out << std::setw(width)<<person.lastName() << std::setw(width) <<  person.firstName() << std::setw(width) <<  person.birthday();
}

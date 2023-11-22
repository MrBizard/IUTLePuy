#include "directory.h"

void CDirectory::addPerson(const CPerson& person)
{
  m_directory.insert(person);
}

void CDirectory::addPerson(CPerson&& person)
{
  m_directory.insert(person);
}

bool CDirectory::removePerson(const CPerson& person)
{
  auto it = m_directory.find(person);
  if(it == m_directory.end())
    return false;
  m_directory.erase(person);
  return true;
}

std::set<CPerson> CDirectory::getPersons(const std::regex& last_name_regex, const std::regex& first_name_regex) const
{
  std::set<CPerson> subSet;
  
  for (auto& person : m_directory)
  {
    if (std::regex_match(std::string(person.lastName()), last_name_regex) && std::regex_match(std::string(person.firstName()), first_name_regex))
      subSet.insert(person);
  }
  return subSet;
}

std::set<CPerson> CDirectory::getPersons(const CDate& birthdayMin, const CDate& birthdayMax) const
{
  std::set<CPerson> subSet;

  for (auto& person : m_directory)
  {
    if (birthdayMin <= person.birthday() && person.birthday() <= birthdayMax)
      subSet.insert(person);
  }
  return subSet;
}

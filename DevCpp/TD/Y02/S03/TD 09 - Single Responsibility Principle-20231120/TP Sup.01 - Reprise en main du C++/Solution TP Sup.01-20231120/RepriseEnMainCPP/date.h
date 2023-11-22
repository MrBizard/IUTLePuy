#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <compare>

class CDate
{
  int m_nYear = 0;
  unsigned char m_cMonth = 0;
  unsigned char m_cDay = 0;

  void check();
public:
  CDate() = default;
  CDate(unsigned char day, unsigned char month, int year);

  unsigned char day() const { return m_cDay; }
  unsigned char month() const { return m_cMonth; }
  int year() const { return m_nYear; }

  bool operator == (const CDate&) const = default;
  std::strong_ordering operator <=> (const CDate& other) const = default;
};

inline CDate operator ""_date(const char* str, size_t) {
  std::regex dateRegex(R"regex(([0-9]{1,2})[/\-]([0-9]{1,2})[/\-](\-?[0-9]{1,4}))regex");
  std::smatch dateMatch;
  std::string strText(str);
  if (std::regex_search(strText, dateMatch, dateRegex)) {
    unsigned char cDay = (unsigned char)stoi(dateMatch[1]);
    unsigned char cMonth = (unsigned char)stoi(dateMatch[2]);
    int nYear = stoi(dateMatch[3]);
    return { cDay, cMonth, nYear };
  }

  return { 0, 0, 0 };
}

inline std::ostream& operator<<(std::ostream& os, const CDate& date)
{
  return os << (int)date.day() << "/" << std::setw(2) << std::setfill('0') << (int)date.month() << "/" << date.year();
}

inline std::istream& operator>>(std::istream& is, CDate& date)
{
  std::string strText;
  is >> strText;
  try {
    date = operator""_date(strText.c_str(), strText.size());
  }
  catch (std::range_error&)
  {
    is.setstate(std::ios_base::failbit);
  }
  return is;
}

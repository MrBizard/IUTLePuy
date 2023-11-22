#include "date.h"
#include <stdexcept>

void CDate::check()
{
  //Check month
  if (m_cMonth < 1 || m_cMonth > 12)
    throw std::range_error("La date n'est pas valide !");

  //Check day in month
  unsigned char cNbDaysInMonth = 30;
  switch (m_cMonth)
  {
  case 1:  case 3:  case 5:  case 7:  case 8:  case 10:  case 12:
    cNbDaysInMonth = 31;
    break;
  case 2://Fevrier (bissextile ou pas ?)
    //Une année est bissextile si elle multiple de 4 sauf si elle est multiple de 100 et pas de 400
    {
      bool bLeap;
      if (m_nYear % 400 == 0)
        bLeap = true;
      else if (m_nYear % 100 == 0)
        bLeap = false;
      else if (m_nYear % 4 == 0)
        bLeap = true;
      else
        bLeap = false;

      cNbDaysInMonth = bLeap ? 29 : 28;
    }
    break;
  }

  if(m_cDay < 1 || m_cDay > cNbDaysInMonth)
    throw std::range_error("La date n'est pas valide !");
}

CDate::CDate(unsigned char day, unsigned char month, int year)
  : m_cDay{ day }
  , m_cMonth{ month }
  , m_nYear{ year }
{
  check();
}

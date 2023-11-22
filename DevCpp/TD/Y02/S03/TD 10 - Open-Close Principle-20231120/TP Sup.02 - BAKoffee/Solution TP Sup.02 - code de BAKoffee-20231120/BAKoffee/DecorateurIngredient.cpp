#include "DecorateurIngredient.h"

//Solution
CDecorateurIngredient::description CDecorateurIngredient::getDescription() const
{
  if (!m_pBoisson)
    return m_description;
  description desc = m_pBoisson->getDescription();
  desc.insert(desc.end(), m_description.begin(), m_description.end());
  return desc;
}
//Fin Solution
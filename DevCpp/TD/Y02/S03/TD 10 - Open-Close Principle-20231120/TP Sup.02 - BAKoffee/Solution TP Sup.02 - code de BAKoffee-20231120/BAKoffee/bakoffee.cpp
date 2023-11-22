#include "bakoffee.h"
#include "Caramel.h"
#include "Chantilly.h"
#include "Colombia.h"
#include "Deca.h"
#include "Espresso.h"
#include "Sucre.h"
#include "Sumatra.h"
#include "Lait.h"
#include <QtWidgets>
#include <QtCore/QLocale>

BAKoffee::BAKoffee(QWidget *parent)
    : QWidget(parent)
    , m_pBoisson(nullptr)
{
    ui.setupUi(this);
}

BAKoffee::~BAKoffee()
{
}

void BAKoffee::enableGo()
{
  ui.btnGo->setEnabled(true);
}

void BAKoffee::go()
{
  //Crée la boisson de base
  //Solution
  if (ui.btnColombia->isChecked())
    m_pBoisson = std::make_shared<CColombia>();
  if (ui.btnDeca->isChecked())
    m_pBoisson = std::make_shared<CDeca>();
  if (ui.btnEspresso->isChecked())
    m_pBoisson = std::make_shared<CEspresso>();
  if (ui.btnSumatra->isChecked())
    m_pBoisson = std::make_shared<CSumatra>();
  //Fin Solution

  //Ajoute du sucre
  //Solution
  for(int i=0; i<ui.spinSucre->value(); ++i)
    m_pBoisson = std::make_shared<CSucre>(m_pBoisson);
  //Fin Solution
  //Ajoute du lait
  //Solution
  for(int i=0; i<ui.spinLait->value(); ++i)
    m_pBoisson = std::make_shared<CLait>(m_pBoisson);
  //Fin Solution
  //Ajoute du caramel
  //Solution
  for(int i=0; i<ui.spinCaramel->value(); ++i)
    m_pBoisson = std::make_shared<CCaramel>(m_pBoisson);
  //Fin Solution
  //Ajoute de la chantilly
  //Solution
  for(int i=0; i<ui.spinChantilly->value(); ++i)
    m_pBoisson = std::make_shared<CChantilly>(m_pBoisson);
  //Fin Solution

  if (m_pBoisson)
  {
    QMessageBox::StandardButton ans = QMessageBox::information(this, "Coût", QString("Merci d'insérer ").append(QLocale().toCurrencyString(m_pBoisson->getCout())), QMessageBox::Ok | QMessageBox::Cancel);
    if (ans == QMessageBox::Ok)
      emit prepare(m_pBoisson);
  }
  else
  {
    QMessageBox::warning(this, "Erreur !", "Vous n'avez pas sélectionné de boisson !", QMessageBox::Ok | QMessageBox::Cancel);
  }
}
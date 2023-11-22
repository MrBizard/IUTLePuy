#pragma once
#include <list>
#include <QObject>
#include <memory>
#include "Decor.h"
#include "monstre.h"
#include "Joueur.h"

class CMonde
  : public QObject
{
  Q_OBJECT
public:
  using MonsterSet = std::list<CMonstre::ptr>;
  using PlayerSet = std::list<CJoueur::ptr>;

private:
  MonsterSet m_lstMonsters;
  PlayerSet m_lstJoueur;
  CDecor::const_ptr m_decor;

public:
  CMonde(CDecor::const_ptr decor, QObject* pParent = nullptr);
  ~CMonde();

  void addMonstre(CMonstre::ptr pMonstre) {m_lstMonsters.push_back(pMonstre);}
  void addJoueur(CJoueur::ptr pJoueur) {m_lstJoueur.push_back(pJoueur);}

  void interactions();
  void afficher();

  CDecor::const_ptr getDecor() const { return m_decor; }

signals:
  void JoueurGagne(const std::shared_ptr<CJoueur>&);
  void JoueurMort(const std::shared_ptr<CJoueur>&);
  void MonstreMort(const std::shared_ptr<CMonstre>&);
};


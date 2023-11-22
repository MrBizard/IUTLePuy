#include "Monde.h"

CMonde::CMonde(CDecor::const_ptr decor, QObject* pParent)
  : QObject(pParent)
  , m_decor(decor)
{
}

CMonde::~CMonde()
{
}

void CMonde::interactions()
{
  PlayerSet::iterator itJoueur=m_lstJoueur.begin();
  while(itJoueur!=m_lstJoueur.end())
  {
    bool bJoueurGagne = false;
    //Solution
    if(m_decor->getObjectif()->distance((*itJoueur)->getPos()) < 1)
    /*
    //Fin Solution
    if(false)
    //Solution
    */
    //Fin Solution
    {
      emit JoueurGagne(*itJoueur);
      bJoueurGagne = true;
      itJoueur = m_lstJoueur.erase(itJoueur);
    }
    if(!bJoueurGagne)
      itJoueur++;
  }

  MonsterSet::iterator itMonstre=m_lstMonsters.begin();
  while( itMonstre!=m_lstMonsters.end())
  {
    bool bMonstreTue = false;
    PlayerSet::iterator itJoueur=m_lstJoueur.begin();
    while(itJoueur!=m_lstJoueur.end() )
    {
      bool bJoueurTue = false;
      //Solution
      if ((*itMonstre)->getPos()->distance((*itJoueur)->getPos()) < 5)
        /*
        //Fin Solution
        if(false)
        //Solution
        */
        //Fin Solution
      {
        (*itMonstre)->attaquer(*itJoueur);
        emit MonstreMort(*itMonstre);
        bMonstreTue = true;
        itMonstre = m_lstMonsters.erase(itMonstre);
        if((*itJoueur)->getVie() <= 0)
        {
          emit JoueurMort(*itJoueur);
          bJoueurTue = true;
          itJoueur = m_lstJoueur.erase(itJoueur);
        }
      }
      if(!bJoueurTue)
        itJoueur++;
    }
    if(!bMonstreTue)
      itMonstre++;
  }

}

void CMonde::afficher()
{
  m_decor->afficher();
  for(PlayerSet::iterator it=m_lstJoueur.begin(); it!=m_lstJoueur.end(); it++)
    (*it)->afficher();
  for(MonsterSet::iterator it=m_lstMonsters.begin(); it!=m_lstMonsters.end(); it++)
    (*it)->afficher();
}


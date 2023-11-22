#include "PetriDish.h"

/*!
 * La boîte de Petri a une taille carrée définie par le paramètre.
 * 
 * \param size Taille de la boîte de Petri à créer
 * 
 * \todo Modifiez le constructeur pour initialier la collection à la bonne taille
 */
CPetriDish::CPetriDish(size_t size)
{
}

/*!
 * Force la cellule à la position (i,j) à être vivante et à l'état Adult.
 * 
 * \param i Indice de ligne
 * \param j Indice de colonne
 * 
 * \todo Complétez cette fonction afin de définir une cellule vivante à la position (i,j). Elle doit 
 * être définie "adulte".
 */
void CPetriDish::ForceAlive(size_t i, size_t j)
{
}

/*!
 * Tue la cellule à la position (i,j). La cellule ne passe pas par l'état Dying, elle est directement tuée.
 *
 * \param i Indice de ligne
 * \param j Indice de colonne
 * 
 * \todo Modifiez cette fonction afin de définir une cellule morte à la position (i,j). Elle ne doit pas 
 * être considérée mourante, mais bel et bien "morte"
 */
void CPetriDish::ForceDead(size_t i, size_t j)
{
}

/*!
 * Vérifie si la cellule à la position (i,j) est vivante (état Nascent, Adult ou Dying).
 *
 * \param i Indice de ligne
 * \param j Indice de colonne
 * 
 * \todo Modifiez cette fonction pour retourner \c true si la cellule à la position (i,j) est vivante
 */
bool CPetriDish::IsAlive(size_t i, size_t j)
{
  return false;
}

/*!
 * Après avoir définitivement tué l'ensemble des cellules mourante (=à l'état Dying), cette fonction
 * met à jour l'état de le boîte de Petri en appliquant les règles du jeu de la vie.
 * 
 * \todo Complétez cette fonction pour que les règles du jeu de la vie soient respectées. Les règles 
 * sont détaillées ci-dessous :
 * > l'état d’une cellule est entièrement déterminé par l’état de ses huit cellules voisines, selon les règles suivantes :
 * > - une cellule morte possédant exactement trois cellules voisines vivantes devient vivante (elle naît) ;
 * > - une cellule vivante possédant deux ou trois cellules voisines vivantes le reste, sinon elle meurt.
 * Vous devez également penser à passer au stade adulte toutes les cellules qui étaient au stade naissante
 * avant l'appel de cette fonction, dans le cas où elle n'ont pas été tuées.
 */
void CPetriDish::Update()
{
  CleanMe();
  auto snapshot = CreateSnapshot();
}

/*!
 * Nettoie la boîte de Petri en supprimant toutes les cellules mourantes.
 * 
 * \todo Complétez cette fonction pour supprimer définitivement toutes les cellules mourantes.
 */
void CPetriDish::CleanMe()
{
}

/*!
 * Cette fonction compte le nombre de cellules voisines vivantes à une cellule particulière au sein 
 * d'une capture mémoire de la boîte de Petri.
 * 
 * \param snapshot La capture mémoire à utiliser pour compter le nombre des voisines
 * \param i Indice de ligne de la cellule considérée
 * \param j Indice de colonne de la cellule considérée
 * \return Le nombre de cellules voisines vivantes.
 * 
 * \todo Complétez cette fonction pour retourner le nombre de cellules vivantes voisines de la cellule
 * à la position (i,j) dans la collection \c snapshot.
 */
unsigned int CPetriDish::NbAliveNeighboors(const petri_collection& snapshot, size_t i, size_t j) const
{
  unsigned int ret = 0;
  return ret;
}

/*!
 * Il est nécessaire de créer une copie mémoire de la boîte de Petri car l'état futur des cellules 
 * dépend de l'état actuel de ses 8 voisines. Sans copie mémoire, les états futurs et actuels se mélangeraient
 * et engendreraient des erreurs algorithmiques.
 * 
 * \return Une copie complète de l'état de la collection interne de cellules. Cela signifie que les cellules
 * sont également copiées.
 * 
 * \todo Complétez cette fonction pour réaliser la copie profonde.
 */
CPetriDish::petri_collection CPetriDish::CreateSnapshot() const
{
  petri_collection snapshot(m_cells);
  return snapshot;
}

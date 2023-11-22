/*!
 * \file "TP.cpp"
 * 
 * \version 2016
 *
 * \brief Définition de la classe CTP
 */
#include "StdAfx.h"
#define _USE_MATH_DEFINES
#include "TP.h"
#include "incLibGraph2.h"


/*!
 * \brief Affiche les objets.
 * 
 * \todo Afficher tous les rectangles et toutes les ellipses
 */
void CTP::Afficher() const
{
}

/*!
 * \brief Définit les attributs graphiques des prochains objets créés.
 *
 * La fonction affiche une boîte de dialogue pour sélectionner graphiquement 
 * les attributs des formes. Les attibuts sont la couleur du trait, son 
 * épaisseur ainsi que son style d'affichage.
 */
void CTP::GuiSetDefaultStyle()
{
  LibGraph2::GetLibGraph2()->guiGetPenStyle(m_argbCurColor, m_fCurThickness, m_eCurStyle);
}

/*!
 * \brief
 * Ajoute un nouveau rectangle.
 * 
 * \param ptP1
 * Point d'origine du nouveau rectangle.
 * 
 * \remark 
 * Le rectangle est créé sans définir son point d'arrivé car la fonction 
 * ModifierDernierRectangle va être appelée juste après.
 *
 * \todo Ajouter un nouveau rectangle ayant les caratéristiques suivantes : \n
 * - Le point d'origine en \c ptP1 \n
 * - Les attributs de tracés courant \n
 * - Le point d'arrivée n'est pas encore défini
 */
void CTP::AjouterRectangle(const LibGraph2::CPoint& ptP1)
{
}

/*!
 * \brief
 * Définit le point d'arrivé du dernier rectangle créé.
 * 
 * \param ptP2
 * Point d'arrivé du dernier rectangle créé.
 * 
 * \todo Modifier le dernier rectangle créé pour lui affecter son point d'arrivée à \c ptP2
 */
void CTP::ModifierDernierRectangle(const LibGraph2::CPoint& ptP2)
{
}

/*!
 * \brief
 * Ajoute une nouvelle ellipse.
 * 
 * \param ptP1
 * Point d'origine de la nouvelle ellipse.
 * 
 * \remark 
 * L'ellipse est créée sans définir son point d'arrivé car la fonction 
 * ModifierDerniereEllipse va être appelée juste après.
 *
 * \todo Ajouter une nouvelle ellipse ayant les caratéristiques suivantes : \n
 * - Le point d'origine en \c ptP1 \n
 * - Les attributs de tracés courant \n
 * - Le point d'arrivée n'est pas encore défini
 */
void CTP::AjouterEllipse(const LibGraph2::CPoint& ptP1)
{
}

/*!
 * \brief
 * Définit le point d'arrivé de la dernière ellipse créée.
 * 
 * \param ptP2
 * Point d'arrivé de la dernière ellipse créée.
 * 
 * \todo Modifier la dernière ellipse créée pour lui affecter son point d'arrivée à \c ptP2
 */
void CTP::ModifierDerniereEllipse(const LibGraph2::CPoint& ptP2)
{
}

/*!
 * \brief
 * Ajoute un nouvel arc.
 * 
 * \param ptP1
 * Point d'origine du nouvel arc.
 * 
 * \remark 
 * L'arc est créé sans définir son point d'arrivé car la fonction 
 * ModifierDernierArc va être appelée juste après.
 *
 * \todo Ajouter un nouvel arc ayant les caratéristiques suivantes : \n
 * - Le point d'origine en \c ptP1 \n
 * - Les attributs de tracés courant \n
 * - Le point d'arrivée n'est pas encore défini
 * - Les angles de départ et de balayage peuvent être laissés aux valeurs par défaut
 */
void CTP::AjouterArc(const LibGraph2::CPoint& ptP1)
{
}

/*!
 * \brief
 * Définit le point d'arrivé du dernier arc créé.
 * 
 * \param ptP2
 * Point d'arrivé du dernier arc créé.
 * 
 * \todo Modifier le dernier arc créé pour lui affecter son point d'arrivée à \c ptP2
 */
void CTP::ModifierDernierArc(const LibGraph2::CPoint& ptP2)
{
}

/*!
 * \brief
 * Définit l'angle de départ de l'arc.
 *
 * L'angle de départ de l'arc est calculé à partir du point \c pt passé en 
 * paramètre. L'angle calculé est l'angle que réalise le vecteur qui part du 
 * centre de l'ellipse vers le point \c pt avec l'horizontale. Pour calculer 
 * cet angle, il suffit d'appliquer l'équation suivante :
 * \f[
 * a = \text{ atan2 } \left( \vec{ v }_y, \vec{ v }_x \right) * \frac{ 180 }{ \pi }
 * \f]
 * où \f$ \vec{v} \f$ est le vecteur du centre de l'ellipse vers le point \c pt.
 * 
 * \param pt
 * Point de destination du vecteur définissant l'angle de départ de l'arc.
 * 
 * \todo Modifier le dernier arc créé pour lui affecter son angle de départ en 
 * suivant les indications précédentes.
 * 
 */
void CTP::ModifierDernierArcStartAngle(const LibGraph2::CPoint& pt)
{
}

/*!
 * \brief
 * Définit l'angle de balayage de l'arc.
 *
 * L'angle de balayage de l'arc est calculé à partir du point \c pt passé en
 * paramètre. L'angle calculé est l'angle que réalise le vecteur qui part du 
 * centre de l'ellipse vers le point \c pt avec l'horizontale auquel on 
 * retranche l'angle de départ. Pour calculer cet angle, il suffit d'appliquer
 * les équations suivantes :
 *
 * \f[
 * a_{temp} = \text{ atan2 } \left( \vec{ v }_y, \vec{ v }_x \right) * \frac{ 180 }{ \pi } - a_{start}
 * \f]
 * \f[
 * a=\begin{cases}
 *     a_{temp}, & \text{ si }a_{temp}>=0 \text{ , } \\
 *     a_{temp} + 360, & \text{ sinon} 
 *   \end{cases}
 * \f]
 *
 * où \f$ \vec{v} \f$ est le vecteur du centre de l'ellipse vers le point \c pt 
 * et \f$ a_{start} \f$ est l'angle de départ de l'arc.
 * 
 * \param pt
 * Point de destination du vecteur définissant l'angle de balayage de l'arc.
 * 
 * \todo Modifier le dernier arc créé pour lui affecter son angle de balayage en 
 * suivant les indications précédentes.
 * 
 */
void CTP::ModifierDernierArcSweepAngle(const LibGraph2::CPoint& pt)
{
}


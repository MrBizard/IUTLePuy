#include <Windows.h>
#include "inc_libgraph2.h"
#include "vecteur2D.h"
#include "carre.h"
#include <iostream>

void showHelp()
{
  LibGraph2::guiMessageBox("Chap1_Ex3", "Touches utilis�es\n"
                           "I : Affiche les informations sur le carr�\n"
                           "D : D�forme le carr�\n"
                           "F1 : Affiche cette aide",
                           LibGraph2::msgbtn_types::MsgBtnOK,
                           LibGraph2::msgicon_types::MsgIcnInformation);
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  LibGraph2::evt_type tEvt;  //Type de l'�v�nement re�u
  int nVkCode;    //Code de la touche si �v�nement clavier
  int nMouseX;    //Position x de la souris si �v�nement souris
  int nMouseY;    //Position y de la souris si �v�nement souris
  //Affiche la fen�tre graphique avec une taille par d�faut
  LibGraph2::show(100, 100);

  /***************************************/
  /*       Initialisation du carr�       */
  /***************************************/
  SCarre carre;
  SPoint2D dep;
  dep.m_dX = 30;
  dep.m_dY = 30;
  SVecteur2D dir;
  dir.m_dX = 40;
  dir.m_dY = -10;
  carre.Creer(dep, dir);

  showHelp();
  //Boucle principale d'�v�nements
  while (waitForEvent(tEvt, nVkCode, nMouseX, nMouseY))
  {
    switch (tEvt)  //En fonction du type du dernier �v�nement
    {
    case LibGraph2::evt_type::evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
      //Utiliser �ventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
      LibGraph2::beginPaint();
      /***************************************/
      /*          Affichage du carr�         */
      /***************************************/
      carre.Afficher();
      LibGraph2::endPaint();
      break;
    case LibGraph2::evt_type::evtKeyDown:  //Enfoncement d'une touche
      switch (nVkCode) //En fonction de la touche enfonc�e
      {
      case 'I':
        /***************************************/
        /* Affichage des informations du carr� */
        /***************************************/
        std::cout << "Le carr� est : ";
        for (int i = 0; i < 3; ++i)
        {
          carre.m_points[i].Afficher();
          std::cout << ", ";
        }
        carre.m_points[3].Afficher();
        std::cout << '\n';
        std::cout << "P�rim�tre = " << carre.Perimetre() << '\n';
        break;

      case 'D':
        /***************************************/
        /*        D�formation du carr� !       */
        /***************************************/
        carre.m_points[3].m_dX = 0;
        LibGraph2::askForRefresh();
        break;

      case VK_F1:
        showHelp();
        break;
      }
      break;
    }
  }
  //Lib�ration de la m�moire li�e � LibGraph 2
  LibGraph2::ReleaseLibGraph2();
  return 0;
}

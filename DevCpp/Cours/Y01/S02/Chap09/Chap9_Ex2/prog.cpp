#include <Windows.h>
#include <tchar.h>
#include <cmath>
#include <memory>
#include "Universite.h"
#include "EnsCherch.h"
#include "incLibGraph2.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR lpCmdLine,
                       int nCmdShow)
{
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
  //Récupération de l'objet principal de LibGraph 2
  LibGraph2::ILibGraph2* libgraph = LibGraph2::GetLibGraph2();
  //Affiche la fenêtre graphique avec une taille par défaut
  const int nWndWidth = 1280;
  const int nWndHeight = 720;
  libgraph->show(LibGraph2::CSize((float)nWndWidth, (float)nWndHeight), false);
  LibGraph2::evt e;                              //Evénement LibGraph 2
  CLaboratoire* pSelectedLab = nullptr; //Laboratoire pointée par la souris
  CComposante* pSelectedComp = nullptr; //Composante pointée par la souris
  bool bMouseDown = false;            //Flag de clic de souris
  LibGraph2::CPoint curPos;                      //Position courante de la souris (maj dans les évt souris)
  DWORD dwStartTime = timeGetTime();  //Temps de départ du programme (pour affichage du bandeau d'aide durant 5s)

  //#######################################
  //# Création des enseignants-chercheurs #
  //#######################################
  const int nNbEnsCherch = 13;
  const int nNbCol = 5;
  const int nNbLig = (int)ceil((nNbEnsCherch * 2.0 - 1) / nNbCol);
  std::shared_ptr<CEnsCherch> pEnsCherchs[nNbEnsCherch];

  for (int i = 0; i < nNbEnsCherch; ++i)
  {
    int lig = (i * 2) / nNbCol;
    int col = (i * 2) % nNbCol;
    LibGraph2::CPoint pos(col * nWndWidth / 3.0f / nNbCol + nWndWidth / 3.0f, (float)lig * (nWndHeight - 100) / (nNbLig - 1) + 50);
    pEnsCherchs[i] = std::make_shared<CEnsCherch>(pos);
  }

  //###############################################
  //# Pointeur vers une université non instanciée #
  //###############################################
  std::shared_ptr<CUniversite> pUniv;


  //Boucle principale d'événements
  while (libgraph->waitForEvent(e))
  {
    switch (e.type) //En fonction du type d'événement
    {
    case LibGraph2::evt_type::evtRefresh: //Raffraichissement de l'affichage (tout redessiner)
      libgraph->beginPaint();
      {
        //Affiche l'université si elle existe
        if (pUniv)
          pUniv->Draw();

        //Affiche le trait de connexion en cours entre la composante ou le laboratoire et la 
        //position courante de la souris
        libgraph->setPen(LibGraph2::MakeARGB(255, 255, 0, 0), 3, LibGraph2::pen_DashStyles::Dash);
        if (pSelectedComp != nullptr)
          libgraph->drawLine(pSelectedComp->GetCenter(), curPos);
        if (pSelectedLab != nullptr)
          libgraph->drawLine(pSelectedLab->GetCenter(), curPos);

        //Dessine les enseignants-chercheurs
        for (int i = 0; i < nNbEnsCherch; ++i)
          pEnsCherchs[i]->Draw();

        //Affiche le bandeau d'aide les 5 premières secondes ou si la souris est proche de la 
        //limite supérieure de la fenêtre
        DWORD dwEllapsedTime = timeGetTime() - dwStartTime;
        if (curPos.m_fY < 50 || dwEllapsedTime <= 5000)
        {
          float fY = 0.0f;
          if (dwEllapsedTime <= 4000)
          {
            fY = 0.0f;
            //libgraph->askForRefresh();
          }
          //else if (dwEllapsedTime<=5000)
          //{
          //  fY = __min((dwEllapsedTime-4000)/1000.0f * 50.0f, curPos.m_fY);
          //  libgraph->askForRefresh();
          //}
          else
            fY = curPos.m_fY;
          libgraph->setPen(0, 0);
          libgraph->setSolidBrush(LibGraph2::MakeARGB(127, 127, 127, 127));
          libgraph->drawRectangle(LibGraph2::CRectangle(LibGraph2::CPoint(0.0f, -fY), LibGraph2::CSize((float)nWndWidth, 50.0f)));
          libgraph->setFont("Calibri", 16, LibGraph2::FontStyleRegular);
          libgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
          LibGraph2::CRectangle rect;
          libgraph->getStringDimension("Appuyez sur 'U' pour créer l'université et sur 'S' pour supprimer l'université", LibGraph2::CPoint(), rect);
          libgraph->drawString("Appuyez sur 'U' pour créer l'université et sur 'S' pour supprimer l'université", LibGraph2::CPoint((nWndWidth - rect.m_szSize.m_fWidth) / 2, (50 - rect.m_szSize.m_fHeight) / 2 - fY));
        }
      }
      libgraph->endPaint();
      break;
    case LibGraph2::evt_type::evtKeyDown: //Enfoncement d'une touche
      switch (e.vkKeyCode) //En fonction de la touche enfoncée
      {
      case 'U': //Crée l'université si non déjà créée
        if (!pUniv)
        {
          pUniv = std::make_shared<CUniversite>();
          libgraph->askForRefresh();
        }
        break;
      case 'S': //Supprime l'université
        pUniv = nullptr;
        pSelectedComp = nullptr;
        pSelectedLab = nullptr;
        libgraph->askForRefresh();
        break;
      }
      break;
    case LibGraph2::evt_type::evtMouseDown:
      curPos = LibGraph2::CPoint((float)e.x, (float)e.y);
      bMouseDown = true;
      if (pUniv)
      {
        pSelectedComp = pUniv->GetSelectedComp(curPos);
        pSelectedLab = pUniv->GetSelectedLab(curPos);
      }
      break;

    case LibGraph2::evt_type::evtMouseUp:
      curPos = LibGraph2::CPoint((float)e.x, (float)e.y);
      bMouseDown = false;
      for (int i = 0; i < nNbEnsCherch; ++i)
        pEnsCherchs[i]->ShowBoundingBox(false);
      if (pSelectedComp != nullptr)
        for (int i = 0; i < nNbEnsCherch; ++i)
          if (pEnsCherchs[i]->IsInside(curPos))
            pSelectedComp->Associer(pEnsCherchs[i]);
      if (pSelectedLab != nullptr)
        for (int i = 0; i < nNbEnsCherch; ++i)
          if (pEnsCherchs[i]->IsInside(curPos))
            pSelectedLab->Associer(pEnsCherchs[i]);
      pSelectedComp = nullptr;
      pSelectedLab = nullptr;
      libgraph->askForRefresh();
      break;

    case LibGraph2::evt_type::evtMouseMove: //Déplacement de la souris
      curPos = LibGraph2::CPoint((float)e.x, (float)e.y);
      if (bMouseDown)
      {
        for (int i = 0; i < nNbEnsCherch; ++i)
          pEnsCherchs[i]->ShowBoundingBox(pEnsCherchs[i]->IsInside(curPos));
      }
      libgraph->askForRefresh();
      break;
    }
  }
  //Libération de l'objet principal de LibGraph 2
  LibGraph2::ReleaseLibGraph2();
  return 0;
}

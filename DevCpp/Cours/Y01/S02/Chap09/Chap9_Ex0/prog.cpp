#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <Windows.h>
#include <tchar.h>
#include <memory>
#include "Doc.h"
#include "incLibGraph2.h"

std::shared_ptr<CDoc> OpenDoc();

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
  libgraph->show(LibGraph2::CSize((float)nWndWidth,(float)nWndHeight), false);
  LibGraph2::evt e;                              //Evénement LibGraph 2

  //#######################################
  //# Pointeur d'accès au document        #
  //#######################################
  std::shared_ptr<CDoc> pDoc;
  

  //Boucle principale d'événements
  while(libgraph->waitForEvent(e))
  {
    switch (e.type) //En fonction du type d'événement
    {
    case LibGraph2::evt_type::evtRefresh: //Raffraichissement de l'affichage (tout redessiner)
      libgraph->beginPaint();
      {
        //Affiche le document s'il existe
        if (pDoc)
          pDoc->DrawIt();
        else
        {
          libgraph->setSolidBrush(LibGraph2::MakeARGB(255, 100, 100, 100));
          libgraph->drawRectangle(LibGraph2::CRectangle{ LibGraph2::CPoint{ 0.0f, 0.0f }, LibGraph2::CSize{ (float)nWndWidth, (float)nWndHeight } });
          libgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
          libgraph->setFont("Tahoma", 14, LibGraph2::font_styles::FontStyleRegular);
          std::string text = "Appuyez sur la touche 'O' pour ouvrir un fichier.\nAppuyez sur la touche 'F' pour fermer le fichier ouvert.";
          LibGraph2::CPoint pos{ 0.0f, 0.0f };
          LibGraph2::CRectangle rect;
          libgraph->getStringDimension(text, pos, rect);
          pos.m_fX = ((float)nWndWidth - rect.m_szSize.m_fWidth) / 2.0f;
          pos.m_fY = ((float)nWndHeight - rect.m_szSize.m_fHeight) / 2.0f;
          libgraph->drawString(text, pos);
        }
      }
      libgraph->endPaint();
      break;
    case LibGraph2::evt_type::evtKeyDown: //Enfoncement d'une touche
      switch (e.vkKeyCode) //En fonction de la touche enfoncée
      {
      case 'O': //Crée le document
      {
        std::shared_ptr<CDoc> ptr = OpenDoc();
        if (ptr)
          pDoc = ptr;
        libgraph->askForRefresh();
      }
        break;
      case 'F': //Supprime le document
        pDoc = nullptr;
        libgraph->askForRefresh();
        break;
      }
      break;
    }
  }
  //Libération de l'objet principal de LibGraph 2
  LibGraph2::ReleaseLibGraph2();
  return 0;
}

//Retourne un pointeur vers un nouveau document ouvert, ou nullptr si l'ouverture n'a pas fonctionnée.
std::shared_ptr<CDoc> OpenDoc()
{
  LibGraph2::ILibGraph2* libgraph = LibGraph2::GetLibGraph2();

  LibGraph2::CString lgstrFileName;
  if (libgraph->guiGetFileName(lgstrFileName, true, std::vector<LibGraph2::CString>{"Fichiers de cette application (chap9ex0)|*.chap9ex0", "Tous les fichiers|*.*"}))
  {
    std::wstring wstrFileName = lgstrFileName;
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;
    std::string strFileName= converter.to_bytes(wstrFileName);
    return std::make_shared<CDoc>(strFileName);
  }
  return nullptr;
}
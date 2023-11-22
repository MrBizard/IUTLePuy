#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#include <iostream>
#include <chrono>
#include "fonctions.h"

using namespace std::chrono_literals;

int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

  char texte[] = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, At accusam aliquyam diam diam dolore dolores duo eirmod eos erat, et nonumy sed tempor et et invidunt justo labore Stet clita ea et gubergren, kasd magna no rebum. sanctus sea sed takimata ut vero voluptua. est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat. Consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo";
  std::string strTexte = texte;

  //Créez votre programme de test ici

  /*************************************************************
   *                                                           *
   *                INITIALISATION DU BENCHMARK                *
   *                                                           *
   *************************************************************/
  /*
  std::cout << "Initialisation du benchmark...\n";
  auto benchMarkDuration = 6s;

  //Cette première boucle commence à "faire chauffer" le processeur
  //-> Le système se met en mode d'exécution rapide (augmentation de la fréquence processeur notament)
  size_t nNbIters = 0;

  auto startTime = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds duration;
  nNbIters = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nNbIters != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    ++nNbIters;
  }
  //Cette seconde boucle permet de mesurer l'impact d'une boucle vide.
  nNbIters = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nNbIters != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    ++nNbIters;
  }
  double dIterationControlTime = static_cast<double>(duration.count()) / nNbIters;
  std::cout << "Le contrôle des itérations prend " << dIterationControlTime << " ns.\n\n";
  */


  /*************************************************************
   *                                                           *
   *        BENCHMARK DE stringSplitter sur const char*        *
   *                                                           *
   *************************************************************/
   /*
  std::cout << "Benchmark de l'appel à stringSplitter sur const char*...\n";
  size_t nbCallsV1 = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsV1 != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction stringSplitter en passant en paramètre la chaine de caractère texte
    ++nbCallsV1;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsV1 << " fois la fonction stringSplitter.\n";
  double dCallV1Time = std::max(static_cast<double>(duration.count()) / nbCallsV1 - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dCallV1Time << "ns.\n\n";
  */


  /*************************************************************
   *                                                           *
   *        BENCHMARK DE stringSplitter sur std::string        *
   *                                                           *
   *************************************************************/
   /*
  std::cout << "Benchmark de l'appel à stringSplitter sur std::string...\n";
  size_t nbCallsV2 = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsV2 != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction stringSplitter en passant en paramètre la chaine de caractère strTexte
    ++nbCallsV2;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsV2 << " fois la fonction stringSplitter.\n";
  double dCallV2Time = std::max(static_cast<double>(duration.count()) / nbCallsV2 - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dCallV2Time << "ns.\n\n";

  std::cout << "L'appel avec passage par pointeur est donc " << dCallV2Time / dCallV1Time << " fois plus rapide.\n\n\n";
  */

}


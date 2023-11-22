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

  /*************************************************************
   *                                                           *
   *                      DONNEES DE TEST                      *
   *                                                           *
   *************************************************************/
  std::string text = R"lorem(Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.   
Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.   
Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.   
Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.   
Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis.   
At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, At accusam aliquyam diam diam dolore dolores duo eirmod eos erat, et nonumy sed tempor et et invidunt justo labore Stet clita ea et gubergren, kasd magna no rebum. sanctus sea sed takimata ut vero voluptua. est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat.   
Consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus.   
Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.   
Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.   
Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.   
Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo)lorem";
  double d = 42.0;


  /*************************************************************
   *                                                           *
   *                INITIALISATION DU BENCHMARK                *
   *                                                           *
   *************************************************************/
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


  /*************************************************************
   *                                                           *
   *              BENCHMARK DE passStringByValue               *
   *                                                           *
   *************************************************************/
  /*
  std::cout << "Benchmark de l'appel à passStringByValue...\n";
  size_t nbCallsStringByValue = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsStringByValue != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction passStringByValue en passant en paramètre la chaine de caractère texte
    ++nbCallsStringByValue;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsStringByValue << " fois la fonction passStringByValue.\n";
  double dPassStringByValueTime = std::max(static_cast<double>(duration.count()) / nbCallsStringByValue - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dPassStringByValueTime << "ns.\n\n";
  */

  /*************************************************************
   *                                                           *
   *                BENCHMARK DE passStringByRef               *
   *                                                           *
   *************************************************************/
  /*
  std::cout << "Benchmark de l'appel à passStringByRef...\n";
  size_t nbCallsStringByRef = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsStringByRef != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction passStringByRef en passant en paramètre la chaine de caractère texte
    ++nbCallsStringByRef;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsStringByRef << " fois la fonction passStringByRef.\n";
  double dPassStringByRefTime = std::max(static_cast<double>(duration.count()) / nbCallsStringByRef - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dPassStringByRefTime << "ns.\n\n";

  std::cout << "L'appel avec passage par référence est donc " << dPassStringByValueTime / dPassStringByRefTime << " fois plus rapide.\n\n\n";
  */


  /*************************************************************
   *                                                           *
   *              BENCHMARK DE passDoubleByValue               *
   *                                                           *
   *************************************************************/
  /*
  std::cout << "Benchmark de l'appel à passDoubleByValue...\n";
  size_t nbCallsDoubleByValue = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsDoubleByValue != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction passDoubleByValue en passant en paramètre la variable d
    ++nbCallsDoubleByValue;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsDoubleByValue << " fois la fonction passDoubleByValue.\n";
  double dPassDoubleByValueTime = std::max(static_cast<double>(duration.count()) / nbCallsDoubleByValue - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dPassDoubleByValueTime << "ns.\n\n";
  */


  /*************************************************************
   *                                                           *
   *                BENCHMARK DE passDoubleByRef               *
   *                                                           *
   *************************************************************/
  /*
  std::cout << "Benchmark de l'appel à passDoubleByRef...\n";
  size_t nbCallsDoubleByRef = 0;
  startTime = std::chrono::high_resolution_clock::now();
  while (nbCallsDoubleByRef != std::numeric_limits<size_t>::max() && (duration = std::chrono::high_resolution_clock::now() - startTime) < benchMarkDuration)
  {
    //Appeler ici la fonction passDoubleByRef en passant en paramètre la variable d
    ++nbCallsDoubleByRef;
  }
  std::cout << "En " << benchMarkDuration.count() << "s, il a été possible d'appeler " << nbCallsDoubleByRef << " fois la fonction passDoubleByRef.\n";
  double dPassDoubleByRefTime = std::max(static_cast<double>(duration.count()) / nbCallsDoubleByRef - dIterationControlTime, 0.0);
  std::cout << "Un appel dure donc " << dPassDoubleByRefTime << "ns.\n\n";

  std::cout << "L'appel avec passage par référence est donc " << dPassDoubleByValueTime / dPassDoubleByRefTime << " fois plus rapide.\n\n\n";
  */
}


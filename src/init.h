#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <cstdlib>

#ifdef linux
  #include "libraries/console/linux.h"
#endif
#ifdef _WIN32
  #include "libraries/console/window.h"
#endif

namespace lablnet {
  void clear(void)
  {
  #ifdef _WIN32
      std::system("cls");
  #else
      std::system ("clear");
  #endif
  }
}

#endif //INIT_H_INCLUDED

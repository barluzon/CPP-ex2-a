#include <iostream>
#include <string>
#include "Direction.hpp"
using ariel::Direction;

namespace ariel{
                              
   class Board {

      public:
      Board();
      static void post(unsigned int, unsigned int, Direction, const std::string &str);
      static std::string read(unsigned int, unsigned int, Direction, unsigned int);
      static void show();
   };
}


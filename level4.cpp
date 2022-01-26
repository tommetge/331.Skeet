/**********************************************************************
 * Level4
 * The fourth level
 **********************************************************************/

#include "level4.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level4::Level4()
   : size(15.0)
   {}

void Level4::spawn(list<Bird *> *birds)
{
   // spawns when there is nothing on the screen
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, 4.0, 18));

   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Standard(size, 4.0, 18));
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Sinker(size, 3.5, 25));
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Floater(size, 4.0, 25));
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Crazy(size));
}

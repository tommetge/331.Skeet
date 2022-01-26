/**********************************************************************
 * Level3
 * The third level
 **********************************************************************/

#include "level3.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level3::Level3()
   : size(20.0)
   {}

void Level3::spawn(list<Bird *> *birds)
{
   // spawns when there is nothing on the screen
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, 5.0, 15));

   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Standard(size, 5.0, 15));
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Sinker(size, 4.0, 22));
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Floater(size));
}

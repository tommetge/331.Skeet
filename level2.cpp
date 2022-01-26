/**********************************************************************
 * Level2
 * The second level
 **********************************************************************/

#include "level2.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level2::Level2()
   : size(25.0)
   {}

void Level2::spawn(list<Bird *> *birds)
{
   // spawns when there is nothing on the screen
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, 7.0, 12));

   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Standard(size, 5.0, 12));
   // spawn every 3 seconds
   if (random(0, 3 * 30) == 1)
      birds->push_back(new Sinker(size));
}

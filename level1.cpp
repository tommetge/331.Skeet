/**********************************************************************
 * Level1
 * The first level
 **********************************************************************/

#include "level1.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level1::Level1()
   : size(30.0)
   {}

void Level1::spawn(list<Bird *> *birds)
{
   // spawns when there is nothing on the screen
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, 7.0));

   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Standard(size, 7.0));
}

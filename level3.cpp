/**********************************************************************
 * Level3
 * The third level
 **********************************************************************/

#include "level3.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level3::Level3()
   : Level(20.0, 15)
   {}

void Level3::spawnSinker(std::list<Bird *> *birds)
{
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Sinker(size, 4.0, 22));
}

void Level3::spawnFloater(std::list<Bird *> *birds)
{
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Floater(size));
}

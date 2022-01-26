/**********************************************************************
 * Level2
 * The second level
 **********************************************************************/

#include "level2.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level2::Level2()
   : Level(25.0, 12)
   {}

void Level2::spawnSinker(std::list<Bird *> *birds)
{
   // spawn every 3 seconds
   if (random(0, 3 * 30) == 1)
      birds->push_back(new Sinker(size));
}

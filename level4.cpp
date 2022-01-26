/**********************************************************************
 * Level4
 * The fourth level
 **********************************************************************/

#include "level4.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

Level4::Level4()
   : Level(15.0, 18)
   {}

void Level4::spawnSinker(std::list<Bird *> *birds)
{
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Sinker(size, 3.5, 25));
}
   
void Level4::spawnFloater(std::list<Bird *> *birds)
{
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Floater(size, 4.0, 25));
}

void Level4::spawnCrazy(std::list<Bird *> *birds)
{
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Crazy(size));
}

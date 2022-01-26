/**********************************************************************
 * Level
 * The base level
 **********************************************************************/

#include "level.h"
#include "random.h"

using namespace std;
using namespace Skeeter;

void Level::spawn(std::list<Bird *> *birds) {
   spawnFirstBird(birds);
   spawnStandard(birds);
   spawnSinker(birds);
   spawnFloater(birds);
   spawnCrazy(birds);
};

void Level::spawnFirstBird(std::list<Bird *> *birds) {
   // spawns when there is nothing on the screen
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, 7.0, points));
}

void Level::spawnStandard(std::list<Bird *> *birds) {
   // spawn every 4 seconds
   if (random(0, 4 * 30) == 1)
      birds->push_back(new Standard(size, 5.0, points));
}
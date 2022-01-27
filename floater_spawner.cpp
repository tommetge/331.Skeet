/***********************************************************************
 * Source File:
 *    FLOATER SPAWNER
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a floater bird
 ************************************************************************/

#include "floater_spawner.h"
#include "random.h"

using namespace Skeeter;

/*********************************************
 * FLOATER SPAWNER
 * Constructor
 *********************************************/
FloaterSpawner::FloaterSpawner(double size, double speed, int points, int frequency)
   : size(size), speed(speed), points(points), frequency(frequency)
{}

/*********************************************
 * FLOATER SPAWNER
 * Spawns a standard bird
 *********************************************/
void FloaterSpawner::spawn(std::list<Bird *> *birds)
{
   // spawn every {frequency} seconds
   if (random(0, SpawnFrequency * 30) == 1)
      birds->push_back(new Floater(size, speed, points));
}
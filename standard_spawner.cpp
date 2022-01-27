/***********************************************************************
 * Source File:
 *    STANDARD SPAWNER
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a standard bird
 ************************************************************************/

#include "standard_spawner.h"
#include "random.h"

using namespace Skeeter;

/*********************************************
 * STANDARD SPAWNER
 * Constructor
 *********************************************/
StandardSpawner::StandardSpawner(double size, double speed, double initialBirdSpeed, int points)
   : size(size), speed(speed), initialBirdSpeed(initialBirdSpeed), points(points)
{}

/*********************************************
 * STANDARD SPAWNER
 * Spawns a standard bird
 *********************************************/
void StandardSpawner::spawn(std::list<Bird *> *birds)
{
   if (birds->size() == 0 && random(0, 15) == 1)
      birds->push_back(new Standard(size, initialBirdSpeed, points));
   
   // spawn every {frequency} seconds
   if (random(0, SpawnFrequency * 30) == 1)
      birds->push_back(new Standard(size, speed, points));
}
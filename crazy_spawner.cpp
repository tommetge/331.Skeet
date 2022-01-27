/***********************************************************************
 * Source File:
 *    CRAZY SPAWNER
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a crazy bird
 ************************************************************************/

#include "crazy_spawner.h"
#include "random.h"

using namespace Skeeter;

/*********************************************
 * CRAZY SPAWNER
 * Constructor
 *********************************************/
CrazySpawner::CrazySpawner(double size, double speed, int points, int frequency)
   : size(size), speed(speed), points(points), frequency(frequency)
{}

/*********************************************
 * CRAZY SPAWNER
 * Spawns a standard bird
 *********************************************/
void CrazySpawner::spawn(std::list<Bird *> *birds)
{
   // spawn every {frequency} seconds
   if (random(0, SpawnFrequency * 30) == 1)
      birds->push_back(new Crazy(size, speed, points));
}
/***********************************************************************
 * Source File:
 *    SINKER SPAWNER
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a sinker bird
 ************************************************************************/

#include "sinker_spawner.h"
#include "random.h"

using namespace Skeeter;

/*********************************************
 * SINKER SPAWNER
 * Constructor
 *********************************************/
SinkerSpawner::SinkerSpawner(double size, double speed, int points, int frequency)
   : size(size), speed(speed), points(points), frequency(frequency)
{}

/*********************************************
 * SINKER SPAWNER
 * Spawns a standard bird
 *********************************************/
void SinkerSpawner::spawn(std::list<Bird *> *birds)
{
   // spawn every {frequency} seconds
   if (random(0, SpawnFrequency * 30) == 1)
      birds->push_back(new Sinker(size, speed, points));
}
/***********************************************************************
 * Header File:
 *    StandardSpawner: Spawns a standard bird
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a standard bird
 ************************************************************************/

#pragma once

#include "bird_spawner.h"

/**********************
 * STANDARD SPAWNER
 * Spawns a standard bird
 **********************/
class StandardSpawner : public BirdSpawner
{
public:
   StandardSpawner(double size, double speed, double initialBirdSpeed, int points);

   void spawn(std::list<Bird *> *birds);

private:
   double size;
   double speed;
   double initialBirdSpeed;
   int points;
};

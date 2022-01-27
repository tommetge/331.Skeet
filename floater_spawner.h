/***********************************************************************
 * Header File:
 *    FloaterSpawner: Spawns a floater bird
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a floater bird
 ************************************************************************/

#pragma once

#include "bird_spawner.h"

/**********************
 * FLOATER SPAWNER
 * Spawns a floater bird
 **********************/
class FloaterSpawner : public BirdSpawner
{
public:
   FloaterSpawner(double size, double speed, int points, int frequency);

   void spawn(std::list<Bird *> *birds);

private:
   double size;
   double speed;
   int points;
   int frequency;
};

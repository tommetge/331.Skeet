/***********************************************************************
 * Header File:
 *    CrazySpawner: Spawns a crazy bird
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a crazy bird
 ************************************************************************/

#pragma once

#include "bird_spawner.h"

/**********************
 * CRAZY SPAWNER
 * Spawns a crazy bird
 **********************/
class CrazySpawner : public BirdSpawner
{
public:
   CrazySpawner(double size, double speed, int points, int frequency);

   void spawn(std::list<Bird *> *birds);

private:
   double size;
   double speed;
   int points;
   int frequency;
};

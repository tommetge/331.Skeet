/***********************************************************************
 * Header File:
 *    SinkerSpawner: Spawns a sinker bird
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a sinker bird
 ************************************************************************/

#pragma once

#include "bird_spawner.h"

/**********************
 * SINKER SPAWNER
 * Spawns a sinker bird
 **********************/
class SinkerSpawner : public BirdSpawner
{
public:
   SinkerSpawner(double size, double speed, int points, int frequency);

   void spawn(std::list<Bird *> *birds);

private:
   double size;
   double speed;
   int points;
   int frequency;
};

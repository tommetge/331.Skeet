/***********************************************************************
 * Header File:
 *    BirdSpawner: Spawns a bird of the correct type
 * Author:
 *    Team 1
 * Summary:
 *    Spawns a bird of the correct type
 ************************************************************************/

#pragma once

#include <list>
#include "bird.h"

static const int SpawnFrequency = 4;

/**********************
 * BIRD SPAWNER
 * Spawns a bird of the correct type
 **********************/
class BirdSpawner
{
public:
   virtual ~BirdSpawner() = default;

   virtual void spawn(std::list<Bird *> *birds) = 0;
};

/***********************************************************************
 * Header File:
 *    Level: Representation of a Level (using Decorator)
 * Author:
 *    Team 1
 * Summary:
 *    Representation of a Level (using Decorator)
 ************************************************************************/

#pragma once

#include <list>
#include <vector>
#include "bird.h"
#include "bird_spawner.h"

/**********************
 * LEVEL
 * Definition of a level
 **********************/
class Level
{
public:
   ~Level();

   // Takes ownership of the spawner pointer. Will be deleted when
   // Level is destructed.
   void addSpawner(BirdSpawner *spawner);

   void spawn(std::list<Bird *> *birds);

private:

   std::vector<BirdSpawner *> list;
};

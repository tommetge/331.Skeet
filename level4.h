/***********************************************************************
 * Header File:
 *    Level4: Level 4
 * Author:
 *    Team 1
 * Summary:
 *    Defines the fourth level
 ************************************************************************/

#pragma once

#include <list>

#include "level.h"
#include "bird.h"

/**********************
 * LEVEL 4
 * Defines level 4
 **********************/
class Level4: public Level
{
public:
   Level4();

   void spawnSinker(std::list<Bird *> *birds);
   void spawnFloater(std::list<Bird *> *birds);
   void spawnCrazy(std::list<Bird *> *birds);

};

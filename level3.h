/***********************************************************************
 * Header File:
 *    Level3: Level 3
 * Author:
 *    Team 1
 * Summary:
 *    Defines the third level
 ************************************************************************/

#pragma once

#include <list>

#include "level.h"
#include "bird.h"

/**********************
 * LEVEL 3
 * Defines level 3
 **********************/
class Level3: public Level
{
public:
   Level3();

   void spawnSinker(std::list<Bird *> *birds);
   void spawnFloater(std::list<Bird *> *birds);

};

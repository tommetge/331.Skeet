/***********************************************************************
 * Header File:
 *    Level2: Level 2
 * Author:
 *    Team 1
 * Summary:
 *    Defines the second level
 ************************************************************************/

#pragma once

#include <list>

#include "level.h"
#include "bird.h"

/**********************
 * LEVEL 2
 * Defines level 2
 **********************/
class Level2: public Level
{
public:
   Level2();

   void spawnSinker(std::list<Bird *> *birds);

};

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

#include "abstract_level.h"
#include "bird.h"

/**********************
 * LEVEL 2
 * Defines level 2
 **********************/
class Level2: public AbstractLevel
{
public:
   Level2();

   void spawn(std::list<Bird *> *birds);

private:
   double size;

};

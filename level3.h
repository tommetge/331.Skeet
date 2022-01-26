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

#include "abstract_level.h"
#include "bird.h"

/**********************
 * LEVEL 3
 * Defines level 3
 **********************/
class Level3: public AbstractLevel
{
public:
   Level3();

   void spawn(std::list<Bird *> *birds);

private:
   double size;

};

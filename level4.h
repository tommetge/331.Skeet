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

#include "abstract_level.h"
#include "bird.h"

/**********************
 * LEVEL 4
 * Defines level 4
 **********************/
class Level4: public AbstractLevel
{
public:
   Level4();

   void spawn(std::list<Bird *> *birds);

private:
   double size;

};

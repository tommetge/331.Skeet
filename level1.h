/***********************************************************************
 * Header File:
 *    Level1: Level 1
 * Author:
 *    Team 1
 * Summary:
 *    Defines the first level
 ************************************************************************/

#pragma once

#include <list>

#include "abstract_level.h"
#include "bird.h"

/**********************
 * LEVEL 1
 * Defines level 1
 **********************/
class Level1: public AbstractLevel
{
public:
   Level1();

   void spawn(std::list<Bird *> *birds);

private:
   double size;

};

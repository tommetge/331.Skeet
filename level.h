/***********************************************************************
 * Header File:
 *    Level: Abstract representation of a Level (using template)
 * Author:
 *    Team 1
 * Summary:
 *    Abstract representation of a Level (using template)
 ************************************************************************/

#pragma once

#include <list>
#include "bird.h"

/**********************
 * LEVEL
 * Abstract definition of a level
 **********************/
class Level
{
public:
   virtual void spawn(std::list<Bird *> *birds);

   virtual void spawnFirstBird(std::list<Bird *> *birds);
   virtual void spawnStandard(std::list<Bird *> *birds);
   virtual void spawnSinker(std::list<Bird *> *birds) {};
   virtual void spawnFloater(std::list<Bird *> *birds) {};
   virtual void spawnCrazy(std::list<Bird *> *birds) {};

protected:
   Level(double size, int points) :
      size(size), points(points)
   {}

   double size;
   int points;
};

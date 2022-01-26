/***********************************************************************
 * Header File:
 *    AbstractLevel: Abstract representation of a Level (using strategy)
 * Author:
 *    Team 1
 * Summary:
 *    Abstract representation of a Level (using strategy)
 ************************************************************************/

#pragma once

#include "bird.h"

/**********************
 * ABSTRACT LEVEL
 * Abstract definition of a level
 **********************/
class AbstractLevel
{
public:
   virtual void spawn(std::list<Bird *> *birds) = 0;

};

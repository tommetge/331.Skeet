/***********************************************************************
 * Header File:
 *    Killable : Defines a killable class (colleague)
 * Author:
 *    Team 1
 * Summary:
 *    Defines a killable class
 ************************************************************************/

#pragma once
#include "mediator.h"

/**********************
 * Killable: Defines a killable class
 **********************/
class Killable
{
protected:
    Killable(Mediator *mediator) : mediator(mediator) { }

    Mediator *mediator;

public:
    virtual void notifyOfTerm() {};
};

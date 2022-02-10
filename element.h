/***********************************************************************
 * Header File:
 *    Element : Defines an element in the visitor pattern
 * Author:
 *    Team 1
 * Summary:
 *    Defines an element
 ************************************************************************/

#pragma once
#include "visitor.h"

class Visitor;

/**********************
 * Element: Defines an element
 **********************/
class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;

    virtual bool isDead() const = 0;
};

class TerminalElement: public Element
{ };

class ExpirableElement: public Element
{ };

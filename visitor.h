/***********************************************************************
 * Header File:
 *    Visitor : Defines a visitor in the visitor pattern
 * Author:
 *    Team 1
 * Summary:
 *    Defines a visitor
 ************************************************************************/

#pragma once
#include "element.h"

class ExpirableElement;
class TerminalElement;

/**********************
 * Visitor: Defines a visitor
 **********************/
class Visitor
{
public:
    virtual void visit(ExpirableElement *element) = 0;
    virtual void visit(TerminalElement *element) = 0;
};

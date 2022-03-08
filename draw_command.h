/***********************************************************************
 * Header File:
 *    DRAW COMMAND
 * Author:
 *    Team 1
 * Summary:
 *    Draw command
 ************************************************************************/

#pragma once

/*************************************************************************
 * DrawCommand
 * The draw command class (encapsulated invocation)
 *************************************************************************/
class DrawCommand
{
public:
    virtual void execute() = 0;
};

/*************************************************************************
 * DrawSessionCommand
 * A concrete draw command that wraps execution with glBegin/glEnd
 *************************************************************************/
class DrawSessionCommand: public DrawCommand
{
public:
    void execute();
};

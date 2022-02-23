/***********************************************************************
 * Header File:
 *    TIME
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Time in level, what level it is, etc.
 ************************************************************************/

#pragma once

#include "time_controller.h"

/************************
 * TIME
 * Time in level, etc.
 ************************/
class Time
{
public:
    Time()
        : controller(this)
    { reset(); }
    
    // which level are we in?
    int level() const  { return controller.level(); }
    
    // are we currently playing in a level?
    bool isPlaying() const { return controller.isPlaying(); };
    
    // are we currently showing the status screen?
    bool isStatus() const { return controller.isStatus(); }
    
    // has the game ended?
    bool isGameOver() const { return controller.isGameOver(); }
    
    // is this the very start of the playing time of the leve
    bool isStartLevel() const { return controller.isStartLevel(); };
    
    // how much time is there left?
    int secondsLeft() const { return controller.secondsLeft(); };
    
    // what percent is left?
    double percentLeft() const { return controller.percentLeft(); };

    // move the time counter by one frame
    void operator++(int postfix) { controller++; };
    
    // text
    std::string getText() const;

    // reset
    void reset() { controller.reset(); };

private:
    // TimeController instance
    TimeController controller;
    
};



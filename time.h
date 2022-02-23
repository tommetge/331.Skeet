/***********************************************************************
 * Header File:
 *    TIME
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Time in level, what level it is, etc.
 ************************************************************************/

#pragma once

#include "time_logic.h"

/************************
 * TIME
 * Time in level, etc.
 ************************/
class Time
{
public:
    Time()
        : logic(this)
    { reset(); }
    
    // which level are we in?
    int level() const  { return logic.level(); }
    
    // are we currently playing in a level?
    bool isPlaying() const { return logic.isPlaying(); };
    
    // are we currently showing the status screen?
    bool isStatus() const { return logic.isStatus(); }
    
    // has the game ended?
    bool isGameOver() const { return logic.isGameOver(); }
    
    // is this the very start of the playing time of the leve
    bool isStartLevel() const { return logic.isStartLevel(); };
    
    // how much time is there left?
    int secondsLeft() const { return logic.secondsLeft(); };
    
    // what percent is left?
    double percentLeft() const { return logic.percentLeft(); };

    // move the time counter by one frame
    void operator++(int postfix) { logic++; };
    
    // text
    std::string getText() const;

    // reset
    void reset() { logic.reset(); };

private:
    // TimeLogic instance
    TimeLogic logic;
    
};



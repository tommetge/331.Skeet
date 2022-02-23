/***********************************************************************
 * Header File:
 *    TIME CONTROLLER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The controlling (think Q) side of Time.
 ************************************************************************/

#pragma once

#include "time_model.h"

#include <array>
#include <string>
#include <cassert>

#define FRAMES_PER_SECOND 30
#define SECONDS_STATUS 5.0

class Time;

/************************
 * TIME LOGIC
 * Time's logic.
 ************************/
class TimeController
{
public:
    TimeController(Time *time)
        : model(time)
    { }

    // which level are we in?
    int level() const  { return model.levelNumber; }
    
    // are we currently playing in a level?
    bool isPlaying() const;
    
    // are we currently showing the status screen?
    bool isStatus() const { return !isPlaying(); }
    
    // has the game ended?
    bool isGameOver() const { return model.levelNumber == 0; }
    
    // is this the very start of the playing time of the leve
    bool isStartLevel() const;
    
    // how much time is there left?
    int secondsLeft() const;
    
    // what percent is left?
    double percentLeft() const;

    // move the time counter by one frame
    void operator++(int postfix);

    // reset
    void reset();

private:
    // Time model
    TimeModel model;
    Time *view;

    // how long have we been in the level in seconds?
    int secondsInLevel() const
    {
        assert(model.levelNumber < (int)model.levelLength.size());
        return model.levelLength[model.levelNumber] - secondsFromFrames(model.framesLeft);
    }
    
    // seconds from frames
    int secondsFromFrames(int frame) const
    {
        return frame / FRAMES_PER_SECOND;
    }
};
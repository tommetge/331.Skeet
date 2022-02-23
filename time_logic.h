/***********************************************************************
 * Header File:
 *    TIME LOGIC
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The logical (think Mr. Spock) side of Time.
 ************************************************************************/

#pragma once

#include "time_storage.h"

#include <array>
#include <string>
#include <cassert>

#define FRAMES_PER_SECOND 30
#define SECONDS_STATUS 5.0

/************************
 * TIME LOGIC
 * Time's logic.
 ************************/
class TimeLogic
{
public:
    TimeLogic(TimeStorage *storage)
        : storage(storage)
    { }

    // which level are we in?
    int level() const  { return storage->levelNumber; }
    
    // are we currently playing in a level?
    bool isPlaying() const;
    
    // are we currently showing the status screen?
    bool isStatus() const { return !isPlaying(); }
    
    // has the game ended?
    bool isGameOver() const { return storage->levelNumber == 0; }
    
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
    // Time Storage
    TimeStorage *storage;

    // how long have we been in the level in seconds?
    int secondsInLevel() const
    {
        assert(storage->levelNumber < (int)storage->levelLength.size());
        return storage->levelLength[storage->levelNumber] - secondsFromFrames(storage->framesLeft);
    }
    
    // seconds from frames
    int secondsFromFrames(int frame) const
    {
        return frame / FRAMES_PER_SECOND;
    }
};
/***********************************************************************
 * Header File:
 *    TIME MODEL
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The model side of Time.
 ************************************************************************/

#pragma once

#include <array>
#include <string>
#include <cassert>

class Time;

/************************
 * TIME
 * Time's model.
 ************************/
class TimeModel
{
public:
    TimeModel(Time *view)
        : view(view)
    { }

    // number of frames left in this level
    int framesLeft;
    
    // the level number we are currently in
    int levelNumber;
    
    // length in seconds of each level
    std::array<int, 5> levelLength;

private:
    Time *view;
};
/***********************************************************************
 * Header File:
 *    TIME STORAGE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The storage side of Time.
 ************************************************************************/

#pragma once

#include <array>
#include <string>
#include <cassert>

/************************
 * TIME
 * Time's storage.
 ************************/
class TimeStorage
{
public:
    // number of frames left in this level
    int framesLeft;
    
    // the level number we are currently in
    int levelNumber;
    
    // length in seconds of each level
    std::array<int, 5> levelLength;
};
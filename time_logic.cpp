/***********************************************************************
 * Implementation File:
 *    TIME LOGIC
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The logical (think Mr. Spock) side of Time.
 ************************************************************************/

#include "time_logic.h"

/************************
 * TIME IS PLAYING
 * Are we currently in a game playing time?
 ************************/
bool TimeLogic::isPlaying() const
{
    // the first 5 seconds are not game plahing time.
    return secondsInLevel() > SECONDS_STATUS;
}

/************************
 * TIME IS START LEVEL
 * Os this the very start of the playing time of the leve
 ************************/
bool TimeLogic::isStartLevel() const
{
    if (isPlaying())
        return storage->framesLeft == FRAMES_PER_SECOND * (storage->levelLength[storage->levelNumber] - (int)SECONDS_STATUS) - 1;
    else
        return false;
}

/************************
 * TIME SECONDS LEFT
 * How much time left, including status messages
 ************************/
int TimeLogic::secondsLeft() const
{
    assert(storage->levelNumber >= 0 && storage->levelNumber < (int)storage->levelLength.size());
    if (isStatus())
        return secondsFromFrames(storage->framesLeft) - storage->levelLength[storage->levelNumber] + (int)SECONDS_STATUS + 1;
    else
        return secondsFromFrames(storage->framesLeft) + 1;
}

/************************
 * TIME PERCENT LEFT
 * What percent is left?
 ************************/
double TimeLogic::percentLeft() const
{
    assert(storage->levelNumber >= 0 && storage->levelNumber < (int)storage->levelLength.size());
    double framesInStatus = SECONDS_STATUS * FRAMES_PER_SECOND;
    double framesInPlaying = (storage->levelLength[storage->levelNumber] - SECONDS_STATUS) * FRAMES_PER_SECOND;
    
    if (isStatus())
    {
        assert(storage->framesLeft - framesInPlaying <= framesInStatus);
        assert(storage->framesLeft - framesInPlaying >= 0);
        assert(framesInStatus > 0);
        return (double)(storage->framesLeft - framesInPlaying) / (double)framesInStatus;
    }
    else
    {
        assert(storage->framesLeft - framesInStatus <= framesInPlaying);
        assert(storage->framesLeft - framesInStatus >= 0);
        assert(framesInPlaying > 0);
        return (double)(storage->framesLeft - framesInStatus) / (double)framesInPlaying;
    }
}

/************************
 * TIME ADVANCE
 * Advance the time counter by one frame
 ************************/
void TimeLogic::operator++(int postfix)
{
    assert(storage->levelNumber >= 0 && storage->levelNumber < (int)storage->levelLength.size());
    
    // do nothing in the game over scenario
    if (storage->levelNumber == 0)
        return;
    
    // standard move withing a level
    if (storage->framesLeft >= 1)
        storage->framesLeft--;
    
    // changing the level
    else
    {
        // move the level or...
        storage->levelNumber++;
        if (storage->levelNumber < (int)storage->levelLength.size())
            storage->framesLeft = FRAMES_PER_SECOND * storage->levelLength[storage->levelNumber];
        
        // game over!
        else
            storage->levelNumber = 0;
    }
}

/************************
 * TIME reset
 * Set up the levels and stuff
 ************************/
void TimeLogic::reset()
{
    // first level is 30 seconds in length, the first 5 are the status time
    storage->levelLength = {0, 30, 30, 45, 45};
    storage->levelNumber = 1;
    storage->framesLeft = FRAMES_PER_SECOND * storage->levelLength[storage->levelNumber];
}

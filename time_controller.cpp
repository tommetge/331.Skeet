/***********************************************************************
 * Implementation File:
 *    TIME CONTROLLER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The controlling (think Q) side of Time.
 ************************************************************************/

#include "time_controller.h"

/************************
 * TIME IS PLAYING
 * Are we currently in a game playing time?
 ************************/
bool TimeController::isPlaying() const
{
    // the first 5 seconds are not game plahing time.
    return secondsInLevel() > SECONDS_STATUS;
}

/************************
 * TIME IS START LEVEL
 * Os this the very start of the playing time of the leve
 ************************/
bool TimeController::isStartLevel() const
{
    if (isPlaying())
        return model.framesLeft == FRAMES_PER_SECOND * (model.levelLength[model.levelNumber] - (int)SECONDS_STATUS) - 1;
    else
        return false;
}

/************************
 * TIME SECONDS LEFT
 * How much time left, including status messages
 ************************/
int TimeController::secondsLeft() const
{
    assert(model.levelNumber >= 0 && model.levelNumber < (int)model.levelLength.size());
    if (isStatus())
        return secondsFromFrames(model.framesLeft) - model.levelLength[model.levelNumber] + (int)SECONDS_STATUS + 1;
    else
        return secondsFromFrames(model.framesLeft) + 1;
}

/************************
 * TIME PERCENT LEFT
 * What percent is left?
 ************************/
double TimeController::percentLeft() const
{
    assert(model.levelNumber >= 0 && model.levelNumber < (int)model.levelLength.size());
    double framesInStatus = SECONDS_STATUS * FRAMES_PER_SECOND;
    double framesInPlaying = (model.levelLength[model.levelNumber] - SECONDS_STATUS) * FRAMES_PER_SECOND;
    
    if (isStatus())
    {
        assert(model.framesLeft - framesInPlaying <= framesInStatus);
        assert(model.framesLeft - framesInPlaying >= 0);
        assert(framesInStatus > 0);
        return (double)(model.framesLeft - framesInPlaying) / (double)framesInStatus;
    }
    else
    {
        assert(model.framesLeft - framesInStatus <= framesInPlaying);
        assert(model.framesLeft - framesInStatus >= 0);
        assert(framesInPlaying > 0);
        return (double)(model.framesLeft - framesInStatus) / (double)framesInPlaying;
    }
}

/************************
 * TIME ADVANCE
 * Advance the time counter by one frame
 ************************/
void TimeController::operator++(int postfix)
{
    assert(model.levelNumber >= 0 && model.levelNumber < (int)model.levelLength.size());
    
    // do nothing in the game over scenario
    if (model.levelNumber == 0)
        return;
    
    // standard move withing a level
    if (model.framesLeft >= 1)
        model.framesLeft--;
    
    // changing the level
    else
    {
        // move the level or...
        model.levelNumber++;
        if (model.levelNumber < (int)model.levelLength.size())
            model.framesLeft = FRAMES_PER_SECOND * model.levelLength[model.levelNumber];
        
        // game over!
        else
            model.levelNumber = 0;
    }
}

/************************
 * TIME reset
 * Set up the levels and stuff
 ************************/
void TimeController::reset()
{
    // first level is 30 seconds in length, the first 5 are the status time
    model.levelLength = {0, 30, 30, 45, 45};
    model.levelNumber = 1;
    model.framesLeft = FRAMES_PER_SECOND * model.levelLength[model.levelNumber];
}

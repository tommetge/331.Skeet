/***********************************************************************
 * Header File:
 *    PersistedScore: Does all the score-related things.
 * Author:
 *    Team 1
 * Summary:
 *    A monster of a score utility.
 ************************************************************************/


#pragma once

#include "score.h"

class PersistedScore
{
public:
   // Score
   std::string getScoreText() const;
   void adjustScore(int value);
   void resetScore();

   // Hit Ratio
   std::string getHitRatioText() const;
   void adjustHitRatio(int value);
   void resetHitRatio();

private:
   Score score;
   HitRatio hitRatio;
}

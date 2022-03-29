/***********************************************************************
 * Header File:
 *    ScoreAdapter: Handles saving and loading the score
 * Author:
 *    Team 1
 * Summary:
 *    A file-backed, score saving monster.
 ************************************************************************/


#pragma once

#include "persisted_score.h"

class ScoreAdapter
{
public:
   void store(PersistedScore &score);
   PersistedScore fetch();

private:
   ScoreProvider provider;
   PersistedScore score;
}

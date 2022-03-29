/***********************************************************************
 * Header File:
 *    ScoreWebProvider: Simple web-backed storage for scores.
 * Author:
 *    Team 1
 * Summary:
 *    A web-backed, score saving monster.
 ************************************************************************/


#pragma once

#include "persisted_score.h"

class ScoreWebProvider
{
public:
   void store(PersistedScore &score);
   PersistedScore fetch();
}

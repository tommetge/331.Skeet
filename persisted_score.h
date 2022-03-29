/***********************************************************************
 * Header File:
 *    PersistedScore: Contains all elements of a score
 * Author:
 *    Team 1
 * Summary:
 *    All details about the user's score
 ************************************************************************/


#pragma once

#include "score.h"

struct PersistedScore
{
   Score score;
   HitRatio hit_ratio;
}

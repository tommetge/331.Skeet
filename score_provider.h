/***********************************************************************
 * Header File:
 *    ScoreProvider: Simple interface for score storage.
 * Author:
 *    Team 1
 * Summary:
 *    An interface for all the score saving monsters.
 ************************************************************************/


#pragma once

#include "persisted_score.h"

class ScoreProvider
{
public:
   void store(PersistedScore &score);
   PersistedScore fetch();
}

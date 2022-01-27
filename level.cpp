/***********************************************************************
 * Source File:
 *    LEVEL
 * Author:
 *    Team 1
 * Summary:
 *    Representation of a Level (using Decorator)
 ************************************************************************/

#include "level.h"

/*********************************************
 * LEVEL
 * Adds a spawner
 *********************************************/
void Level::addSpawner(BirdSpawner *spawner)
{
    list.push_back(spawner);
}

/*********************************************
 * LEVEL
 * Each spawner spawns a bird. You know, like
 * calling spawner->spawn(birds) for each bird.
 *********************************************/
void Level::spawn(std::list<Bird *> *birds)
{
    for (BirdSpawner *spawner : list) {
        spawner->spawn(birds);
    }
}

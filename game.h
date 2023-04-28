#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Party.h"
/**
 * This class contains all the high level functional methods for the game
 * These methods operate the various stages of the game at a high level 
 */

#include "Map.h"
#include "Merchant.h"
#include "GamePrompts.h"
#include "Monster.h"

//Game class definition
class Game
{
    private:

        // Object instantiations
        Map map;

        Prompts prompts;
        Monster monster;

    public:

        //Function declarations


        void start(Player &player, Merchant &merchant); // Game start

        void merchantInteraction(Player &player, Merchant &merchant); // Initial player interaction with merchant

        void movementPhase(Player &player, Merchant &merchant); // Player interaction with the actual map - primary game functionality
};

#endif
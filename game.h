#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
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

        bool gameEnd = false; //When true, game ends

    public:

        //Function declarations


        void start(Player &player, Merchant &merchant); // Game start

        void merchantInteraction(Player &player, Merchant &merchant); // Initial player interaction with merchant

        void movementPhase(Player &player, Merchant &merchant); // Player interaction with the actual map - primary game functionality
        
        void endGame(Player &player); //Ends game once player wins/loses

        void bubbleSort(vector<pair<string, int>> &scores); //Bubble sorting algorithm

        void scoreBoard(); //Prints score board
};

#endif
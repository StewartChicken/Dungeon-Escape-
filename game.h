#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Party.h"
#include "Map.h"
#include "Merchant.h"
#include "GamePrompts.h"

class Game
{
    private:

        Map map;

        Prompts prompts;

    public:
        void start(Player &player, Merchant &merchant);
        void merchantInteraction(Player &player, Merchant &merchant);

        //Part of the game that allows the player to move around the map
        void movementPhase(Player &player, Merchant &merchant);

        //Getters

        Player getPlayer();
        Merchant getMerchant();

};

#endif
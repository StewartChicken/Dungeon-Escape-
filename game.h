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

        Merchant merchant;
        Player player;

    public:
        void start();
        void merchantInteraction(Player &player, Merchant &merchant);
        void loadMap();

        //Getters

        Player getPlayer();
        Merchant getMerchant();

};

#endif
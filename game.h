#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Player.h"
#include "GameStats.h"
#include "Map.h"
//#include "Map.cpp" - not created yet
#include "Merchant.h"
#include "GamePrompts.h"

class Game
{
    private:
        Prompts prompts;

        Player player;
        
    public:
        void start();
        
};

#endif
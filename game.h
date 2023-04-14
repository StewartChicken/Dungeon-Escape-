#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Player.h"
#include "GameStats.h"
#include "Map.h"
//#include "Map.cpp" - not created yet
#include "Merchant.h"
#include "TeamMember.h"
#include "GamePrompts.h"

class Game
{
    private:
        Prompts prompts;

        Player player;
        teamMember members[4];

    public:
        void start();

};

#endif
#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H
#include "Player.h"
#include "Merchant.h"
#include <iostream>

using std::string;

class Prompts
{

    public:
        //Prompts player to enter their name
        string playerNamePrompt();
        int merchantPrompt(Player &player);
        int purchaseCost(int choice, Merchant &merchant);
};

#endif
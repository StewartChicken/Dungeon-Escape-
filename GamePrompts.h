#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

#include <iostream>
#include <map>
#include "Player.h"
#include "Merchant.h"

using std::string;

class Prompts
{

    public:
        //Prompts player to enter their name
        string playerNamePrompt();
        string memberNamePrompt();

        void teamGreetingPrompt(string, string, string, string, string);

        int merchantPrompt(Player &player);
        int purchaseCost(int choice, Merchant &merchant);
};

#endif
#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

#include <iostream>
#include <map>
#include "Party.h"
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

        void initialMerchantPrompt(Player &player);

        int purchaseCost(int choice, Merchant &merchant);

};

#endif
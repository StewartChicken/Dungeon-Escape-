#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

#include <iostream>
#include <map>
#include "Party.h"
#include "Merchant.h"
#include "Map.h"

using std::string;

class Prompts
{

    public:
        //Prompts player to enter their name
        string playerNamePrompt();
        string memberNamePrompt();

        void teamGreetingPrompt(string, string, string, string, string);

        int merchantPrompt(Player &player);

        void currentStatus(Player &player, Merchant &merchant, Map &map);

        void initialMerchantPrompt(Player &player);

        int purchaseCost(int choice, Merchant &merchant, Player &player);

};

#endif
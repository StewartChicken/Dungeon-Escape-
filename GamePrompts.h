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
        //Introductory prompts
        string playerNamePrompt(); //Enter player name
        string memberNamePrompt(); //Enter team member names
        void teamGreetingPrompt(string, string, string, string, string); //Greet team members
        void goodLuckPrompt();

        //Merchant Prompts
        int merchantPrompt(Player &player);\
        int purchaseCost(int choice, Merchant &merchant, Player &player);
        void currentStatus(Player &player, Merchant &merchant, Map &map);
        void initialMerchantPrompt(Player &player);

        //Major buy menu prompts
        void ingredientBuyMenu(Merchant &merchant, int &costPerUnit, string &item, string &quantitySuffix);
        void cookwareBuyMenu();
        void weaponBuyMenu();
        void sellTreasureMenu(Merchant &merchant);
        void armorBuyMenu(Merchant &merchant, string &item);

        //Buy sub-menus


        void imaginaryGlassesPrompt();
        void brokePrompt();
        
        void movementExplorePrompt();
        void movementErrorPrompt();
        void invalidPositionPrompt();
        void invalidInputPrompt();

};

#endif
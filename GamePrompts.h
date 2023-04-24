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
        void merchantPrompt(Player &player, Merchant &merchant);
      
        void merchantInteraction(Player &player, Merchant &merchant, bool &active);
        void merchantGreeting(Player &player);

        //Major buy menu prompts
        int itemBuyMenu(Player &player, Merchant &merchant, int price, string itemLabel);
        int confirmPurchase(Player &player, Merchant &merchant, int numItems, int price, string item);
        void sellTreasureMenu(Player &player, Merchant &merchant);
    
        //Cookware and Weapon sub menus
        void cookwareBuyMenu(Player &player, Merchant &merchant);
        void weaponBuyMenu(Player &player, Merchant &merchant);
        
        //Does the party have sufficient gold to make a purchase
        bool canPurchaseGoods(Player &player, int amount, int price);

        //void currentStatus(Player &player, Merchant &merchant, Map &map);
        void currentStatus(Player &player, Merchant &merchant, Map &map);
        
        void roomInteractionPrompt(Player &player, Merchant &merchant, Map &map);
        bool roomKeyPrompt(Player &player);
        void launchMonsterFight(int combatScore, int roomsCleared);

        //Random single prompts

        void imaginaryGlassesPrompt();
        void brokePrompt();
        
        void movementExplorePrompt();
        void movementInteractPrompt();
        void movementErrorPrompt();
        void invalidPositionPrompt();
        void invalidInputPrompt();
        void negativeAmountWarning();

};

#endif
#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

#include <iostream>
#include <map>
#include "Party.h"
#include "Merchant.h"
#include "Map.h"
#include "Monster.h"

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
        void currentStatus(Player &player, Merchant &merchant);
        
        //User interacts with a room entity
        void roomInteractionPrompt(Player &player, Merchant &merchant, Map &map, Monster &monster);

        //User plays Boulder, Parchment, Shears with a door
        bool doorGameInteraction(Player &player);

        //Does the user want to use a key to enter a room?
        bool roomKeyPrompt(Player &player);

        //Launch a monster fight with the user
        void launchMonsterFight(Player &player, Merchant &merchant, Map &map, double combatScore, int roomsCleared, string monsterName, Monster &monster, bool enteredRoom);

        //Random single prompts

        void imaginaryGlassesPrompt(); //Player tries to sell something he/she doesn't have
        void brokePrompt(); //Player can't afford to make a purchase from the merchant
        
        //Different prompts depending on which map entity the player is over
        void movementExplorePrompt();
        void onRoomSpacePrompt();
        void onNPCSpacePrompt();
        void onExitSpacePrompt();

        //Invalid movement prompts
        void movementErrorPrompt();
        void invalidPositionPrompt();
        void invalidInputPrompt();

        //User interacts with NPC's 
        void npcInteractionPrompt(Player &player, Merchant &merchant, Map &map, Monster &monster);
        void npcWelcomeMessage();
        bool npcRiddle();
        bool barterPrompt();
        void read(string file_name,string arr[][2], int array_size);
        void split(string input_string, char seperator, string arr[], int arr_size);

        //User interacts with the dungeon exit
        void exitInteractionPrompt(Player &player, Merchant &merchant, bool &gameEnd);

        //User cooks food prompts
        int foodQuantityPrompt(int available);
        int cookWithPrompts(Player &player);

        //Is a string value a digit?
        bool validNumericalInput(string userInput);

        //Endgame functions
        void endgameStats(Player &player, Map &map);
        void vectorSplit(std::string line, std::vector<std::pair<string, int>> &vect);
        void vectorRead(std::string file_name, std::vector<std::pair<string, int>> &vect);
        void printBoard(std::vector<pair<std::string, int>> &vect);

};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "time.h"

using std::string;
using std::map;

class Player
{
    private:
        
        //Stores party's names and fullness levels
        map<string, int> fullnessLevels;
        string partyNames[5];
        bool isMemberAlive[4]; // Tracks the death status of each team member

        /*!!Remember to set up gold too!!(100 initial gold for the pary)*/

        //Combat values

        int numWeapons;

        //Weapons (5 max)
        int stoneClubs; //2 gold - denoted C
        int ironSpears; //2 gold - denoted S
        int mythrilRapiers; //5 gold - +1 attack - denoted R
        int flamingAxes; //15 gold - +2 attack - denoted B
        int vorpalSwords; //50 gold - +3 attack - denoted L

        //Purchasing 1 per team member maximizes survival chance. Purchasing
        //more than this value does not increase survival chance. 
        int armorSuits; //5 gold

        //Team combat score depending on the weapons carried by team
        int combatScore;


        //Cookware
        int ceramicPots; //2 gold - stews and boils - 25% chance of breaking per use
        int fryingPans;  //10 gold - fries and sizzles -    10% chance of breaking per use
        int cauldrons;   //20 gold - stews and boils - 2% chance of breaking per use

        //Inventory values
        int gold; 
        int ingredients; //1 gold per kg
        int numKeys;

        //Treasures - can be sold to merchant
        int silverRings; //10 gold - denoted E
        int rubyNecklaces; //20 gold - denoted N
        int emeraldBracelets; //30 gold - denoted B
        int diamondCirclets; //40 gold - denoted C
        int gemGoblets; //50 gold denoted - G

        //Eastereggs - make the game more interesting
        int imaginaryGlasses;

    public:
        //Constructor
        Player();
        
        //Adds new team member at a given index
        void addNewMember(string, int);

        //Sets the fullness level of a given player or team member to the passed fullness level
        void setFullnessLevel(string, int);

        //Returns the fullness level of a given player or team member
        int getFullness(string);

        std::string getPlayerName();
        std::string getMember1Name();
        std::string getMember2Name();
        std::string getMember3Name();
        std::string getMember4Name();
        
        //Increment or decrement the fullness of a given player or team member
        void incrementFullness(string);
        void decrementFullness(string);
        
        //Cooks and eats food in increments of 5kgs
        bool cookedSuccessfully(int);
        void cookFood(int,int);


        //Inventory methods

        int getGold();
        int getIngredients();
        int getNumKeys();

        int getSilverRings();
        int getRubyNecklaces();
        int getEmeraldBracelets();
        int getDiamondCirclets();
        int getGemGoblets();

        int getImaginaryGlasses();

        void setGold(int);
        void setIngredients(int);
        void setNumKeys(int);
        
        void setSilverRings(int);
        void setRubyNecklaces(int);
        void setEmeraldBracelets(int);
        void setDiamondCirclets(int);
        void setGemGoblets(int);

        void incrementKeys();
        void decrementKeys();

        void incrementImaginaryGlasses();

        //Sudorandom events
        void hungerMisfortune(int chances);
        bool investigate(int roomsCleared);
        void incrementTreasure(int roomsCleared);
        

        //Combat methods
        int countNumWeapons();
        int getNumWeapons();

        int getStoneClubs();
        int getIronSpears();
        int getMythrilRapiers();
        int getFlamingAxes();
        int getVorpalSwords();
        int getArmorSuits();

        void setNumWeapons(int);

        void setStoneClubs(int);
        void setIronSpears(int);
        void setMythrilRapiers(int);
        void setFlamingAxes(int);
        void setVorpalSwords(int);
        void setArmorSuits(int);

        //Calculates combat score - chance of winning a fight against
        // a monster. Takes the current monster challenge rating as an argument. 
        double calculateCombatScore(int);
        bool winsFight(double combatScore);
        void winFight(double challengeRating); // Called in the event the player wins a monster fight
        void loseFight();
        void surrenderTeamMember();


        //Cookware methods

        int getCeramicPots();
        int getFryingPans();
        int getCauldrons();
        
        void setCeramicPots(int);
        void setFryingPans(int);
        void setCauldrons(int);

};

#endif
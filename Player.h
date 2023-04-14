#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player
{
    private:
        
        int fullness; //Can be replenished with cooked meals
        int gold; 
        int ingredients; //1 gold per kg

        //Cookware
        int ceramicPots; //2 gold - stews and boils - 25% chance of breaking per use
        int fryingPans;  //10 gold - fries and sizzles -    10% chance of breaking per use
        int cauldrons;   //20 gold - stews and boils - 2% chance of breaking per use

        //Weapons (5 max)
        int stoneClubs; //2 gold - denoted C
        int ironSpears; //2 gold - denoted S
        int mythrilRapiers; //5 gold - +1 attack - denoted R
        int flamingAxes; //15 gold - +2 attack - denoted B
        int vorpalSwords; //50 gold - +3 attack - denoted L

        //Number of weapons
        int numWeapons;

        //Purchasing 1 per team member maximizes survival chance. Purchasing
        //more than this value does not increase survival chance. 
        int armorSuits; //5 gold

        //Treasures - can be sold to merchant
        int silverRings; //10 gold - denoted E
        int rubyNecklaces; //20 gold - denoted N
        int emeraldBracelets; //30 gold - denoted B
        int diamondCirclets; //40 gold - denoted C
        int gemGoblets; //50 gold denoted - G

        //Number of keys the player has found
        int numKeys;

        //Playername
        std::string name;

        //Team combat score depending on the weapons carried by team
        int combatScore;

        int memberHungerLevels[4];
        string memberNames[4];

    public:
        //Constructors
        Player();
        Player(std::string);

        //Setters
        void setFullness(int);
        void setGold(int);
        void setIngredients(int);
        void setCeramicPots(int);
        void setFryingPans(int);
        void setCauldrons(int);
        void setStoneClubs(int);
        void setIronSpears(int);
        void setMythrilRapiers(int);
        void setFlamingAxes(int);
        void setVorpalSwords(int);
        void setArmorSuits(int);
        void setSilverRings(int);
        void setRubyNecklaces(int);
        void setEmeraldBracelets(int);
        void setDiamondCirclets(int);
        void setGemGoblets(int);
        void setNumKeys(int);
        void setNumWeapons(int);
        void setName(std::string);
  
        //Getters
        int getFullness();
        int getGold();
        int getIngredients();
        int getCeramicPots();
        int getFryingPans();
        int getCauldrons();
        int getStoneClubs();
        int getIronSpears();
        int getMythrilRapiers();
        int getFlamingAxes();
        int getVorpalSwords();
        int getArmorSuits();
        int getSilverRings();
        int getRubyNecklaces();
        int getEmeraldBracelets();
        int getDiamondCirclets();
        int getGemGoblets();
        int getNumKeys();
        int getNumWeapons();
        std::string getName();
        
        //Incremental Methods
        void incrementFullness();
        void decrementFullness();

        void incrementKeys();
        void decrementKeys();

        //Cooks and eats food in increments of 5kgs
        void cookFood(int);

        //Calculates combat score - chance of winning a fight against
        // a monster. Takes the current monster challenge rating as an argument. 
        void calculateCombatScore(int);

};

#endif
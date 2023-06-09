// CSCI 1300 Spring 2023
// Author: Wyatt Massey & Evan Poon
// Recitation: 202 – Lin Shi
// Project 3 - Merchant
#ifndef MERCHANT_H
#define MERCHANT_H

#include <iostream>
#include <string>

class Merchant
{
    private:

        //Number of rooms cleared by player - impacts multiplier
        int roomsCleared = 0;

        //Determines the multiplier for the price of goods
        float multiplier;


        //Constant values for prices    

        //Default prices for each commodity
        const int ingredientPrice = 1;

        const int ceramicPotPrice = 2;
        const int fryingPanPrice = 10;
        const int cauldronPrice = 20;

        const int stoneClubPrice = 2;
        const int ironSpearPrice = 2;
        const int mythrilRapierPrice = 5;
        const int flamingAxePrice = 15;
        const int vorpalSwordPrice = 50;

        const int armorSuitPrice = 5;

        //Trade in value for treasures found by the player
        const int silverRingValue = 10;
        const int rubyNecklaceValue = 20;
        const int emeraldBraceletValue = 30;
        const int diamondCircletValue = 40;
        const int gemGobletValue = 50;

    public:

        //Constructor
        Merchant();

        //Getters

        int getIngredientPrice();
        int getCeramicPotPrice();
        int getFryingPanPrice();
        int getCauldronPrice();
        int getStoneClubPrice();
        int getIronSpearPrice();
        int getMythrilRapierPrice();
        int getFlamingAxePrice();
        int getVorpalSwordPrice();
        int getArmorSuitPrice();
        int getSilverRingValue();
        int getRubyNecklaceValue();
        int getEmeraldBraceletValue();
        int getDiamondCircletValue();
        int getGemGobletValue();

        int getRoomsCleared();

        //Change number of rooms cleared for merchant
        void setRoomsCleared(int);
        void incrementRoomsCleared();

        //Updates multiplier after number of rooms cleared changes
        void updateMultiplier();
};

#endif
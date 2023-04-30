#include "Merchant.h"

//Constructor
Merchant::Merchant()
{
    this -> roomsCleared = 0;
    this -> multiplier = (0.25 * roomsCleared) + 1.0;
}

//Getters

int Merchant::getIngredientPrice()
{
    return ingredientPrice * multiplier;
}

int Merchant::getCeramicPotPrice()
{
    return ceramicPotPrice * multiplier;
}

int Merchant::getFryingPanPrice()
{
    return fryingPanPrice * multiplier;
}

int Merchant::getCauldronPrice()
{
    return cauldronPrice * multiplier;
}

int Merchant::getStoneClubPrice()
{
    return stoneClubPrice * multiplier;
}

int Merchant::getIronSpearPrice()
{
    return ironSpearPrice * multiplier;
}

int Merchant::getMythrilRapierPrice()
{
    return mythrilRapierPrice * multiplier;
}

int Merchant::getFlamingAxePrice()
{
    return flamingAxePrice * multiplier;
}

int Merchant::getVorpalSwordPrice()
{
    return vorpalSwordPrice * multiplier;
}

int Merchant::getArmorSuitPrice()
{
    return armorSuitPrice * multiplier;
}

int Merchant::getSilverRingValue()
{
    return silverRingValue;
}

int Merchant::getRubyNecklaceValue()
{
    return rubyNecklaceValue;
}

int Merchant::getEmeraldBraceletValue()
{
    return emeraldBraceletValue;
}

int Merchant::getDiamondCircletValue()
{
    return diamondCircletValue;
}

int Merchant::getGemGobletValue()
{
    return gemGobletValue;
}

int Merchant::getRoomsCleared()
{
    return roomsCleared;
}

//Setters

void Merchant::setRoomsCleared(int roomsCleared)
{
    this -> roomsCleared = roomsCleared;
}

void Merchant::incrementRoomsCleared()
{
    this -> roomsCleared ++;
}

//Updates the merchant multplier after then number of rooms cleared changes
void Merchant::updateMultiplier()
{
    this -> multiplier = (0.25 * roomsCleared) + 1.0;
}
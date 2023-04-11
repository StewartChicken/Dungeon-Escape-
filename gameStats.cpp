#include <iostream>
#include "gameStats.h"

GameStats::GameStats()
{
    //Gamestats
    this -> roomsCleared = 0;
    this -> numKeys = 0;
    this -> angerLevel = 0;

    //Inventory
    this -> gold = 100;
    this -> ingredients = 0;
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 0;
    this -> stoneClubs = 0;
    this -> ironSpears = 0;
    this -> mythrilRapiers = 0;
    this -> flamingAxes = 0;
    this -> vorpalSwords = 0;
    this -> armor = 0;
    this -> silverRings = 0;
    this -> rubyNecklaces = 0;
    this -> emeraldBracelets = 0;
    this -> diamondCirclets = 0;
    this -> gemGoblets = 0;

    this -> playerFullness = 50;
    this -> member1Fullness = 50;
    this -> member2Fullness = 50;
    this -> member3Fullness = 50;
    this -> member4Fullness = 50;
}

//Getters 

int GameStats::getRoomsCleared()
{
    return roomsCleared;
}

int GameStats::getNumKeys()
{
    return numKeys;
}

int GameStats::getAngerlevel()
{
    return angerLevel;
}

int GameStats::getGoldAmount()
{
    return gold;
}

int GameStats::getIngredients()
{
    return ingredients;
}

int GameStats::getCeramicPots()
{
    return ceramicPots;
}

int GameStats::getFryingPans()
{
    return fryingPans;
}

int GameStats::getCauldrons()
{
    return cauldrons;
}

int GameStats::getStoneClubs()
{
    return stoneClubs;
}

int GameStats::getIronSpears()
{
    return ironSpears;
}

int GameStats::getMythrilRapiers()
{
    return mythrilRapiers;
}

int GameStats::getFlamingAxes()
{
    return flamingAxes;
}

int GameStats::getVorpalSwords()
{
    return vorpalSwords;
}

int GameStats::getArmor()
{
    return armor;
}

int GameStats::getSilverRings()
{
    return silverRings;
}

int GameStats::getRubyNecklaces()
{
    return rubyNecklaces;
}

int GameStats::getEmeraldBracelets()
{
    return emeraldBracelets;
}

int GameStats::getDiamondCirclets()
{
    return diamondCirclets;
}

int GameStats::getGemGoblets()
{
    return gemGoblets;
}

int GameStats::getPlayerFullness()
{
    return playerFullness;
}

int GameStats::getMember1Fullness()
{
    return member1Fullness;
}

int GameStats::getMember2Fullness()
{
    return member2Fullness;
}

int GameStats::getMember3Fullness()
{
    return member3Fullness;
}

int GameStats::getMember4Fullness()
{
    return member4Fullness;
}

//Setters

void GameStats::setRoomsCleared(int rooms)
{
    roomsCleared = rooms;
}

void GameStats::setNumKeys(int numKeys)
{
    this -> numKeys = numKeys;
}

void GameStats::setAngerlevel(int angerLevel)
{
    this -> angerLevel = angerLevel;
}

void GameStats::setGoldAmount(int gold)
{
    this -> gold = gold;
}

void GameStats::setIngredients(int ingredients)
{
    this -> ingredients = ingredients;
}

void GameStats::setCeramicPots(int ceramicPots)
{
    this -> ceramicPots = ceramicPots;
}

void GameStats::setFryingPans(int fryingPans)
{
    this -> fryingPans = fryingPans;
}

void GameStats::setCauldrons(int cauldrons)
{
    this -> cauldrons = cauldrons;
}

void GameStats::setStoneClubs(int stoneClubs)
{
    this -> stoneClubs = stoneClubs;
}

void GameStats::setIronSpears(int ironSpears)
{
    this -> ironSpears = ironSpears;
}

void GameStats::setMythrilRapiers(int mythrilRapiers)
{
    this -> mythrilRapiers = mythrilRapiers;
}

void GameStats::setFlamingAxes(int flamingAxes)
{
    this -> flamingAxes = flamingAxes;
}

void GameStats::setVorpalSwords(int vorpalSwords)
{
    this -> vorpalSwords = vorpalSwords;
}

void GameStats::setArmor(int armor)
{
    this -> armor = armor;
}

void GameStats::setSilverRings(int silverRings)
{
    this -> silverRings = silverRings;
}

void GameStats::setRubyNecklaces(int rubyNecklaces)
{
    this -> rubyNecklaces = rubyNecklaces;
}

void GameStats::setEmeraldBracelets(int emeraldBracelets)
{
    this -> emeraldBracelets = emeraldBracelets;
}

void GameStats::setDiamondCirclets(int diamondCirclets)
{
    this -> diamondCirclets = diamondCirclets;
}

void GameStats::setGemGoblets(int gemGoblets)
{
    this -> gemGoblets = gemGoblets;
}

void GameStats::setPlayerFullness(int playerFullness)
{
    this -> playerFullness = playerFullness;
}

void GameStats::setMember1Fullness(int member1Fullness)
{
    this -> member1Fullness = member1Fullness;
}

void GameStats::setMember2Fullness(int member2Fullness)
{
    this -> member2Fullness = member2Fullness;
}

void GameStats::setMember3Fullness(int member3Fullness)
{
    this -> member3Fullness = member3Fullness;
}

void GameStats::setMember4Fullness(int member4Fullness)
{
    this -> member4Fullness = member4Fullness;
}


//Incremental methods

void GameStats::incrementRoomsCleared()
{
    roomsCleared ++;
}

void GameStats::decrementRoomsCleared()
{
    roomsCleared --;
}

void GameStats::incrementNumKeys()
{
    numKeys ++;
}

void GameStats::decrementNumKeys()
{
    numKeys --;
}

void GameStats::incrementAngerlevel()
{
    angerLevel ++;
}

void GameStats::decrementAngerlevel()
{
    angerLevel --;
}

void GameStats::incrementPlayerFullness()
{
    playerFullness ++;
}

void GameStats::decrementPlayerFullness()
{
    playerFullness --;
}

void GameStats::incrementMember1Fullness()
{
    member1Fullness ++;
}

void GameStats::decrementMember1Fullness()
{
    member1Fullness --;
}

void GameStats::incrementMember2Fullness()
{
    member2Fullness ++;
}

void GameStats::decrementMember2Fullness()
{
    member2Fullness --;
}

void GameStats::incrementMember3Fullness()
{
    member3Fullness ++;
}

void GameStats::decrementMember3Fullness()
{
    member3Fullness --;
}

void GameStats::incrementMember4Fullness()
{
    member4Fullness ++;
}

void GameStats::decrementMember4Fullness()
{
    member4Fullness --;
}


#include "Party.h"

//Default constructor
Player::Player()
{

    //Party default names
    this -> partyNames[0] = "Player";
    this -> partyNames[1] = "Member1";
    this -> partyNames[2] = "Member2";
    this -> partyNames[3] = "Member3";
    this -> partyNames[4] = "Member4";


    //Party default combat values
    
    //weapons
    this -> stoneClubs = 0;
    this -> ironSpears = 0;
    this -> mythrilRapiers = 0;
    this -> flamingAxes = 0;
    this -> vorpalSwords = 0;
    
    this -> armorSuits = 0; 

    this -> combatScore = 0;

    //cookware
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 0;


    //Party default inventory values

    this -> gold = 0;
    this -> numKeys = 0;
    this -> ingredients = 0;


    //Treasures found
    this -> silverRings = 0; 
    this -> rubyNecklaces = 0; 
    this -> emeraldBracelets = 0; 
    this -> diamondCirclets = 0; 
    this -> gemGoblets = 0;
    this -> imaginaryGlasses = 0; 


    

}



//Player and team member name/hunger management methods

//Adds new party member
void Player::addNewMember(std::string name, int index)
{
    this -> fullnessLevels[name] = 50;
    partyNames[index] = name;
}

void Player::setFullnessLevel(string name, int fullness)
{
    this -> fullnessLevels[name] = fullness;
}

int Player::getFullness(string partyMember)
{
    return fullnessLevels[partyMember];
}

std::string Player::getPlayerName()
{
    return partyNames[0];
}

std::string Player::getMember1Name()
{
    return partyNames[1];
}

std::string Player::getMember2Name()
{
    return partyNames[2];
}

std::string Player::getMember3Name()
{
    return partyNames[3];
}

std::string Player::getMember4Name()
{
    return partyNames[4];
}

//Increments the fullness of the player
void Player::incrementFullness(string partyMember)
{
    this -> fullnessLevels[partyMember] ++;
}

//Decrements the fullness of the player
void Player::decrementFullness(string partyMember)
{
    this -> fullnessLevels[partyMember] --;
}

//Player::cookFood function definition
//Cooks food in incrememnts of 5 kg since there are 5 team members
//The input argument is the number of servings that will be cooked
// total food cooked will be servings * 5
//Successful cooks will increase fullness by 1 for each team member
//If the pot breaks, cook fails and the food is lost
//Returns void
void Player::cookFood(int servings)
{
    //Todo
}



//Inventory methods

int Player::getGold()
{
    return gold;
}

int Player::getIngredients()
{
    return ingredients;
}

int Player::getNumKeys()
{
    return numKeys;
}

int Player::getSilverRings()
{
    return silverRings;
}

int Player::getRubyNecklaces()
{
    return rubyNecklaces;
}

int Player::getEmeraldBracelets()
{
    return emeraldBracelets;
}

int Player::getDiamondCirclets()
{
    return diamondCirclets;
}

int Player::getGemGoblets()
{
    return gemGoblets;
}

int Player::getImaginaryGlasses()
{
    return imaginaryGlasses;
}

void Player::setGold(int gold)
{
    this -> gold = gold;
}

void Player::setIngredients(int ingredients)
{
    this -> ingredients = ingredients;
}

void Player::setNumKeys(int numKeys)
{
    this -> numKeys = numKeys;
}

void Player::setSilverRings(int silverRings)
{
    this -> silverRings = silverRings;
}

void Player::setRubyNecklaces(int rubyNecklaces)
{
    this -> rubyNecklaces = rubyNecklaces;
}

void Player::setEmeraldBracelets(int emeraldBracelets)
{
    this -> emeraldBracelets = emeraldBracelets;
}

void Player::setDiamondCirclets(int diamondCirclets)
{
    this -> diamondCirclets = diamondCirclets;
}

void Player::setGemGoblets(int gemGoblets)
{
    this -> gemGoblets = gemGoblets;
}

void Player::incrementKeys()
{
    this -> numKeys ++;
}

void Player::decrementKeys()
{
    this -> numKeys --;
}

void Player::incrementImaginaryGlasses()
{
    this -> imaginaryGlasses ++;
} 


//Combat methods


int Player::getNumWeapons()
{
    return numWeapons;
}

int Player::getStoneClubs()
{
    return stoneClubs;
}

int Player::getIronSpears()
{
    return ironSpears;
}

int Player::getMythrilRapiers()
{
    return mythrilRapiers;
}

int Player::getFlamingAxes()
{
    return flamingAxes;
}

int Player::getVorpalSwords()
{
    return vorpalSwords;
}

int Player::getArmorSuits()
{
    return armorSuits;
}

void Player::setNumWeapons(int numWeapons)
{
    this -> numWeapons = numWeapons;
}


void Player::setStoneClubs(int stoneClubs)
{
    this -> stoneClubs = stoneClubs;
}

void Player::setIronSpears(int ironSpears)
{
    this -> ironSpears = ironSpears;
}

void Player::setMythrilRapiers(int mythrilRapiers)
{
    this -> mythrilRapiers = mythrilRapiers;
}

void Player::setFlamingAxes(int flamingAxes)
{
    this -> flamingAxes = flamingAxes;
}

void Player::setVorpalSwords(int vorpalSwords)
{
    this -> vorpalSwords = vorpalSwords;
}

void Player::setArmorSuits(int armorSuits)
{
    this -> armorSuits = armorSuits;
}

//Calculates the combat score for the team based on the weapons within the inventory
//Formula : (r1 * w + d) - (r2 * c)/a
// w is the number of weapons the party possesses + bonus points for upgraded weapons
//  + (number of mythrilRapiers) + 2*(number of flaming axes) + 3*(number of vorbalSwords)
// d is 4 if each party member has a different weapon and is 0 if not
// a is the number of armor suits the party has
// c is the challenge rating of the monster

//TODO - random numbers for r1, r2. Return combat score
void Player::calculateCombatScore(int monsterChallengeRating)
{
    int w = numWeapons + mythrilRapiers + 2 * flamingAxes + 3 * vorpalSwords;

    //Calculate d
    int d;
    if(stoneClubs == 1 && ironSpears == 1 && mythrilRapiers == 1 && flamingAxes == 1 && vorpalSwords == 1)
    {
        d = 4;
    }
    else
    {
        d = 0;

    }

    //number of armor suits
    int a = armorSuits;

    int c = monsterChallengeRating;

    //int r1 = [RANDOM NUMBER]
    //int r2 = [RANDOM NUMBER]

}


//Cookware methods

int Player::getCeramicPots()
{
    return ceramicPots;
}

int Player::getFryingPans()
{
    return fryingPans;
}

int Player::getCauldrons()
{
    return cauldrons;
}


void Player::setCeramicPots(int ceramicPots)
{
    this -> ceramicPots = ceramicPots;
}

void Player::setFryingPans(int fryingPans)
{
    this -> fryingPans = fryingPans;
}

void Player::setCauldrons(int cauldrons)
{
    this -> cauldrons = cauldrons;
}
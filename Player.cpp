#include "Player.h"

//Default constructor
Player::Player()
{
    this -> fullness = 50;
    this -> gold = 100;
    this -> ingredients = 0;

    //cookware
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 0;

    //weapons
    this -> stoneClubs = 0;
    this -> ironSpears = 0;
    this -> mythrilRapiers = 0;
    this -> flamingAxes = 0;
    this -> vorpalSwords = 0;

    //Number armor suits
    this -> armorSuits = 0; 

    //Treasures found
    this -> silverRings = 0; 
    this -> rubyNecklaces = 0; 
    this -> emeraldBracelets = 0; 
    this -> diamondCirclets = 0; 
    this -> gemGoblets = 0; 

    //Player name
    this -> name = "Player";

    this -> combatScore = 0;

}

//Parameterized constructor
Player::Player(std::string name)
{
    this -> fullness = 50;
    this -> gold = 100;
    this -> ingredients = 0;

    //cookware
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 0;

    //weapons
    this -> stoneClubs = 0;
    this -> ironSpears = 0;
    this -> mythrilRapiers = 0;
    this -> flamingAxes = 0;
    this -> vorpalSwords = 0;

    this -> numWeapons = 0;

    //Number armor suits
    this -> armorSuits = 0; 

    //Treasures found
    this -> silverRings = 0; 
    this -> rubyNecklaces = 0; 
    this -> emeraldBracelets = 0; 
    this -> diamondCirclets = 0; 
    this -> gemGoblets = 0; 

    //Player name
    this -> name = name;

    //Player keys
    this -> numKeys = 0;
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

//Adds new team member
void Player::addNewMember(std::string name)
{
    teamMembers[name] = 50;
}

//Returns hashmap of team members
std::map<std::string, int> Player::getTeamMembersMap()
{
    return teamMembers;
}

//Getters
int Player::getFullness()
{
    return fullness;
}

int Player::getGold()
{
    return gold;
}

int Player::getIngredients()
{
    return ingredients;
}

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

int Player::getNumKeys()
{
    return numKeys;
}

int Player::getNumWeapons()
{
    return numWeapons;
}

std::string Player::getName()
{
    return name;
}

int Player::getMemberHungerLevel(std::string member)
{
    return teamMembers[member];
}

//Setters

void Player::setFullness(int fullness)
{
    this -> fullness = fullness;
}

void Player::setGold(int gold)
{
    this -> gold = gold;
}

void Player::setIngredients(int ingredients)
{
    this -> ingredients = ingredients;
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

void Player::setNumKeys(int numKeys)
{
    this -> numKeys = numKeys;
}

void Player::setNumWeapons(int numWeapons)
{
    this -> numWeapons = numWeapons;
}

void Player::setName(std::string name)
{
    this -> name = name;
}

void Player::setMemberHungerLevel(std::string member, int level)
{
    teamMembers[member] = level;
}

//Incremental methods

//Increments the fullness of the player
void Player::incrementFullness()
{
    this -> fullness ++;
}

//Decrements the fullness of the player
void Player::decrementFullness()
{
    this -> fullness --;
}

void Player::incrementKeys()
{
    this -> numKeys ++;
}

void Player::decrementKeys()
{
    this -> numKeys --;
}

void Player::incrementMemberHungerLevel(std::string member)
{
    teamMembers[member] ++;
}

void Player::decrementMemberHungerLevel(std::string member)
{
    teamMembers[member] --;
}


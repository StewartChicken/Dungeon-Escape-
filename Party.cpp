#include "Party.h"
#include <iostream>
#include "time.h"

//Default constructor
Player::Player()
{

    //Party default names
    this -> partyNames[0] = "Player";
    this -> partyNames[1] = "Member1";
    this -> partyNames[2] = "Member2";
    this -> partyNames[3] = "Member3";
    this -> partyNames[4] = "Member4";

    this -> isMemberAlive[0] = true;
    this -> isMemberAlive[0] = true;
    this -> isMemberAlive[0] = true;
    this -> isMemberAlive[0] = true;

    //Party default combat values
    
    //weapons
    this -> numWeapons = 0;
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

    this -> gold = 100;
    this -> numKeys = 99;
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

void Player::hungerMisfortune(int chances){
    srand(time(0));
    int chaos[5];
    for(int i=0;i < 5; i++){
        chaos[i] = rand() % chances;
    }

    if(chaos[0]<20){
        decrementFullness(getPlayerName());   
    }
    if(chaos[1]<20){
        decrementFullness(getMember1Name());  
    }
    if(chaos[2]<20){
        decrementFullness(getMember2Name());  
    }
    if(chaos[3]<20){
        decrementFullness(getMember3Name());  
    }
    if(chaos[4]<20){
        decrementFullness(getMember4Name());  
    }

}
void Player::incrementTreasure(int roomsCleared){
    switch(roomsCleared){
        case 0:
            this -> silverRings ++;
        break;
        case 1:
            this -> rubyNecklaces ++;
        break;
        case 2:
            this -> emeraldBracelets ++;
        break;
        case 3:
            this -> diamondCirclets ++;
        break;
        case 4:
            this -> gemGoblets ++;
        break;
    }
} 
bool Player::investigate(int roomsCleared){
    srand(time(0));
    int chaos = rand() % 100;
    //std::cout<<chaos<<std::endl;
    if (chaos<20){
        incrementTreasure(roomsCleared);
    }else if (chaos<30){
        incrementKeys();
    }else if(chaos<50){
        return true;
    }
    hungerMisfortune(40);
    return false;
}
//chosses cookware, 1 through 3
/*
1.) ceramic pot
2.) frying pan
3.) cauldron
*/
bool Player::cookedSuccessfully(int cookingWith){
    bool success = false;
    srand(time(0));
    int chaos = rand() % 100;
    switch(cookingWith){
        case 1:
            if(getCeramicPots()<=0){
                std::cout<<"Please cook with an item you actually have\n";
                break;
            }else if(chaos<25){
                setCeramicPots(getCeramicPots()-1);

            }else {
                success=true;
            }
        break;
        case 2:
            if(getFryingPans()<=0){
                std::cout<<"Please cook with an item you actually have\n";
                break;
            }else if(chaos<10){
                setFryingPans(getFryingPans()-1);
            }else {
                success=true;
            }
        break;
        case 3:
            if(getCauldrons()<=0){
                std::cout<<"Please cook with an item you actually have\n";
                break;
            }else if(chaos<2){
                setCauldrons(getCauldrons()-1);
            }else {
                success = true;
            }
        break;
    }
    return success;
}
//prompt by serving size
//Player::cookFood function definition
//Cooks food in incrememnts of 5 kg since there are 5 team members
//The input argument is the number of servings that will be cooked
// total food cooked will be servings * 5
//Successful cooks will increase fullness by 1 for each team member
//If the pot breaks, cook fails and the food is lost
//Returns void
void Player::cookFood(int servings,int cookingWith)
{
    int fullness_earned = 0;
    for(int i = 0; i<servings; i++){
        setIngredients(getIngredients()-5);
        fullness_earned++;
    }
    if(cookedSuccessfully(cookingWith)){
        setFullnessLevel(getPlayerName(), getFullness(getPlayerName())+fullness_earned);
        setFullnessLevel(getMember1Name(), getFullness(getMember1Name())+fullness_earned);
        setFullnessLevel(getMember2Name(), getFullness(getMember2Name())+fullness_earned);
        setFullnessLevel(getMember3Name(), getFullness(getMember3Name())+fullness_earned);
        setFullnessLevel(getMember4Name(), getFullness(getMember4Name())+fullness_earned);
    }
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
int Player::countNumWeapons()
{
    return stoneClubs + ironSpears + mythrilRapiers + flamingAxes + vorpalSwords;
}

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
double Player::calculateCombatScore(int roomsCleared)
{

    srand(time(0));

    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;

    int w = countNumWeapons() + mythrilRapiers + 2 * flamingAxes + 3 * vorpalSwords;

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

    if(a == 0)
    {
        return 0;
    }

    int c; //Monster challenge rating

    switch(roomsCleared)
    {
        case 0:
            c = 2;
            break;
        case 1:
            c = 3;
            break;
        case 2:
            c = 4;
            break;
        case 3:
            c = 5;
            break;
        case 4:
            c = 6;
            break;
        default:
            break;
    };

    return (r1 * w + d) - double(r2 * c) / double(a);

}

//Determins if player wins fight against monster based on their combat score
bool Player::winsFight(double combatScore)
{
    return combatScore > 0 ? true : false;
}

//If player wins fight against monster
void Player::winFight(double challengeRating)
{
    srand(time(0));

    int keyChance = rand() % 10;

    setGold((challengeRating * 10) + gold);
    setIngredients((challengeRating * 5) + ingredients);

    if(keyChance == 0)
    {
        incrementKeys();
    }
}

//If player loses fight against monster
void Player::loseFight()
{
    srand(time(0));

    //Loses 25% of their gold
    setGold(int(double(gold) * 0.75));

    //Loses up to 30 kg of ingredients
    if(ingredients < 30)
    {
        setIngredients(0);
    }
    else
    {
        setIngredients(ingredients - 30);
    }

    //Loops through every NPC that has an armor suit - skips player
    for(int i = 1; i < armorSuits; i ++)
    {
        int deathChance = rand() % 20;

        if(deathChance == 0)
        {
            fullnessLevels[partyNames[i]]  = 0;
        }
    }

    //Loops through every teammember that doesn't have an armor suit - skips player
    for(int i = armorSuits; i < 5; i ++)
    {
        //If no armor suits were purchased
        if(i == 0)
        {
            continue;
        }

        int deathChance = rand() % 10;

        //10% chance of teammember dying
        if(deathChance == 0)
        {
            fullnessLevels[partyNames[i]]  = 0;
        }
    }
}

void Player::surrenderTeamMember()
{
    for(int i = 3; i >= 0; i --)
    {
        if(isMemberAlive[i])
        {
            isMemberAlive[i] = false;
            //setFullnessLevel();
            partyNames[i + 1] = partyNames[i + 1] + " (Dead)";
            std::cout << partyNames[i + 1] << " Has been sacrificed to the monster. R.I.P.\n";
            return;
        }
    }

    std::cout << "All Team Members are dead.\n";
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
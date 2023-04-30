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

    //Are the members alive?
    this -> isMemberAlive[0] = true;
    this -> isMemberAlive[1] = true;
    this -> isMemberAlive[2] = true;
    this -> isMemberAlive[3] = true;

    //Party default combat values
    
    //weapons
    this -> stoneClubs = 0;
    this -> ironSpears = 0;
    this -> mythrilRapiers = 0;
    this -> flamingAxes = 0;
    this -> vorpalSwords = 1;
    
    //Armor
    this -> armorSuits = 5; 

    this -> combatScore = 0;

    //Sorcerer variables
    this -> sorcererAngerLevel = 0;
    this -> sorcererDefeated = false;

    //Stats
    this -> monstersDefeated = 0;
    this -> gameScore = 0;
    this -> turnsElapsed = 0;

    //cookware
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 10;


    //Party default inventory values

    this -> gold = 100;
    this -> numKeys = 0;
    this -> ingredients = 0;


    //Treasures found
    this -> silverRings = 0; 
    this -> rubyNecklaces = 0; 
    this -> emeraldBracelets = 0; 
    this -> diamondCirclets = 0; 
    this -> gemGoblets = 0;
    this -> imaginaryGlasses = 0;

    this -> endCode = 0;
    this -> playerQuit = false; //Has the player quit?

    //End game statements
    this -> endgameArray[0]="You have died from hunger.\n\n GAME OVER!\n\n\n";
    this -> endgameArray[1]="You have upset the sorcer.\n\n GAME OVER!\n\n\n";
    this -> endgameArray[2]="You have died from food poisoning.\n\n GAME OVER!\n\n\n";
    this -> endgameArray[3]="You have no remaining companions.\n\n GAME OVER!\n\n\n";
    this -> endgameArray[4]="You have Escaped the Dungeon.\n\n YOU WIN!\n\n\n";
    this -> endgameArray[5]="You gave up. *Loser* (don't get butthurt pls)\n\n GAME OVER!\n\n\n";
}


//Player and team member name/hunger management methods

//Adds new party member
bool Player::addNewMember(std::string name, int index)
{
    //Checks if user input name is a duplicate
    if(!isTakenName(name))
    {
        this -> fullnessLevels[name] = 50;
        partyNames[index] = name;
        return true;
    }
    else
    {
        //Duplicate name warning
        cout << "You cannot enter the same name twice!\n";
        return false;
    }
}

//Ensures user can't enter the same name for team mates
bool Player::isTakenName(string name)
{
    for(int i = 0; i < 5; i ++)
    {
        //Compare names
        if(compareStrings(name, partyNames[i]))
        {
            return true;
        }
    }

    return false;
}

//Checks if a given name is a team member and not the player
bool Player::isTeamMember(string name)
{
    for(int i = 1; i < 5; i ++)
    {
        if(compareStrings(name, partyNames[i]))
        {
            return true;
        }
    }

    return false;
}

//Adjust fullness level for specific party member
void Player::setFullnessLevel(string name, int fullness)
{
    //Max fullness level is 50
    if(fullness >= 50)
    {
        cout << name << " is full.\n";
        this -> fullnessLevels[name] = 50;
    }
    //Min fullness level is 0
    else if(fullness <= 0)
    {
        this -> fullnessLevels[name] = -1;
 
        //Iterates through each party name (skipping player) and finds the index within partyNames that matches
        // uses this index to kill player that died of starvation
        for(int i = 0; i < 4; i ++)
        {
            if(compareStrings(name, partyNames[i + 1]))
            {
                isMemberAlive[i] = false;
                return;
            }
        }
    }
    else
    {
        this -> fullnessLevels[name] = fullness;
    }
    
}

//Getters

int Player::getFullness(string partyMember)
{
    return fullnessLevels[partyMember];
}

//Get specific party members' names - returns as strings
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
    //Max fullness is 50 - can only increment if fullness level is less than 50
    if(fullnessLevels[partyMember] <= 50)
    {
        this -> fullnessLevels[partyMember] ++;
    }
    else
    {
        this -> fullnessLevels[partyMember] = 50;
        cout << partyMember << " is full.\n";
    }
}

//Decrements the fullness of the player
void Player::decrementFullness(string partyMember)
{
    //Player dies from hunger if fullness level is less than 1
    if(fullnessLevels[partyMember] <= 0) //S
    {
        this -> fullnessLevels[partyMember] = -1;
        cout << partyMember << " has died from hunger.\n";

        //Iterates through each party name (skipping player) and finds the index within partyNames that matches
        // uses this index to kill player that died of starvation
        for(int i = 0; i < 4; i ++)
        {
            if(compareStrings(partyMember, partyNames[i + 1]))
            {
                isMemberAlive[i] = false;
                return;
            }
        }
    }
    this -> fullnessLevels[partyMember] --;
}

//After every monster fight, each team member has a 50 percent chance of losing a fullness level
void Player::monsterFightDecrementFullness()
{
    //Random seed
    srand(time(0));

    //Iterate through every team member
    for(int i{}; i < 5; i++)
    {
        //Random number between 0 and 1
        int chance = rand() % 2;

        //50% chance to decrement fullness
        if(chance == 0)
        {
            decrementFullness(partyNames[i]);
        }
    }
}

//Random hunber misfortune - each player has a 50 percent chance of losing a fullness level (assuming the input is 40)
void Player::hungerMisfortune(int chances){

    //Random seed
    srand(time(0));

    //Array of 5 random numbers
    int chaos[5];

    for(int i=0;i < 5; i++){
        chaos[i] = rand() % chances;
    }

    //20% chance to decrement fullness - independent for each team member
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

//Increment treasure depending on how many rooms were cleared
void Player::incrementTreasure(int roomsCleared){
    switch(roomsCleared){
        //0 rooms cleared
        case 0:
            this -> silverRings ++;
        break;
        //1 room cleared
        case 1:
            this -> rubyNecklaces ++;
        break;
        //2 rooms cleared
        case 2:
            this -> emeraldBracelets ++;
        break;
        //3 rooms cleared
        case 3:
            this -> diamondCirclets ++;
        break;
        //4 rooms cleared
        case 4:
            this -> gemGoblets ++;
        break;
    }
} 

//Game with the door that the player plays if they don't have keys
//1 - Boulder
//2 - Parchment
//3 - Shears
bool Player::winsDoorTrapGame(int playerChoice, int doorChoice)
{

    //If tie, player loses
    if(playerChoice == doorChoice)
    {
        return false;
    }

    //Door win scenarios
    if(doorChoice == 3 && playerChoice == 2)
    {
        return false;
    }

    if(doorChoice == 2 && playerChoice == 1)
    {
        return false;
    }

    if(doorChoice = 1 && playerChoice == 3)
    {
        return false;
    }
    
    //If door doesn't win or tie, player wins
    return true;
}

//Investigate an unexplored space
bool Player::investigate(int roomsCleared)
{

    //Random seed
    srand(time(0));

    //Random number between 0 and 99
    int chaos = rand() % 100;

    bool monsterFight = false; // Monster fight is not active at the start

    if (chaos < 20) //20 percent chance of a treasure
    {
        incrementTreasure(roomsCleared);
    }
    else if (chaos < 30) //20 percent chance of a key
    {
        incrementKeys();
    }
    else if(chaos < 50) //20 percent of a monster fight
    {
        monsterFight = true;
    }

    //If there is no monster fight - hunger misfortune
    if(!monsterFight)
    {
        hungerMisfortune(40);
    }

    return monsterFight; //Returns whether or not there was a monster fight
}

//chooses cookware, 1 through 3
/*
1.) ceramic pot
2.) frying pan
3.) cauldron
*/

//Was the food cooked successfully? (Depends on which cookware is used)
 bool Player::cookedSuccessfully(int cookingWith){

    bool success = false;
    srand(time(0));
    int chaos = rand() % 100;

    switch(cookingWith){
        case 1:
            if(chaos<25){ //Breaks pot with 25 percent chance
                setCeramicPots(getCeramicPots()-1);

            }else {
                success=true;
            }
            break;
        case 2:
            if(chaos<10){ //Breaks pan with 10 percent chance
                setFryingPans(getFryingPans()-1);
            }else {
                success=true;
            }
            break;
        case 3:
            if(chaos<2){ //Breaks cauldron with 2 percent chance
                setCauldrons(getCauldrons()-1);
            }else {
                success = true;
            }
            break;
        default:
            cout << "ERROR - cookedSuccessfully\n"; //Error code - should not reach this case
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
    //Increase fullness for each serving
    if(cookedSuccessfully(cookingWith)){

        cout << "Meal was cooked successfully.\n";

        setFullnessLevel(getPlayerName(), getFullness(getPlayerName())+fullness_earned);
        setFullnessLevel(getMember1Name(), getFullness(getMember1Name())+fullness_earned);
        setFullnessLevel(getMember2Name(), getFullness(getMember2Name())+fullness_earned);
        setFullnessLevel(getMember3Name(), getFullness(getMember3Name())+fullness_earned);
        setFullnessLevel(getMember4Name(), getFullness(getMember4Name())+fullness_earned);
    }
    else
    {
        cout << "Your cook failed! Ingredients were lost.\n";
    }
}

//Inventory methods


//Getters

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

//Setters

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

//Increment/Decrement

void Player::incrementKeys()
{
    this -> numKeys ++;
}

void Player::decrementKeys()
{

    //numKeys cannot be negative
    if(numKeys > 0)
    {
        this -> numKeys --;
        return;
    }

    numKeys = 0;
}

void Player::incrementImaginaryGlasses()
{
    this -> imaginaryGlasses ++;
} 


//Combat methods
int Player::countNumWeapons() //Total number of weapons on team
{
    return stoneClubs + ironSpears + mythrilRapiers + flamingAxes + vorpalSwords;
}

//Getters

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

//Setters

void Player::setStoneClubs(int clubs)
{
    //Cannot have negative value
    if(clubs <= 0)
    {
        this -> stoneClubs = 0;
        return;
    }

    this -> stoneClubs = clubs;
}

void Player::setIronSpears(int spears)
{
    //Cannot have negative value
    if(spears <= 0)
    {
        this -> ironSpears = 0;
        return;
    }
    this -> ironSpears = spears;
}

void Player::setMythrilRapiers(int rapiers)
{
    //Cannot have negative value
    if(rapiers <= 0)
    {
        this -> mythrilRapiers = 0;
        return;
    }

    this -> mythrilRapiers = rapiers;
}

void Player::setFlamingAxes(int axes)
{
    //Cannot have negative value
    if(axes <= 0)
    {
        this -> flamingAxes = 0;
        return;
    }

    this -> flamingAxes = axes;
}

void Player::setVorpalSwords(int swords)
{
    //Cannot have negative value
    if(swords <= 0)
    {
        this -> vorpalSwords = 0;
        return;
    }

    this -> vorpalSwords = swords;
}

void Player::setArmorSuits(int suits)
{
    //Cannot have negative value
    if(suits <= 0)
    {
        this -> armorSuits = 0;
        return;
    }

    this -> armorSuits = suits;
}

void Player::decrementArmorSuits()
{
    //Cannot have negative value
    if(armorSuits > 0)
    {
        this -> armorSuits --;
    }
}

//Party cannot have more than 5 armor suits - this function refunds user the gold spent on extra suits
int Player::checkArmorSuitCap(int numSuitsBought, int suitCost)
{
    if((numSuitsBought + armorSuits) > 5)
    {
        gold = gold + ((numSuitsBought + armorSuits) - 5) * suitCost; //Refunds user the money they spent on excess suits

        cout << "You can only have 5 armor suits at a time.\n";
        return 5;
    }

    return numSuitsBought + armorSuits;;
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

    int r1 = rand() % 6 + 1; //Random variation
    int r2 = rand() % 6 + 1;

    //weapon weighting
    int w = countNumWeapons() + mythrilRapiers + 2 * flamingAxes + 3 * vorpalSwords;

    //Calculate d - if every party member has a different weapon, d = 4. Otherwise, d = 0
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

    //If team has no armor, they lose the fight 
    if(a == 0) 
    {
        return 0;
    }

    int c; //Monster challenge rating

    switch(roomsCleared)
    {
        //0 rooms cleared
        case 0:
            c = 2;
            break;
        //1 room cleared
        case 1:
            c = 3;
            break;
        //2 rooms cleared
        case 2:
            c = 4;
            break;
        //3 rooms cleared
        case 3:
            c = 5;
            break;
        //4 rooms cleared
        case 4:
            c = 6;
            break;
        //Default case : should not reach this
        default:
            break;
    };

    //Return final combat score
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
    //Random seed
    srand(time(0));

    //Random number between 0 and 9
    int keyChance = rand() % 10;

    //Gives player gold and ingredients 
    setGold((challengeRating * 10) + gold);
    setIngredients((challengeRating * 5) + ingredients);

    //10% chance of getting a key
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

//Surrender team member to monster
void Player::surrenderTeamMember()
{
    //Loop through every team member to check which ones are alive
    for(int i = 3; i >= 0; i --)
    {
        //If member at this specific index is alive, surrender them to monster
        if(isMemberAlive[i])
        {
            isMemberAlive[i] = false;
            setFullnessLevel(partyNames[i + 1], -1);
            std::cout << partyNames[i + 1] << " Has been sacrificed to the monster. R.I.P.\n";
            return;
        }
    }

    //Should never print this - if all members are dead, should register it long before this method is ever called
    std::cout << "All Team Members are dead.\n";
}

//Lose a party member if the party member loses the game to the door
void Player::loseTeamMember()
{

    //Random  seed
    srand(time(0));
    
    //Member successfully removed from team
    bool successfulRemoval = false;
    
    while(!successfulRemoval)
    {
        //Random number between 1 and 4
        int removeIndex = (rand() % 4) + 1;

        //If member is alive, lose them to the depths of the dungeon
        if(isMemberAlive[removeIndex - 1])
        {
            std::cout << partyNames[removeIndex] << " Has been lost to the depths of the dungeon!\n";

            isMemberAlive[removeIndex - 1] = false;
            setFullnessLevel(partyNames[removeIndex], -1);

            successfulRemoval = true;
        }
    }
}

//Checks if entire team is dead
bool Player::wholeTeamDead()
{
    //If any team member is alive, return false
    for(int i = 0; i < 4; i++)
    {
        if(isMemberAlive[i])
        {
            return false;
        }
    }

    return true;
}

//Count number of presently living team members
int Player::getNumSurvivingTeamMembers()
{
    int count = 0;

    for(int i; i < 4; i ++)
    {
        if(isMemberAlive[i])
        {
            //Increment count
            count ++;
        }
    }

    return count;
}
//Sorcerer anger level methods

int Player::getSorcererAngerLevel()
{
    return sorcererAngerLevel;
}

void Player::setSorcererAngerLevel(int level)
{
    sorcererAngerLevel = level;
}

void Player::incrementSorcererAnger()
{
    if(!sorcererDefeated)
    {
        sorcererAngerLevel ++;
    }
}

//Changes sorcerer defeat status to true
void Player::defeatSorcerer()
{
    sorcererDefeated = true;
}

//Checks if the sorcerer is defeated
bool Player::isSorcererDefeated()
{
    return sorcererDefeated;
}

//Number of monsters defeated
int Player::getMonstersDefeated()
{
    return monstersDefeated;
}

//Changes the number of monsters defeated
void Player::setMonstersDefeated(int number)
{
    monstersDefeated = number;
}

//Increment the number of monsters defeated by 1
void Player::incrementMonstersDefeated()
{
    monstersDefeated ++;
}

//Game score methods

int Player::getGameScore()
{
    return gameScore;
}

void Player::setGameScore(int score)
{
    gameScore = score;
}

int Player::getTurnsElapsed()
{
    return turnsElapsed;
}

void Player::setTurnsElapsed(int turns)
{
    turnsElapsed = turns;
}

void Player::incrementTurnsElapsed()
{
    turnsElapsed ++;
}


//Cookware methods

//Getters

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

//Setters

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

//Misfortune : hippies stole some of your cookware
void Player::cookwareTheft(){

    //Random seed
    srand(time(0));

    //Random number between 0 and 2 - 0 = ceramic pot, 1 = frying pan, 2 = cauldron
    int chaos = rand() % 3;

    std::cout<<"You come back to your campsite to find Dirty Hippies actively rummaging through your stuff.";

    //Ceramic pots chosen at random - they take precedence 
    if(chaos==0){
        if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one ceramic pot\n";
        //If no ceramic pots
        }else if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        //If no frying pans
        }else if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        //Nothing to steal
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    //Frying pans chosen at random - they take precedence
    }else if (chaos==1){
        if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        //If no frying pans found
        }else if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        //If no ceramic pots found
        }else if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        //Nothing to steal
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    //Cauldrons chosen at random - they take precedence
    }else if (chaos==2){
        if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        //If no cauldrons found
        }else if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        //If no frying pans found
        }else if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one ceramic pot\n";
        //Nothing to steal
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    }
}

//Misfortune : robbed
void Player::robbed(){

    //Random seed
    srand(time(0));

    //Random number between 0 and 2
    int chaos = rand() % 3;

    //Ingredients stolen by hobbits
    if(chaos==0){
        std::cout<<"While you were destracted, feral hobbits snuck into your reserves and stole some food!\n\n You have lost 10kg of ingredients.\n";
        if(getIngredients() > 0 && getIngredients() < 10)
        {
            setIngredients(0);
        //No ingredients to be stolen
        }else if(getIngredients() == 0)
        {
            std::cout << "The hobbots were shocked by your lack of food and called you a peasant before waddling into the distance\n";
        }else{
            setIngredients(getIngredients()-10);
        }
    //Armor stolen by bandits
    }else if (chaos==1){
        std::cout<<"You are held at sword tip by bandits!\n\nYou have lost 1 suit of armor.\n";
        if(getArmorSuits() > 0)
        {
            decrementArmorSuits();
        }
    //Cookware stolen
    }else if (chaos==2){
        cookwareTheft();
    }
}

//Misfortune : broken
void Player::broken(){

    //Randmo seed
    srand(time(0));

    //Random number between 0 and 5
    int chaos = rand() % 6;

    //Affected item
    std::string item;

    //Stolen club broken
    if(chaos==0){
        setStoneClubs(getStoneClubs()-1);
        item = "stone club";
    //Iron spear broken
    }else if (chaos==1){
        setIronSpears(getIronSpears()-1);
        item = "iron spear";
    //Mythril Rapier broken
    }else if (chaos==2){
        setMythrilRapiers(getMythrilRapiers()-1);
        item = " myhtril rapier";
    //Flaming axe broken
    }else if(chaos==3){
        setFlamingAxes(getFlamingAxes()-1);
        item = "flaming axe";
    //Vorpal sword broken
    }else if(chaos==4){
        setVorpalSwords(getVorpalSwords()-1);
        item = "vorpal sword";
    //Armor suit broken
    }else if(chaos==5){
        setArmorSuits(getArmorSuits()-1);
        item = "armor suit";
    }

    //Lost item message
    std::cout<<"You have lost 1 "<<item<<".\n";
}

//Misfortune : poisioned
void Player::poisoned(){

    //Random seed
    srand(time(0));

    //Random number between 0 and 5
    int chaos=rand()%5;

    //Name of affected team member
    std::string name;

    //Randomly select a team member
    if(chaos==0){
        name=getPlayerName();
    }else if(chaos==1){
        name=getMember1Name();
    }else if(chaos==2){
        name=getMember2Name();  
    }else if(chaos==3){
        name=getMember3Name();
    }else if(chaos==4){
        name=getMember4Name();
    }
    //If player/team member alive, subtract 10 from fullness
    if(getFullness(name)>=0)
    {
        setFullnessLevel(name, getFullness(name)-10);
    //Player or team member is dead, recursively call poisioned()
    }else{
        poisoned();
    }
    //Checks if the poisoning has resulted in a death of either the player or a team member
    if(getFullness(name)<=0){
        if(name==getPlayerName()){
            std::cout<<"You have died from food poisoning!\n";
            setEndCode(2);
        }else{
        std::cout<<name<<" has died from food poisoning! "<< getNumSurvivingTeamMembers() <<" players remain.\n";
        }
    //Player/team member hasn't died, just lost 10 fullness points
    }else{
        if(name==getPlayerName()){
            std::cout<<"You have lost 10 fullness to food poisoning!\n";

        }else{
        std::cout<<name<<" has lost 10 fullness to food poisoning!\n";
        }
    }
}

//Lose team member to a locked room
void Player::locked(){

    //Random seed
    srand(time(0));

    //Random number betwen 0 and 3
    int chaos = rand() % 4;

    //Affected player or team member
    std::string name;

    //Select a random team member at random
    if(chaos == 0 ){
        name=getMember1Name();
    }else if(chaos == 1){
        name=getMember2Name();
    }else if(chaos == 2){
        name=getMember3Name();
    }else if(chaos == 3){
        name=getMember4Name();
    }
    
    //If the selected player is alive, they are locked in the previous room and killed
    if(getFullness(name)>=0){
        std::cout<<name<<" has been locked in the previous room.\n";
        setFullnessLevel(name, -1);
    }else{

        //If the selected player is dead, recursively call the locked() function
        locked();
    }
}

//Misfortune function:
//party can be robbed, poisoned, have their equipment broken, or lose a member (locked in previous room)
void Player::misfortunes(bool entering_a_room, Map &map){

    //Random seed
    srand(time(0));

    //Random number between 0 and 199
    int chaos=rand()%200;

    //15% chance of being robbed
    if(chaos<30){
        robbed();
    //5% chance of having an item break
    }else if (chaos<40){
        broken();
    //15% chance of being poisoned
    }else if (chaos<70){
        poisoned();
    //15% chance of member being locked in a room, if the party is presently entering a room
    }else if (chaos<100&&entering_a_room){
        locked();
    }
}

//End game methods
int Player::getEndCode(){
    return endCode;
}
void Player::setEndCode(int code){
    this -> endCode = code;
}

void  Player::endgamePrompt(int index){
    std::cout<<endgameArray[index];
}

//Player quits game
void Player::quit()
{
    endCode = 5;
    playerQuit = true;
}

bool Player::hasQuit()
{
    return playerQuit;
}

//Compares two strings
bool Player::compareStrings(string a, string b)
{
    if(a.length() != b.length())
    {
        return false;
    }

    for(int i=0; i < a.length(); i ++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    return true;

}
//Add To Inventory
//adds the quauntity of a selected item to the player's inventory
void Player::addToInventory(string item, int itemCount, int price){
    if (item == "kg(s) of Ingredients"){
        setIngredients(getIngredients() + itemCount);//Update user inventory
    }else if (item == "Armor suit(s)"){
        setArmorSuits(checkArmorSuitCap(itemCount,price)); 
    }else if (item == "Ceramic pots"){
        setCeramicPots(getCeramicPots() + itemCount);
    }else if (item == "Frying pans"){
        setFryingPans(getFryingPans() + itemCount);
    }else if (item == "Cauldrons"){
        setCauldrons(getCauldrons() + itemCount);
    }else if (item ==  "Stone club(s)"){
        setStoneClubs(getStoneClubs() + itemCount);
    }else if (item == "Iron spear(s)"){
        setIronSpears(getIronSpears() + itemCount);
    }else if (item == "Mythril Rapier(s)"){
        setMythrilRapiers(getMythrilRapiers() + itemCount);
    }else if (item == "Battle Axe(s)"){
        setFlamingAxes(getFlamingAxes() + itemCount);
    }else if (item == "Vorpal Sword(s)"){
        setVorpalSwords(getVorpalSwords() + itemCount);
    }
}

int Player::getTotalWeapons(){
    int total = getStoneClubs()+getIronSpears()+getMythrilRapiers()+getFlamingAxes()+getVorpalSwords();
    return total;
}

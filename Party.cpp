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

    this -> sorcererAngerLevel = 95;
    this -> sorcererDefeated = false;

    this -> monstersDefeated = 0;
    this -> gameScore = 0;

    //cookware
    this -> ceramicPots = 0;
    this -> fryingPans = 0;
    this -> cauldrons = 0;


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
void Player::addNewMember(std::string name, int index)
{
    this -> fullnessLevels[name] = 50;
    partyNames[index] = name;
}

//Adjust fullness level for specific party member
void Player::setFullnessLevel(string name, int fullness)
{
    if(fullness >= 50)
    {
        cout << name << " is full.\n";
        this -> fullnessLevels[name] = 50;
    }
    else if(fullness <= 0)
    {
        this -> fullnessLevels[name] = -1;
        cout << name << " has died from hunger.\n";
        return;
    }
    else
    {
        this -> fullnessLevels[name] = fullness;
    }
    
}

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
    if(fullnessLevels[partyMember] <= 0)
    {
        this -> fullnessLevels[partyMember] = -1;
        cout << partyMember << " has died from hunger.\n";

        return;
    }

    this -> fullnessLevels[partyMember] --;
}

//After every monster fight, each team member has a 50 percent chance of losing a fullness level
void Player::monsterFightDecrementFullness()
{
    srand(time(0));

    for(int i{}; i < 5; i++)
    {
        int chance = rand() % 2;

        if(chance == 0)
        {
            decrementFullness(partyNames[i]);
        }
    }
}

//Random hunber misfortune - each player has a 50 percent chance of losing a fullness level (assuming the input is 40)
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

//Increment treasure depending on how many rooms were cleared
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

//Game with the door that the player plays if they don't have keys
//1 - Boulder
//2 - Parchment
//3 - Shears
bool Player::winsDoorTrapGame(int playerChoice, int doorChoice)
{
    if(playerChoice == doorChoice)
    {
        return false;
    }

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
    
    return true;
}

//Investigate an unexplored space
bool Player::investigate(int roomsCleared)
{

    srand(time(0));
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
            cout << "ERROR - cookedSuccessfully\n"; //Error code
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

void Player::decrementArmorSuits()
{
    this -> armorSuits --;
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

//Surrender team member to monster
void Player::surrenderTeamMember()
{
    for(int i = 3; i >= 0; i --)
    {
        if(isMemberAlive[i])
        {
            isMemberAlive[i] = false;
            setFullnessLevel(partyNames[i + 1], -1);
            std::cout << partyNames[i + 1] << " Has been sacrificed to the monster. R.I.P.\n";
            return;
        }
    }

    std::cout << "All Team Members are dead.\n";
}

//Lose a party member if the party member loses the game to the door
void Player::loseTeamMember()
{

    srand(time(0));
    
    bool successfulRemoval = false;
    
    while(!successfulRemoval)
    {
        int removeIndex = (rand() % 4) + 1;
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
    for(int i = 0; i < 4; i++)
    {
        if(isMemberAlive[i])
        {
            return false;
        }
    }

    return true;
}

int Player::getNumSurvivingTeamMembers()
{
    int count = 0;

    for(int i; i < 4; i ++)
    {
        if(isMemberAlive[i])
        {
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

int Player::getMonstersDefeated()
{
    return monstersDefeated;
}

void Player::setMonstersDefeated(int number)
{
    monstersDefeated = number;
}

void Player::incrementMonstersDefeated()
{
    monstersDefeated ++;
}

int Player::getGameScore()
{
    return gameScore;
}

void Player::setGameScore(int score)
{
    gameScore = score;
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
void Player::cookwareTheft(){
    srand(time(0));
    int chaos = rand() % 3;
    std::cout<<"You come back to your campsite to find Dirty Hippies actively rummaging through your stuff.";
    if(chaos==0){
        if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one ceramic pot\n";
        }else if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        }else if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    }else if (chaos==1){
        if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        }else if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        }else if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    }else if (chaos==2){
        if(getCauldrons() > 0)
        {
            setCauldrons(getCauldrons() - 1);
            cout << " You chase them off before they can take much.\n\nYou have lost one cauldron\n";
        }else if(getFryingPans() > 0)
        {
            setFryingPans(getFryingPans() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one frying pan\n";
        }else if(getCeramicPots() > 0)
        {
            setCeramicPots(getCeramicPots() - 1);
            std::cout << " You chase them off before they can take much.\n\nYou have lost one ceramic pot\n";
        }else{
            cout << " They took nothing because there was nothing to take...\n\n";
        }
    }
}

void Player::robbed(){
    srand(time(0));
    int chaos = rand() % 3;
    if(chaos==0){
        std::cout<<"While you were destracted, feral hobbits snuck into your reserves and stole some food!\n\n You have lost 10kg of ingredients.\n";
        if(getIngredients() > 0 && getIngredients() < 10)
        {
            setIngredients(0);
        }else if(getIngredients() == 0)
        {
            std::cout << "The hobbots were shocked by your lack of food and called you a peasant before waddling into the distance\n";
        }else{
            setIngredients(getIngredients()-10);
        }
    }else if (chaos==1){
        std::cout<<"You are held at sword tip by bandits!\n\nYou have lost 1 suit of armor.\n";
        if(getArmorSuits() > 0)
        {
            decrementArmorSuits();
        }
    }else if (chaos==2){
        cookwareTheft();
    }
}

void Player::broken(){
    srand(time(0));
    int chaos = rand() % 6;
    std::string item;
    if(chaos==0){
        setStoneClubs(getStoneClubs()-1);
        item = "stone club";
    }else if (chaos==1){
        setIronSpears(getIronSpears()-1);
        item = "iron spear";
    }else if (chaos==2){
        setMythrilRapiers(getMythrilRapiers()-1);
        item = " myhtril rapier";
    }else if(chaos==3){
        setFlamingAxes(getFlamingAxes()-1);
        item = "flaming axe";
    }else if(chaos==4){
        setVorpalSwords(getVorpalSwords()-1);
        item = "vorpal sword";
    }else if(chaos==5){
        setArmorSuits(getArmorSuits()-1);
        item = "armor suit";
    }
    std::cout<<"You have lost 1 "<<item<<".\n";
}

void Player::poisoned(){
    srand(time(0));
    int chaos=rand()%5;
    std::string name;
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
    if(getFullness(name)>=0){
    setFullnessLevel(name, getFullness(name)-10);
    }else{
        poisoned();
    }
    if(getFullness(name)<=0){
        if(name==getPlayerName()){
            std::cout<<"You have died from food poisoning!\n";
            setEndCode(1);
        }else{
        std::cout<<name<<" has died from food poisoning! "<< getNumSurvivingTeamMembers() <<" players remain.\n";
        }
    }else{
        if(name==getPlayerName()){
            std::cout<<"You have lost 10 fullness to food poisoning!\n";

        }else{
        std::cout<<name<<" has lost 10 fullness to food poisoning!\n";
        }
    }
}
void Player::locked(){
    srand(time(0));
    int chaos = rand() % 4;
    std::string name;
    if(chaos == 0 ){
        name=getMember1Name();
    }else if(chaos == 1){
        name=getMember2Name();
    }else if(chaos == 2){
        name=getMember3Name();
    }else if(chaos == 3){
        name=getMember4Name();
    }
    if(getFullness(name)>=0){
        std::cout<<name<<" has been locked in the previous room.\n";
        setFullnessLevel(name, -1);
    }else{
        locked();
    }
}
void Player::misfortunes(bool entering_a_room, Map &map){
    srand(time(0));
    int chaos=rand()%200;
    if(chaos<30){
        robbed();
    }else if (chaos<40){
        broken();
    }else if (chaos<70){
        poisoned();
    }else if (chaos<100&&entering_a_room){
        locked();
    }
}

int Player::getEndCode(){
    return endCode;
}
void Player::setEndCode(int code){
    this -> endCode = code;
}

void  Player::endgamePrompt(int index){
    std::cout<<endgameArray[index];
}

void Player::quit()
{
    endCode = 5;
    playerQuit = true;
}

bool Player::hasQuit()
{
    return playerQuit;
}
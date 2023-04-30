//TODO - 119 Infinite Loop

#include "Monster.h"

// Default constructor
Monster::Monster()
{
    // All monster names within the game
    monsterNames[0] = "Minotaur";
    monsterNames[1] = "Owlbear";
    monsterNames[2] = "Banshee";
    monsterNames[3] = "Wereboar";
    monsterNames[4] = "Wild Gerbil";
    monsterNames[5] = "Grounded Guy";
    monsterNames[6] = "Librarian";
    monsterNames[7] = "Tree Sapling";
    monsterNames[8] = "Giant Crocodile";
    monsterNames[9] = "Troll";
    monsterNames[10] = "Hobgoblin Warlord";
    monsterNames[11] = "Mammoth";
    monsterNames[12] = "Greg";
    monsterNames[13] = "Business Major";
    monsterNames[14] = "Asbestos Man";
    monsterNames[15] = "Clay Dude";
    monsterNames[16] = "Stone Giant";
    monsterNames[17] = "Night Hag";
    monsterNames[18] = "Assassin";
    monsterNames[19] = "Batman";
    monsterNames[20] = "Dirty Diaper";
    monsterNames[21] = "Jack Sparrow";
    monsterNames[22] = "Aghast Ghast";
    monsterNames[23] = "Mutant Tortoise";
    monsterNames[24] = "Cloud Giant";
    monsterNames[25] = "Silver Dragon";
    monsterNames[26] = "Vampire";
    monsterNames[27] = "Rick Sandwhich";
    monsterNames[28] = "Lich";
    monsterNames[29] = "Electricity Woman";
    monsterNames[30] = "Tom Brady";
    monsterNames[31] = "Darth Vader";
    monsterNames[32] = "Sorcerer";

    // Monster names and their difficulties
    Monsters["Minotaur"] = 2;
    Monsters["Owlbear"] = 2;
    Monsters["Banshee"] = 2;
    Monsters["Wereboar"] = 2;
    Monsters["Wild Gerbil"] = 2;
    Monsters["Grounded Guy"] = 2;
    Monsters["Librarian"] = 2;
    Monsters["Tree Sapling"] = 2;
    Monsters["Giant Crocodile"] = 3;
    Monsters["Troll"] = 3;
    Monsters["Hobgoblin Warlord"] = 3;
    Monsters["Mammoth"] = 3;
    Monsters["Greg"] = 3;
    Monsters["Business Major"] = 3;
    Monsters["Asbestos Man"] = 3;
    Monsters["Clay Dude"] = 3;
    Monsters["Stone Giant"] = 4;
    Monsters["Night Hag"] = 4;
    Monsters["Assassin"] = 4;
    Monsters["Batman"] = 4;
    Monsters["Dirty Diaper"] = 4;
    Monsters["Jack Sparrow"] = 4;
    Monsters["Aghast ghast"] = 4;
    Monsters["Mutant Tortoise"] = 4;
    Monsters["Cloud Giant"] = 5;
    Monsters["Silver Dragon"] = 5;
    Monsters["Vampire"] = 5;
    Monsters["Rick Sandwhich"] = 5;
    Monsters["Lich"] = 5;
    Monsters["Electricity Woman"] = 5;
    Monsters["Tom Brady"] = 5;
    Monsters["Darth Vader"] = 5;
    Monsters["Sorcerer"] = 6;

    // Creates room combat order
    generateCombatOrder();
}

//generateCombatOrder function definition
//Creates a random combat order for the monsters that the player will encounter 
// within each of the five rooms. Each room contains a stronger monster than the
// previous one. If a monster is found within a room, it cannot be fought anywhere
// outside of that room. 
//Returns void : only modifies the private data members of the class
void Monster::generateCombatOrder()
{
    // Random seed
    srand(time(0));

    // Defines four random monsters (excluding the final boss) for the combat order 
    for(int i = 0; i < 4; i ++)
    {
        int randMonster = rand() % 8;
        roomCombatOrder[i] = monsterNames[randMonster + (8 * i)];
    }

    // Final boss is the sorcerer
    roomCombatOrder[4] = monsterNames[32];
}

//getMonsterFromRoomCombatOrder function definition
//Returns the name of a monster depending on which room the player is in (numRoomsCleared)
string Monster::getMonsterFromRoomCombatOrder(int index)
{
    return roomCombatOrder[index];
}

//getRandomMonster function definition
//Returns the name of a random monster. The monster cannot exist within one of the rooms
// and the monster cannot have been previously defeated. The function calls itself
// recursively if any of the listed conditions are met
// parameter : int roomsCleared
// Return : string - name of the randomly selected monster
string Monster::getRandomMonster(int roomsCleared)
{

    srand(time(0));

    // Determines the difficulty of the monster that will be chosen. 
    int monsterMultiplier;

    //Prevents player from fighting sorcerer anywhere but within the final room
    if(roomsCleared >= 4)
    {
        monsterMultiplier = 3;
    }
    else
    {
        monsterMultiplier = roomsCleared;
    }

    // Random index depending on the difficulty
    int chosenMonsterIndex = (rand() % 8) + (8 * monsterMultiplier);
    std::cout<<"Chosen Monster Index\n"<<chosenMonsterIndex;

    // Name of the monster at the chosen index
    string chosenMonster = monsterNames[chosenMonsterIndex];

    // If the monster already exists within a room or has already been defeated, recall the function
    if(isInRoomCombatOrder(chosenMonster) || isDefeatedMonster(chosenMonster))
    {
        chosenMonster = getRandomMonster(roomsCleared); // Recursive function call
    }

    //Returns random monster name
    return chosenMonster;
}


//Return a specified monster's difficulty
int Monster::getMonsterDifficulty(string monsterName)
{
    return Monsters[monsterName];
}


//isInRoomCombatOrder function definition
//Checks to see if a given monster already exists within one of the rooms on the map
//Parameter : string - monsterName
//Return type : boolean
bool Monster::isInRoomCombatOrder(string monsterName)
{
    //Iterates through all the monsters within the all of the rooms
    for(string name : roomCombatOrder)
    {
        if(compareStrings(name, monsterName))
        {
            return true;
        }   
    }

    return false;
}

//isDefeatedMonster function definition
//Checks to see if a given monster has already been defeated by the player
//Parameter : string - monsterName
//Return type : boolean
bool Monster::isDefeatedMonster(string monsterName)
{
    //Iterates through every defeated monster and compares to the name passed as a parameter
    for(string defeatedMonster : defeatedMonsters)
    {
        if(compareStrings(monsterName, defeatedMonster))
        {
            return true;
        }
    }

    return false;
}

//killMonster function definition
//Adds the given monster to the "defeatedMonsters" vector
//Parameter : string - monsterName
//Return type : void
void Monster::killMonster(string monsterName)
{
    defeatedMonsters.push_back(monsterName);
}

//compareStrings function definition
//Compares two strings and determines if they are equal
//Parameter : string a, string b
//Return type : boolean
bool Monster::compareStrings(string a, string b)
{
    // Return false if the lengths of the strings are not equal
    if(a.length() != b.length())
    {
        return false;
    }

    // Return false if any of the characters are not equal
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i])
        {
            return false;
        }
    }

    // All cases passed - return true
    return true;
}

#include <iostream>
#include "Monster.h"

Monster::Monster()
{
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

    generateCombatOrder();
}

void Monster::generateCombatOrder()
{
    srand(time(0));

    for(int i = 0; i < 4; i ++)
    {
        int randMonster = rand() % 8;
        combatOrder[i] = monsterNames[randMonster + (8 * i)];
    }

    combatOrder[4] = monsterNames[32];
}

string Monster::getMonsterFromCombatOrder(int index)
{
    return combatOrder[index];
}
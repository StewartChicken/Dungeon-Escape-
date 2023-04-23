#include <iostream>
#include "Monster.h"

Monster::Monster()
{
    monsterNames[0] = "Minotaur";
    monsterNames[1] = "Owlbear";
    monsterNames[2] = "Banshee";
    monsterNames[3] = "Wereboar";
    monsterNames[4] = "Giant Crocodile";
    monsterNames[5] = "Troll";
    monsterNames[6] = "Hobgoblin Warlord";
    monsterNames[7] = "Mammoth";
    monsterNames[8] = "Stone Giant";
    monsterNames[9] = "Night Hag";
    monsterNames[10] = "Assassin";
    monsterNames[11] = "Hyrda";
    monsterNames[12] = "Cloud Giant";
    monsterNames[13] = "Silver Dragon";
    monsterNames[14] = "Vampire";
    monsterNames[15] = "Lich";
    monsterNames[16] = "Sorcerer";

    Monsters["Minotaur"] = 2;
    Monsters["Owlbear"] = 2;
    Monsters["Banshee"] = 2;
    Monsters["Wereboar"] = 2;
    Monsters["Giant Crocodile"] = 3;
    Monsters["Troll"] = 3;
    Monsters["Hobgoblin Warlord"] = 3;
    Monsters["Mammoth"] = 3;
    Monsters["Stone Giant"] = 4;
    Monsters["Night Hag"] = 4;
    Monsters["Assassin"] = 4;
    Monsters["Hydra"] = 4;
    Monsters["Cloud Giant"] = 5;
    Monsters["Silver Dragon"] = 5;
    Monsters["Vampire"] = 5;
    Monsters["Lich"] = 5;
    Monsters["Sorcerer"] = 6;
}

void Monster::generateCombatOrder()
{
    srand(time(0));

    for(int i = 0; i < 4; i ++)
    {
        int randMonster = rand() % 4;
        combatOrder[i] = monsterNames[randMonster + (4 * i)];
    }

    combatOrder[4] = monsterNames[16];
}

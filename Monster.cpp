#include <iostream>
#include "Monster.h"

Monster::Monster()
{
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";
    monsterNames[0] = "Minotaur";

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

        switch(randMonster)
        {
            case 0:
                combatOrder[i] = 
        };
    }
}
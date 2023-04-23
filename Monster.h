#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <time.h>

using std::map;
using std::string;

class Monster
{
    private:

        string monsterNames[17];
        string combatOrder[5]; // Order the player encounters monsters

        map<string, int> Monsters; // Monsters and their difficulties

    public:
        Monster();
 
        void generateCombatOrder(); //Generates random order for monster apperances

        int getCombatDifficulty(string);

};

#endif
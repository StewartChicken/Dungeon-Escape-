#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <vector>
#include <time.h>

using std::map;
using std::string;

class Monster
{
    private:

        string monsterNames[33];
        string roomCombatOrder[5]; // Order the player encounters monsters

        vector<string> defeatedMonsters;

        map<string, int> Monsters; // Monsters and their difficulties

    public:
        Monster();
 
        void generateCombatOrder(); //Generates random order for monster apperances

        string getMonsterFromRoomCombatOrder(int index);

        string getRandomMonster(int roomsCleared);
        bool isInRoomCombatOrder(string monsterName);
        bool isDefeatedMonster(string monsterName);

        void killMonster(string monsterName);

        bool compareStrings(string a, string b);

};

#endif
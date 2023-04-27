/**
 * @file Monster.h
 * @author Evan Poon and Wyatt Massey
 * 
 * This class contains all of the data for the Monsters within our game.
 * It will allow the game to randomly summon monsters of varying difficulty.
 * The difficulty is determined by the player's progression into the game. 
 * The class will also allow the game to track the death's of different monsters
 *  and will create a system for summoning a monsters within rooms or for
 *  random fights that the player encounters. 
 * 
 */

#ifndef MONSTER_H
#define MONSTER_H

//Inclusions
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

        string monsterNames[33]; // Every single monster within the game
        string roomCombatOrder[5]; // Order the player encounters monsters within the rooms. Final is the sorcerer

        vector<string> defeatedMonsters; // Vector containing all of the defeated monsters

        map<string, int> Monsters; // Monsters and their difficulties

    public:
        Monster(); // Default constructor
 
        void generateCombatOrder(); // Generates random order for monster apperances within rooms

        string getMonsterFromRoomCombatOrder(int index); // Gets a random monster from the room combat order        
                                                         // depending on which room the player is in

        string getRandomMonster(int roomsCleared);  // Gets random monster so long as it is not defeated or already present in a room

        bool isInRoomCombatOrder(string monsterName); // Checks if a given monster exists ithin one of the rooms
        bool isDefeatedMonster(string monsterName);  // Checks if a given monster has already been defeated by the player

        void killMonster(string monsterName); // Moves a monster to the defeatedMonsters vector

        bool compareStrings(string a, string b); // Compares two strings

};

#endif
// CSCI 1300 Spring 2023
// Author: Wyatt Massey & Evan Poon
// Recitation: 202 – Lin Shi
// Project 3 - Game Prompts
#ifndef NPC_H
#define NPC_H

#include <iostream>
class npc{
    private:
    std::string intro;
    std::string name;

    public:
    
    npc();
    std::string getIntro();
    void setIntro(std::string inputIntro);
    std::string getName();
    void setName(std::string inputName);
};

#endif
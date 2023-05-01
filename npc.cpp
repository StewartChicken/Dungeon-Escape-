// CSCI 1300 Spring 2023
// Author: Wyatt Massey & Evan Poon
// Recitation: 202 – Lin Shi
// Project 3 - NPC
#include "npc.h"

npc::npc(){
    intro="";
    name="";
}
std::string npc::getIntro(){
    return intro;
}
void npc::setIntro(std::string inputIntro){
    intro=inputIntro;
}
std::string npc::getName(){
    return name;
}
void npc::setName(std::string inputName){
    name = inputName;
}

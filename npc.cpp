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

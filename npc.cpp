#include "npc.h"
    std::string npc::getIntro(){
        return intro;
    }
    void setIntro(std::string inputIntro){
        intro=inputIntro;
    }
    std::string npc::getName(){
        return name;
    }
    void npc::setName(std::string inputName){
        name = inputName;
    }

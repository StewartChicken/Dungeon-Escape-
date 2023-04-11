#include <iostream>
#include <string>
#include "teamMember.h"

//Default constructor
teamMember::teamMember()
{
    this -> fullness = 50;
    this -> name = "";
}

//Parameterized constructor
teamMember::teamMember(std::string name)
{
    this -> name = name;
}

//Getters
int teamMember::getFullness()
{
    return this -> fullness;
}

std::string teamMember::getName()
{
    return this -> name;
}

//Setters
void teamMember::setFullness(int fullness)
{
    this -> fullness = fullness;
}

void teamMember::setName(std::string name)
{
    this -> name = name;
}

//Increments the fullness of the teamMember
void teamMember::incrementFullness()
{
    this -> fullness ++;
}

//Decrements the fullness of the teamMember
void teamMember::decrementFullness()
{
    this -> fullness --;
}



#ifndef TEAMMEMBER_H
#define TEAMMEMBER_H

#include <iostream>
#include <string>

class teamMember
{
    private:
        //Team member data members
        int fullness;
        std::string name;

    public:
        //Constructor
        teamMember();
        teamMember(std::string);

        //Getters
        int getFullness();
        std::string getName();

        //Setters
        void setFullness(int);
        void setName(std::string);

        void incrementFullness();
        void decrementFullness();
};

#endif
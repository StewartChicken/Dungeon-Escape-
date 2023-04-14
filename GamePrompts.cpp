#include <iostream>
#include <string>
#include "GamePrompts.h"

using std::cout;
using std::cin;
using std::string;

//Prompts user to enter his/her name
string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}

//Prompts user to enter his/her team members' names
string Prompts::teamMemberNamePrompt()
{
    string teamMemberName;

    cout << "Please enter the team member name: \n";
    cin >> teamMemberName;

    return teamMemberName;
}


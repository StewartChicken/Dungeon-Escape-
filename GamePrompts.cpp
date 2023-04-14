#include <iostream>
#include <string>
#include "GamePrompts.h"

using std::cout;
using std::cin;
using std::string;

string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}


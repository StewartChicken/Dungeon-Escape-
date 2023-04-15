#ifndef GAMEPROMPTS_H
#define GAMEPROMPTS_H

#include <iostream>
#include "Player.h"
#include "Merchant.h"

using std::string;

class Prompts
{

    public:
        //Player and team member names prompt
        string playerNamePrompt();
        string teamMemberNamePrompt();
};

#endif
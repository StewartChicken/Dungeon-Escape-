#include <iostream>
#include <map>
#include "game.h"

void Game::start()
{
    //Player name prompt
    player.setName(prompts.playerNamePrompt());

    //Team member name prompt
    for(int i{}; i < 4; i ++)
    {
        player.addNewMember(prompts.teamMemberNamePrompt());;
    }

}
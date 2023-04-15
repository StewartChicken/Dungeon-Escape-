#include <iostream>
#include <map>
#include "game.h"

//start the game with user prompts for names
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
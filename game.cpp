#include <iostream>
#include "game.h"

void Game::start()
{
    //Player name prompt
    player.setName(prompts.playerNamePrompt());

    //Team member name prompt
    for(int i{}; i < 4; i ++)
    {
        members[i].setName(prompts.teamMemberNamePrompt());
    }
}
void Merchant::merchant(Player &player, Merchant &merchant){
    choice = prompts.merchantPrompt(player);

}
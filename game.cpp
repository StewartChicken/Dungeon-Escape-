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
    do{
    choice = prompts.merchantPrompt(player);
    price = prompts.purchasePrice(choice, merchant);
    player.setGold(player.getGold() + price);
}
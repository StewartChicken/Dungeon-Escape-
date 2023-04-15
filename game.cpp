#include <iostream>
#include "game.h"

void Game::start()
{
    //Player name prompt
    player.setName(prompts.playerNamePrompt());
}
void Game::merchantInteraction(Player &player, Merchant &merchant){
    int choice = 0;
    int price = 0;
    do{
    choice = prompts.merchantPrompt(player);
    price = prompts.purchaseCost(choice, merchant);
    if(player.getGold() < price){
        cout<<"You're too broke to buy that. Dont come around here with your empty pockets tring to play games. I dont got time for that, ain't nobody got time for that!"<<endl;
    }else{
        player.setGold(player.getGold() + price);
    }
    }while(player.getGold() < 0);
}
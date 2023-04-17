#include <iostream>
#include "Game.h"

void Game::start()
{
    //Player name prompt
    player.addNewMember(prompts.playerNamePrompt(), 0);

    //Add four team members
    player.addNewMember(prompts.memberNamePrompt(), 1);
    player.addNewMember(prompts.memberNamePrompt(), 2);
    player.addNewMember(prompts.memberNamePrompt(), 3);
    player.addNewMember(prompts.memberNamePrompt(), 4);

    prompts.teamGreetingPrompt(player.getPlayerName(), player.getMember1Name(), player.getMember2Name(), player.getMember3Name(), player.getMember4Name());
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
    }while(choice >= 0);
}

void Game::loadMap()
{
    map.displayMap();
}

Player Game::getPlayer(){
    return player;
}

Merchant Game::getMerchant(){
    return merchant;
}
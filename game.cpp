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
    price = prompts.purchaseCost(choice, merchant, player);
    if(choice == 6){
        prompts.goodLuckPrompt();
    }else if(price == 1){
        prompts.imaginaryGlassesPrompt();
        player.incrementImaginaryGlasses();
    }else if(player.getGold() < -price){
        prompts.brokePrompt(); 
    }else{
        player.setGold(player.getGold() + price);
    }
    }while(choice >= 0 && choice != 6);
}

void Game::movementPhase()
{
    map.displayMap();

    char input = '-';

    int newRow;
    int newCol;

    while(true)
    {

        prompts.movementExplorePrompt();
        cin >> input;
        
        if(map.isMovementKey(input))
        {
            
            newRow = map.getPlayerRow();
            newCol = map.getPlayerCol();

            switch(input)
            {
                case 'w':
                    newRow --;
                    break;
                case 's':
                    newRow ++;
                    break;
                case 'a':
                    newCol --;
                    break;
                case 'd':
                    newCol ++;
                    break;
                default:
                    prompts.movementExplorePrompt();
                    break;

            };

            if(map.isOnMap(newRow, newCol))
            {
                map.setPlayerPosition(newRow, newCol);
                map.updateMap();
                prompts.currentStatus(player, merchant, map);
                map.displayMap();
                player.hungerMisfortune(100);
            }
            else
            {
                prompts.invalidPositionPrompt();
                map.displayMap();
            }

        }
        else if(input == 'e')
        {
            prompts.currentStatus(player, merchant, map);
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
            map.displayMap();
            player.investigate(merchant.getRoomsCleared());
        }
        else
        {
            prompts.invalidInputPrompt();
            map.displayMap();
        }
    }
}

Player Game::getPlayer(){
    return player;
}

Merchant Game::getMerchant(){
    return merchant;
}
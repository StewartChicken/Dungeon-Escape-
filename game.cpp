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

void Game::movementPhase()
{
    map.displayMap();

    char input = '-';

    int newRow;
    int newCol;

    while(true)
    {

        cout << "Choose a direction to move\n";
        cin >> input;
        
        if(input == map.getMoveUpKey() || input == map.getMoveDownKey() || input == map.getMoveRightKey() || input == map.getMoveLeftKey())
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
                    cout << "Something went wrong with player movement\n";
                    break;

            };

            if(map.isOnMap(newRow, newCol))
            {
                map.setPlayerPosition(newRow, newCol);
                map.updateMap();
                map.displayMap();
            }
            else
            {
                cout << "Invalid player position\n";
                map.displayMap();
            }

        }
        else
        {
            cout << "Invalid input\n";
        }
    }
}

Player Game::getPlayer(){
    return player;
}

Merchant Game::getMerchant(){
    return merchant;
}
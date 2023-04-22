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
    price = prompts.purchaseCost(choice, merchant, player);
    if(choice == 6){
        cout<<"Good Luck!\n";
    }else if(price == 1){
        cout<<"Here's some imaginary glasses so you can look for the non-existant treasure you just tried to sell me since you want to play make believe.\n\n\n";
        player.incrementImaginaryGlasses();
    }else if(player.getGold() < -price){
        cout<<"You're too broke to buy that. Dont come around here with your empty pockets trying to play games. I dont got time for that, ain't nobody got time for that!\n\n\n";
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

        cout << "Press 'w', 'a', 's' or 'd' to move. Press 'e' to clear the explore the space\n";
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
        else if(input == 'e')
        {
            map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
            map.displayMap();
        }
        else
        {
            cout << "Invalid Input\n";
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
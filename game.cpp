#include "Game.h"

void Game::start(Player &player, Merchant &merchant)
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
    prompts.merchantPrompt(player, merchant);
    prompts.currentStatus(player, merchant, map);
}

void Game::movementPhase(Player& player, Merchant &merchant)
{
    map.displayMap();

    char input = '-';

    int newRow;
    int newCol;

    while(true)
    {
        if((map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())
            || map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
            || map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())) 
            && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
            && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.movementInteractPrompt();
        }
        else
        {
            prompts.movementExplorePrompt();
        }
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
                    //prompts.movementExplorePrompt();
                    cout << "Error - Game::movementPhase\n";
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
            if(!map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.currentStatus(player, merchant, map);
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                map.displayMap();
                player.investigate(merchant.getRoomsCleared());
            }
            else if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) 
                    && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.roomInteractionPrompt(player, merchant, map, monster);
            }
            else if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                    && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.npcInteractionPrompt(player, merchant, map, monster);
            }
            else if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                cout << "DUNGEON EXIT INTERACTION\n";
            }
            else
            {
                cout << "You can't explore an empty space!\n";
            }
        }
        else
        {
            prompts.invalidInputPrompt();
            map.displayMap();
        }
    }
}

/*Player Game::getPlayer(){
    return player;
}

Merchant Game::getMerchant(){
    return merchant;
}*/
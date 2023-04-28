#include "Game.h"

//start function definition
//Starts the game by prompting the user for input - asks for his/her name as well as the names
//of each team member within the party
//Arguments : player and merchant objects (passed by references)
//Return type : void
void Game::start(Player &player, Merchant &merchant)
{
    //Player name prompt
    player.addNewMember(prompts.playerNamePrompt(), 0);

    //Add four team members
    player.addNewMember(prompts.memberNamePrompt(), 1);
    player.addNewMember(prompts.memberNamePrompt(), 2);
    player.addNewMember(prompts.memberNamePrompt(), 3);
    player.addNewMember(prompts.memberNamePrompt(), 4);

    //Greet team members
    prompts.teamGreetingPrompt(player.getPlayerName(), player.getMember1Name(), player.getMember2Name(), player.getMember3Name(), player.getMember4Name());
}

//Game::merchantInteraction function definition
//Prompts the player with the initial merchant interaction to start the game
//Once that interaction is complete, shows the player their present status within the game
void Game::merchantInteraction(Player &player, Merchant &merchant){

    prompts.merchantPrompt(player, merchant); // Initial merchant interaction
    prompts.currentStatus(player, merchant, map); // Show player status
}

//Game::movementPhase function definition
//Encompasses all the primary functionality of the game including 
// - movement
// - investigating spaces
// - interacting with NPC's
// - entering rooms
// - cooking food
// - fighting monsters
// - encountering misfortunes
// 
//Arguments : player and merchant objects (passed by reference)
//Return type : void
void Game::movementPhase(Player& player, Merchant &merchant)
{
    map.displayMap(); //Display map following merchant interaction

    char input = '-'; //Initial input value (set to invalid input)

    //update player row and column
    int newRow;
    int newCol;

    bool room; //Is in room

    //Loops until win or loss condition is met
    while(true)
    {
        room = false; //Initial status of player - not within a room

        //If player is over a room, an NPC, or the exit, prompts player to interact with the space
        if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) 
            && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
            && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.onRoomSpacePrompt();
        }
        else if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
                && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.onNPCSpacePrompt();
        }
        else if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())
                && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
                && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
           prompts.onExitSpacePrompt();
        }
        else
        {
            prompts.movementExplorePrompt();
        }

        //User input
        cin >> input;
        
        //If user input is a movement key
        if(map.isMovementKey(input))
        {
            //Update player location
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

            //Check boundary conditions
            if(map.isOnMap(newRow, newCol))
            {
                map.setPlayerPosition(newRow, newCol); //Update position
                map.updateMap(); //Update map data
                prompts.currentStatus(player, merchant, map); //Prints status of player

                if(map.isNPCLocation(newRow, newCol))
                {
                    map.exploreSpace(newRow, newCol);
                }

                map.displayMap(); // Displays new map
                player.hungerMisfortune(100); //Random hunger misfortune
            }
            else
            {
                //Player tried to move out of bounds
                prompts.invalidPositionPrompt();
                map.displayMap();
            }

        }
        //If player chooses to explore
        else if(input == 'e')
        {
            //If player location has not already been explored
            if(!map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
            {
                //Update map and space status
                prompts.currentStatus(player, merchant, map);
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                map.displayMap();

                //Player investigates space - if the function returns true, a monster fight is launched
                if(player.investigate(merchant.getRoomsCleared())){

                    int numRoomsCleared = merchant.getRoomsCleared();
                    double combatScore = player.calculateCombatScore(numRoomsCleared);
                    string currentMonster = monster.getRandomMonster(numRoomsCleared);

                    // Launch monster fight with random monster
                    prompts.launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster); 
                }
            }
            //Interact with room if the space is a room and hasn't been cleared
            else if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) 
                    && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.roomInteractionPrompt(player, merchant, map, monster);
                room = true; // Entered a room
            }
            //Interact with NPC if the space is an NPC and hasn't been cleared
            else if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                    && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.npcInteractionPrompt(player, merchant, map, monster);
            }
            //Interact with dungeon exit 
            else if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.exitInteractionPrompt(merchant);
            }
            else
            {
                cout << "You can't explore an empty space!\n";
            }
            player.misfortunes(room, map);
        }
        else if(input == 'c')
        {   
            if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                continue;
            }

            int servings = 0;
            int available = player.getIngredients()/5;
            int cookingWith = 0;
            do{
            servings=prompts.foodQuantityPrompt(available);

            }while(servings<0||servings>available);
            if(servings!=0){
                do{
                cookingWith=prompts.cookWithPrompts(player);
                }while(cookingWith==-1);
                if(cookingWith!=0){
                    player.cookFood(servings,cookingWith);
                }
            }

            prompts.currentStatus(player, merchant, map);
            map.displayMap();

            player.misfortunes(room, map);
        }
        else if(input == 'f')
        {
            if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                continue;
            }

            int numRoomsCleared = merchant.getRoomsCleared();
            double combatScore = player.calculateCombatScore(numRoomsCleared);
            string currentMonster = monster.getRandomMonster(numRoomsCleared);

            prompts.launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster);
        }
        else
        {
            prompts.invalidInputPrompt();
            map.displayMap();
        }
    }
}

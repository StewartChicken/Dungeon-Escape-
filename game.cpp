#include "Game.h"

//start function definition
//Starts the game by prompting the user for input - asks for his/her name as well as the names
//of each team member within the party
//Arguments : player and merchant objects (passed by references)
//Return type : void
void Game::start(Player &player, Merchant &merchant)
{

    //Prompts user to input their user name and the names of their team members
    for(int i = 0; i < 5; i ++)
    {
        bool successfullAdd = false;

        while(!successfullAdd)
        {
            if(i == 0) //First member is player username
            {
                successfullAdd = player.addNewMember(prompts.playerNamePrompt(), i); //Username prompt
            }
            else
            {
                successfullAdd = player.addNewMember(prompts.memberNamePrompt(), i); //Teammember prompt
            }
        }
    }

    //Greet team members
    prompts.teamGreetingPrompt(player.getPlayerName(), player.getMember1Name(), player.getMember2Name(), player.getMember3Name(), player.getMember4Name());
}

//Game::merchantInteraction function definition
//Prompts the player with the initial merchant interaction to start the game
//Once that interaction is complete, shows the player their present status within the game
void Game::merchantInteraction(Player &player, Merchant &merchant){

    prompts.merchantPrompt(player, merchant); // Initial merchant interaction
    prompts.currentStatus(player, merchant); // Show player status
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

    string input = ""; //Initial input value (set to invalid input)

    //update player row and column
    int newRow;
    int newCol;

    bool room; //Is in room

    //Loops until win or loss condition is met
    while(true)
    {

        //Player dead
        //All team members dead
        //Sorcer level = 100

        //Lose game conditions
        if(player.getFullness(player.getPlayerName()) < 0)
        {
            //Player gets food poisoned
            if(player.getEndCode() == 2)
            {
                player.endgamePrompt(player.getEndCode());

                //Exit function
                return; 
            }
            player.setEndCode(0); //Player dies from starvation
            player.endgamePrompt(player.getEndCode());

            //Exit function
            return;
        }

        if(player.wholeTeamDead())
        {
            player.setEndCode(3); //Player has no team members left
            player.endgamePrompt(player.getEndCode());

            //Exit function
            return;
        }

        if(gameEnd)
        {
            player.setEndCode(4);
            player.endgamePrompt(player.getEndCode());
            
            return;
        }

        if(player.getSorcererAngerLevel() >= 100)
        {
            player.setEndCode(1); //Anger lever == 100
            player.endgamePrompt(player.getEndCode());

            //Exit function
            return;
        }

        //Player gives up
        if(player.hasQuit())
        {
            player.endgamePrompt(player.getEndCode());

            //Exit function
            return;
        }

        room = false; //Initial status of player - not within a room

        //If player is over a room
        if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()) 
            && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
            && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.onRoomSpacePrompt();
            player.incrementSorcererAnger();
        }
        //If player is over an NPC
        else if(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
                && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.onNPCSpacePrompt();
            player.incrementSorcererAnger();
        }
        //If player is over dungeon exit
        else if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol())
                && map.isExplored(map.getPlayerRow(), map.getPlayerCol())
                && !map.isCleared(map.getPlayerRow(), map.getPlayerCol()))
        {
           prompts.onExitSpacePrompt();
        }
        //Increment sorcerer level when player moves over unexplored area
        else if(!map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
        {
            prompts.movementExplorePrompt();
            player.incrementSorcererAnger();
        }
        else
        {
            //Default prompt
            prompts.movementExplorePrompt();
        }

        //User input

        cin.clear();
        cin.ignore(100, '\n');

        cin >> input;
         
        //If user input is a movement key
        if(map.isMovementKey(input[0]))
        {
            //Update player location
            newRow = map.getPlayerRow();
            newCol = map.getPlayerCol();

            //Movement keys
            switch(input[0])
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
                prompts.currentStatus(player, merchant); //Prints status of player

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

                prompts.currentStatus(player, merchant);
                map.displayMap();
            }

        }
        //If player chooses to explore
        else if(input[0] == 'e')
        {
            //If player location has not already been explored
            if(!map.isExplored(map.getPlayerRow(), map.getPlayerCol()))
            {
                //Update map and space status
                prompts.currentStatus(player, merchant);
                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                map.displayMap();

                //Player investigates space - if the function returns true, a monster fight is launched
                if(player.investigate(merchant.getRoomsCleared())){

                    int numRoomsCleared = merchant.getRoomsCleared();
                    double combatScore = player.calculateCombatScore(numRoomsCleared);
                    string currentMonster = monster.getRandomMonster(numRoomsCleared);

                    // Launch monster fight with random monster
                    prompts.launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster, false); 
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

                prompts.currentStatus(player, merchant);
                map.displayMap();

                map.exploreSpace(map.getPlayerRow(), map.getPlayerCol());
                map.clearSpace(map.getPlayerRow(), map.getPlayerCol());
            }
            //Interact with dungeon exit 
            else if(map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                prompts.exitInteractionPrompt(player, merchant, gameEnd);
            }
            else
            {
                //Explore empty space warning
                cout << "You can't explore an empty space!\n";
            }
            //Create misfortune
            player.misfortunes(room, map);

            prompts.currentStatus(player, merchant);
            map.displayMap();
        }
        //Player chooses to cook food
        else if(input[0] == 'c')
        {   
            //Can't cook food over room, NPC, or dungeon location
            if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                //Continue loop
                continue;
            }

            //Player cook process
            int servings = 0;
            int available = player.getIngredients()/5;
            int cookingWith = 0;
            do{
            //How many servings can the player get
            servings = prompts.foodQuantityPrompt(available);

            }while(servings < 0 || servings > available);
            if(servings!=0){
                do{
                //Asks use which cooking item they wish to use
                cookingWith=prompts.cookWithPrompts(player);
                }while(cookingWith==-1);
                if(cookingWith!=0){
                    player.cookFood(servings,cookingWith); //Cook food
                }
            }

            //Prints the player's current status
            prompts.currentStatus(player, merchant);
            map.displayMap(); 

            //Calls misfortune
            player.misfortunes(room, map);

            prompts.currentStatus(player, merchant);
            map.displayMap();
        }
        else if(input[0] == 'f') //If player wishes to pick a fight
        {
            if(player.isSorcererDefeated())
            {
                cout << "The Sorcerer has been defeated and all other monsters have ran away. There are none to fight.\n";
                continue;
            }

            //Can't pick a fight on a room, npc, or dungeon exit
            if(map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())
                || map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
            {
                continue; //Continue loop
            }

            int numRoomsCleared = merchant.getRoomsCleared();
            double combatScore = player.calculateCombatScore(numRoomsCleared);
            string currentMonster = monster.getRandomMonster(numRoomsCleared);

            //Launch monster fight
            prompts.launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster, false);
        }
        else if(input[0] == 'q') //Quit input
        {
            player.quit(); //Call quit function
        }
        else //Any other input is invalid
        {
            prompts.invalidInputPrompt();
            map.displayMap();
        }

        player.incrementTurnsElapsed();
    }
}   

//Prints final score baord
void Game::scoreBoard(){
    std::vector<pair<std::string, int>> vect;
    prompts.vectorRead("stats.txt", vect);
    bubbleSort(vect);
    prompts.printBoard(vect);
}

//End game function
void Game::endGame(Player &player, Merchant &merchant)
{
    prompts.endgameStats(player, merchant, map);
    scoreBoard();
}

//Sorts a vector of pairs using a bubble sort
//Will traverse through the vector comparing two elements at a time
//If the elements are out of order, will flip their positions in the vector
// and increment the index. Will continue to do this until the end of 
// the vector is reached. The process repeats until the function detects
// that no swaps have been made within the loop
void Game::bubbleSort(std::vector<pair<string, int>> &vec)
{
    bool sorted = false;

    while(!sorted){
        bool alteration = false; //Checks if a swap has been made
        for(int i = 0; i < vec.size() - 1; i ++){
            if(vec.at(i).second < vec.at(i + 1).second){
                alteration = true;

                //Swap elements
                pair<string, int> temp(vec.at(i).first, vec.at(i).second);
                vec.at(i) = vec.at(i + 1);
                vec.at(i + 1) = temp;
            }
        }

        if(!alteration){ // IF no swap, vector is sorted
            sorted = true;
            break;
        }
    }
}

// Todo:
//   teamMemberNamePrompt needs to account for duplicate names - they should not be allowed
//   Dead players are not updated until the next move - should remove them immediately

#include <iostream>
#include <string>
#include "GamePrompts.h"
#include <fstream>

using std::cin;  
using std::cout;
using std::string;

// playerName prompt - asks player to enter their user name
string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}

// memberName prompt - asks player to enter each of his/her team members' names
string Prompts::memberNamePrompt()
{
    string memberName;

    cout << "Please enter a team member name: \n";
    cin >> memberName;

    return memberName;
}

//Greets the newly created team
void Prompts::teamGreetingPrompt(string playerName, string member1, string member2, string member3, string member4)
{
    cout << "Welcome " << playerName << "!\n";
    cout << "Welcome " << member1 << "!\n";
    cout << "Welcome " << member2 << "!\n";
    cout << "Welcome " << member3 << "!\n";
    cout << "Welcome " << member4 << "!\n";
}

// Wishes team good luck
void Prompts::goodLuckPrompt()
{
    cout << "Good Luck!\n";
}

// High level merchent prompt function
void Prompts::merchantPrompt(Player &player, Merchant &merchant)
{
    int choice = 0; //User input selection
    bool merchantMenuActive = true; 

    //While the menu is active, establish a merchant interaction with the user
    while(merchantMenuActive)
    {
        merchantInteraction(player, merchant, merchantMenuActive);
    }
    
}

//Merchant interaction with the user
void Prompts::merchantInteraction(Player &player, Merchant &merchant, bool &active)
{
    //User input - initual value is set to 0
    string choice = "0";

    //Prompt user until they enter a valid input
    while(stoi(choice) < 1 || stoi(choice) > 6)
    {
        //Merchant greets user
        merchantGreeting(player);
        cin >> choice; 

        //Checks to see if the user entered a digit for input - prevents errors with stoi() function
        if(!validNumericalInput(choice))
        {
            choice = "0";
            continue;
        }
    }

    //Number of items the user is purchasing
    int itemCount;

    //User selection - which goods did they choose to purchase
    switch(stoi(choice))
    {
        case 1:
            itemCount = itemBuyMenu(player, merchant, merchant.getIngredientPrice(), "kg(s) of Ingredients"); //Ingredients for food
            player.setIngredients(player.getIngredients() + itemCount); //User gains ingredients if they succesfully make a purchase
            break;
        case 2:
            cookwareBuyMenu(player, merchant); //User chooses to buy cookware
            break;
        case 3:
            weaponBuyMenu(player, merchant); //User chooses to buy weapons
            break;
        case 4:
            itemCount = itemBuyMenu(player, merchant, merchant.getArmorSuitPrice(), "Armor suit(s)"); //User chooses to buy armor
            player.setArmorSuits(player.getArmorSuits() + itemCount); //Update user inventory
            break;
        case 5:
            sellTreasureMenu(player, merchant); //User chooses to sell treasure
            break;
        case 6:
            active = false; //Deactivates menu - user chooses to exit merchant interaction
            break;
        default:
            cout << "Error - merchantInteraction\n"; //Error code - this case should never be reached
            break;
    };
}

//Prints the greeting card from the merchant
void Prompts::merchantGreeting(Player &player)
{
    cout << "If you're looking to get supplies, you've come to the right place.\n";
    cout << "I would be happy to part with some of my wares...for the proper price!\n\n\n";

    //Displays user inventory - pulls information from the player class
    cout << "+-------------------+\n"
         << "|  Inventory        |\n"
         << "+-------------------+\n"
         << "| Gold              | " << player.getGold() << " |\n"
         << "| Indregients       | " << player.getIngredients() << " kg |\n"
         << "| Cookware          | P: " << player.getCeramicPots() << "| F: " << player.getFryingPans() << "| C:" << player.getCauldrons() << "|\n"
         << "| Weapons           | C: " << player.getStoneClubs() << "| S: " << player.getIronSpears() << "| R: " << player.getMythrilRapiers() << "| B: " << player.getFlamingAxes() << "| L: " << player.getVorpalSwords() << "|\n"
         << "| Armor             | " << player.getArmorSuits() << " |\n"
         << "| Treasures         | R:" << player.getSilverRings() << "| N: " << player.getRubyNecklaces() << "| B: " << player.getEmeraldBracelets() << "| C: " << player.getDiamondCirclets() << "| G: " << player.getGemGoblets() << "|\n";
         if(player.getImaginaryGlasses() > 0)cout<<"| Imaginary Glasses | "<<player.getImaginaryGlasses()<<" |\n";
         cout << "+-------------------+\n";
         cout << "\n\n Choose one of the following:\n"
         << "1. Ingredients: To make food, you have to cook raw ingredients\n"
         << "2. Cookware: You will need something to cook those ingredients.\n"
         << "3. Weapons: It's dangerous to go alone, take this!\n"
         << "4. Armor: If you want to survive monster attacks, you will need some armor.\n"
         << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands.\n"
         << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!\n"
         << ">";
}


//Returns number of items bought
int Prompts::itemBuyMenu(Player &player, Merchant &merchant, int price, string itemLabel)
{
    string amount = "-1";

    while(stoi(amount) < 0)
    {
        cout << "How many " << itemLabel << " would you like to buy? (" << price << " Gold each). Press 0 to cancel.\n";
        cin >> amount;

        //Checks if user inputs a digit
        if(!validNumericalInput(amount))
        {
            cout << "Invalid amount.\n";
            amount = "-1";
            continue;
        }

    }

    //If valid amount was input by user
    if(stoi(amount) > 0)
    {
        //How many items would the user like to buy?
        int itemsBought = confirmPurchase(player, merchant, stoi(amount), price, itemLabel);

        if(itemsBought == 0)
        {
            //If user doesn't buy anything, sends user back to the item buy menu
            itemBuyMenu(player, merchant, price, itemLabel);
        }
        else
        {
            //Returns number of items the user was able to purchase
            return itemsBought;
        }
    }

    //Returns 0 by default
    return 0;
}

//Computes number of items purchased
//Takes user input for requested number of items
//Multiplies requested number by price of each item
// Checks if user can afford itetm
//If the user can afford it, confirms purchase
int Prompts::confirmPurchase(Player &player, Merchant &merchant, int numItems, int price, string item)
{
    char confirmation;

    //Transaction in progress
    bool transaction = true;

    //While transaction is in progress
    while(transaction)
    {
        //Confirmation
        cout << "Are you sure you want to buy " << numItems << " " << item << "? (y/n)\n";
        cin >> confirmation;
        
        //Invalid input check
        if(confirmation != 'y' && confirmation != 'n')
        {
            cout << "Invalid input\n\n";
            continue;
        }

        switch(confirmation)
        {
        case 'y':
            
            //Checks if user can afford purchase
            if(canPurchaseGoods(player, numItems, price))
            {
                //Subtracts gold from user inventory
                player.setGold(player.getGold() - numItems * price);
                return numItems;
            }
            else
            {
                //User is too broke to afford goods
                brokePrompt();
                return 0;
            }

            break;
        //User cancels transaction
        case 'n':
            transaction = false;
            break;
        default:
            //Error case - should not reach this case
            cout << "Error - confirmIngredientPurchase\n";
            break;
        };
    }

    //Returns 0 by default
    return 0;
}

//Sell treasure menu
//Allows user to sell treasures they find to the merchant
void Prompts::sellTreasureMenu(Player &player, Merchant &merchant)
{

    string choice = "-1";

    while(stoi(choice) < 0)
    {
        //Print values of each item - pulls information from the merchant class
        cout << "During your journey, you may encounter pieces of treasure in each room. When you The price of each treasure\n"
            "depends upon the number of rooms cleared when it was found. Once you sell a piece of treasure, I cannot sell\n"
            "it back to you\n"
            "1.) Silver ring [" << merchant.getSilverRingValue() << " Gold]\n"
            "2). Ruby necklace [" << merchant.getRubyNecklaceValue() << "Gold]\n"
            "3.) Emerald bracelet [" << merchant.getSilverRingValue() << " Gold]\n"
            "4.) Diamond circlet [" << merchant.getSilverRingValue() << " Gold]\n"
            "5.) Gem-encrusted goblet [" << merchant.getSilverRingValue() << " Gold]\n"
            "What do you have for me?\n";
        cin >> choice;

        //Is user input a digit
        if(!validNumericalInput(choice))
        {
            choice = "-1";
            continue;
        }
    }

    //User selection - which item will they sell to the merchant?
    //If, at any point, the user tries to sell the merchant treasures they do not possess,
    // the merchant calls them out and gives them imaginary glasses so they can find the 
    // imaginary treasure they just tried to sell
    switch(stoi(choice))
    {
        //User sells silver rings
        case 1:
            //If user doesn't have the treasure
            if(player.getSilverRings() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses(); //Add one pair of imaginary glasses to user inventory
                break;
            }
            else
            {
                //Sell all silver rings
                player.setGold(player.getGold() + player.getSilverRings() * merchant.getSilverRingValue());
                player.setSilverRings(0);
            }
        //User sells ruby necklaces
        case 2:
            if(player.getRubyNecklaces() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses();
                break;
            }
            else
            {
                player.setGold(player.getGold() + player.getRubyNecklaces() * merchant.getRubyNecklaceValue());
                player.setRubyNecklaces(0);
            }
        //User sells emerald bracelets
        case 3:
            if(player.getEmeraldBracelets() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses();
                break;
            }
            else
            {
                player.setGold(player.getGold() + player.getEmeraldBracelets() * merchant.getEmeraldBraceletValue());
                player.setEmeraldBracelets(0);
            }
        //User sells diamond circlets
        case 4:
            if(player.getDiamondCirclets() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses();
                break;
            }
            else
            {
                player.setGold(player.getGold() + player.getDiamondCirclets() * merchant.getDiamondCircletValue());
                player.setDiamondCirclets(0);
            }
        //User sells gem goblets
        case 5:
            if(player.getGemGoblets() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses();
                break;
            }
            else
            {
                player.setGold(player.getGold() + player.getGemGoblets() * merchant.getGemGobletValue());
                player.setGemGoblets(0);
            }
        //Error code - should not reach this case
        default:
            cout << "Error - sellTreasureMenu\n";
            break;
    };

}

// Cookware buy menu
void Prompts::cookwareBuyMenu(Player &player, Merchant &merchant)
{

    string cookwareChoice = "-1";

    //Prompt user to select which item of cookware they wish to buy
    while(stoi(cookwareChoice) < 0 || stoi(cookwareChoice) > 3)
    {
        //User's cookware opptions
        cout << "You need cookware in order to turn your ingredients into food wich, when consumed, will replenish\n"
            "your fullness levels or that of your companions.\n"
            "1.) Ceramic pot (25% chance of breaking)\n"
            "2.) Frying pan (10% chance of breaking)\n"
            "3.) Cauldron (2% chance of breaking)\n"
            "The more dependable items will be more expensive, are you a chaepskate?"
            "(Enter a positive integer, or 0 to cancel)\n";

        cin >> cookwareChoice;

        //Does the user enter a digit?
        if(!validNumericalInput(cookwareChoice))
        {
            cookwareChoice = "-1";
            continue;
        }
    }

    //If user cancels the transaction
    if(stoi(cookwareChoice) == 0)
    {
        return;
    }

    int itemCount; //Number of cookware items the user purchases

    switch(stoi(cookwareChoice))
    {
        //User wants to buy ceramic pots
        case 1:
            itemCount = itemBuyMenu(player, merchant, merchant.getCeramicPotPrice(), "Ceramic pots");
            player.setCeramicPots(player.getCeramicPots() + itemCount);
            break;
        //User wants to buy frying pans
        case 2:
            itemCount = itemBuyMenu(player, merchant, merchant.getFryingPanPrice(), "Frying pans");
            player.setFryingPans(player.getFryingPans() + itemCount);
            break;
        //User wnts to buy cauldrons
        case 3:
            itemCount = itemBuyMenu(player, merchant, merchant.getCauldronPrice(), "Cauldrons");
            player.setCauldrons(player.getCauldrons() + itemCount);
            break;
        //Error code - should not reach this case
        default:
            cout << "Error - cookwareBuyMenu\n";
            break;
    }
   
}

// Weapon buy menu
void Prompts::weaponBuyMenu(Player &player, Merchant &merchant)
{
    string choice = "-1";

    while(stoi(choice) < 0 || stoi(choice) > 5)
    {
        cout << "You need weapons to be able to fend off\n"
            "monsters, otherwise, you can only run\n!"
            "Equipping your team with the maximum\n"
            "number of weapons (1 weapon per person)\n"
            "and buying upgraded weapons that are\n"
            "worth 5 gold pieces will maximize you\n"
            "chances of survival during an attack. You can\n"
            "have a maximum of 5 weapons. These are\n"
            " the different types of weapons: \n"
            "1.) Club\n"
            "2.) Spear\n"
            "3.) +1 Rapier\n"
            "4.) +2 Battle-axe\n"
            "5.) +3 Longsword\n"
            "Which weapon catches your fancy? (Enter a positive integer, or 0 to cancel)\n";
        
        cin >> choice;
        if(!validNumericalInput(choice))
        {
            choice = "-1";
            continue;
        }
    }

    if(stoi(choice) == 0)
    {
        return;
    }

    int itemCount;
    switch(stoi(choice))
    {
        case 1:
            itemCount = itemBuyMenu(player, merchant, merchant.getStoneClubPrice(), "Stone club(s)");
            player.setStoneClubs(player.getStoneClubs() + itemCount);
            break;
        case 2:
            itemCount = itemBuyMenu(player, merchant, merchant.getIronSpearPrice(), "Iron spear(s)");
            player.setIronSpears(player.getIronSpears() + itemCount);
            break;
        case 3:
            itemCount = itemBuyMenu(player, merchant, merchant.getMythrilRapierPrice(), "Mythril Rapier(s)");
            player.setMythrilRapiers(player.getMythrilRapiers() + itemCount);
            break;
        case 4:
            itemCount = itemBuyMenu(player, merchant, merchant.getFlamingAxePrice(), "Battle Axe(s)");
            player.setFlamingAxes(player.getFlamingAxes() + itemCount);
            break;
        case 5:
            itemCount = itemBuyMenu(player, merchant, merchant.getVorpalSwordPrice(), "Vorpal Sword(s)");
            player.setVorpalSwords(player.getVorpalSwords() + itemCount);
            break;
        default:
            "Error - weaponBuyMenu\n";
            break;

    };
    
}

//Checks if the player has enough gold to purchase the goods they requested
bool Prompts::canPurchaseGoods(Player &player, int amount, int price)
{
    if(player.getGold() < amount * price)
    {
        return false;
    }

    return true;
}

void Prompts::currentStatus(Player &player, Merchant &merchant){
    cout << "+-------------------+\n"
         << "|  Status           | Rooms Cleared: "<< merchant.getRoomsCleared()<<" | Keys: "<<player.getNumKeys()<<" | Sorcerer's Anger Level: " << player.getSorcererAngerLevel()
         << "\n+-------------------+\n"
         << "+-------------------+\n"
         << "|  Inventory        |\n"
         << "+-------------------+\n"
         << "| Gold              | " << player.getGold() << " |\n"
         << "| Indregients       | " << player.getIngredients() << " kg |\n"
         << "| Cookware          | P: " << player.getCeramicPots() << "| F: " << player.getFryingPans() << "| C:" << player.getCauldrons() << "|\n"
         << "| Weapons           | C: " << player.getStoneClubs() << "| S: " << player.getIronSpears() << "| R: " << player.getMythrilRapiers() << "| B: " << player.getFlamingAxes() << "| L: " << player.getVorpalSwords() << "|\n"
         << "| Armor             | " << player.getArmorSuits() << " |\n"
         << "| Treasures         | R:" << player.getSilverRings() << "| N: " << player.getRubyNecklaces() << "| B: " << player.getEmeraldBracelets() << "| C: " << player.getDiamondCirclets() << "| G: " << player.getGemGoblets() << "|\n";
         if(player.getImaginaryGlasses() > 0)cout<<"| Imaginary Glasses | "<<player.getImaginaryGlasses()<<" |\n";
    cout << "+-------------------+\n";
         if(player.getFullness(player.getPlayerName())>=0)cout<< "\n| "<<player.getPlayerName()<<" | Fullness: "<< player.getFullness(player.getPlayerName());
         if(player.getFullness(player.getMember1Name())>=0)cout<< "\n| "<<player.getMember1Name()<<" | Fullness: "<< player.getFullness(player.getMember1Name());
         if(player.getFullness(player.getMember2Name())>=0)cout<< "\n| "<<player.getMember2Name()<<" | Fullness: "<< player.getFullness(player.getMember2Name());
         if(player.getFullness(player.getMember3Name())>=0)cout<< "\n| "<<player.getMember3Name()<<" | Fullness: "<< player.getFullness(player.getMember3Name());
         if(player.getFullness(player.getMember4Name())>=0)cout<< "\n| "<<player.getMember4Name()<<" | Fullness: "<< player.getFullness(player.getMember4Name());
         cout<< "\n\n+---------------------+\n";
 }

void Prompts::roomInteractionPrompt(Player &player, Merchant &merchant, Map &map, Monster &monster)
{
    bool enteredRoom;

    if(player.getNumKeys() > 0)
    {
        enteredRoom = roomKeyPrompt(player);
    }
    else
    {
        cout << "You do not have enough keys to access this room!\n" <<
            "Consequently, the door challenges you to a ruthless game of Boulder, Parchment, Shears!\n";

        //If player loses door trap game
        if(!doorGameInteraction(player))
        {
            cout << "The door has bested you!\n";
            player.loseTeamMember();
            return;
        } 
        else
        {
            cout << "You have conquered the door's trap! You may now proceed to the room\n";
            enteredRoom = true;
        }
    }

    if(enteredRoom)
    {   
        player.decrementKeys();

        int numRoomsCleared = merchant.getRoomsCleared();
        double combatScore = player.calculateCombatScore(numRoomsCleared);
        string currentMonster = monster.getMonsterFromRoomCombatOrder(numRoomsCleared);
        
        launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster, enteredRoom);
    }
}


bool Prompts::doorGameInteraction(Player &player)
{
    srand(time(0));

    int attemptsRemaining = 3;

    cout << "\nYou have three attempts to beat the door. If you do so, you will be granted access to the room.\n" <<
    "Should you fail, one of your team members will be executed!\n";

    for(int i = 0; i < 3; i ++)
    {
        string playerChoice = "0";

        while(stoi(playerChoice) != 1 && stoi(playerChoice) != 2 && stoi(playerChoice) != 3)
        {
            std::cout << "\nAttempts Remaining: " << attemptsRemaining << "\n\nChoose your move!\n" <<
                    "1). Boulder\n" <<
                    "2). Parchment\n" <<
                    "3). Shears\n>";

            std::cin >> playerChoice;

            if(!validNumericalInput(playerChoice))
            {
                playerChoice = "0";
                continue;
            }
        }

        int doorChoice = (rand() % 3) + 1;

        string doorChoiceString;
        string playerChoiceString;

        switch(doorChoice)
        {
            case 1: 
                doorChoiceString = "Boulder";
                break;
            case 2:
                doorChoiceString = "Parchment";
                break;
            case 3:
                doorChoiceString = "Shears";
                break;
            default:
                cout << "Error - doorGameInteraction\n";
                break;
        };

        switch(stoi(playerChoice))
        {
            case 1: 
                playerChoiceString = "Boulder";
                break;
            case 2:
                playerChoiceString = "Parchment";
                break;
            case 3:
                playerChoiceString = "Shears";
                break;
            default:
                cout << "Error - doorGameInteraction\n";
                break;
        };
        
        std::cout << "\nYou chose: " << playerChoiceString <<  "\nThe door chose:" << doorChoiceString << "\n";

        if(player.winsDoorTrapGame(stoi(playerChoice), doorChoice))
        {
            return true;
        }

        cout << "The door won that round! Try again.\n";
        attemptsRemaining --;
    }

    return false;
}

void Prompts::launchMonsterFight(Player &player, Merchant &merchant, Map &map, double combatScore, int roomsCleared, string monsterName, Monster &monster, bool enteredRoom)
{

    if(player.isSorcererDefeated())
    {
        return;
    }

    srand(time(0));

    string combatChoice = "0";

    while(stoi(combatChoice) != 1 && stoi(combatChoice) != 2)
    {
        cout << monsterName << " ahead!! They got beef wit u bro! Would you like to take the fight or surrender?\n" <<
        "1). Take the fight!!\n" <<
        "2). Surrender..\n";    

        cin >> combatChoice;

        if(!validNumericalInput(combatChoice))
        {
            combatChoice = "0";
            continue;
        }
    }

    //Player chooses to surrender
    if(stoi(combatChoice) == 2)
    {
        cout << "\n\nYou chose to surrender at the expense of a team member.\n\n";

        player.surrenderTeamMember();
        player.monsterFightDecrementFullness(); //Each player has 50% chance of decrementing fullness

        currentStatus(player, merchant);
        map.displayMap();

        return;
    }

    if(player.countNumWeapons() < 1)
    {
        cout << "\n\nYou encountered a hostile " << monsterName << " but you did not have a single weapon to defend yourself with!\n" <<
        "You are forced to surrender and one of your team mates was lost to the wrath of the monster. R.I.P.\n\n";

        player.surrenderTeamMember();
        player.monsterFightDecrementFullness();

        currentStatus(player, merchant);
        map.displayMap();

        return;
    }

    if(player.winsFight(combatScore))
    {

        srand(time(0));

        int keyDrop = rand() % 10;

        if(merchant.getRoomsCleared() == 4 && enteredRoom)
        {
            player.defeatSorcerer();
        }
        
        cout << "\n\nNot to fear, your team is strong enough to overcome the adversary!\n\n";
        map.clearSpace(map.getPlayerRow(), map.getPlayerCol());
        player.winFight(roomsCleared + 2);
        
        if(enteredRoom)
        {
            merchant.incrementRoomsCleared();
            merchant.updateMultiplier();
        }
        
        player.monsterFightDecrementFullness();
        monster.killMonster(monsterName);

        player.setGameScore(player.getGameScore() + monster.getMonsterDifficulty(monsterName));

        if(keyDrop == 0)
        {
            player.incrementKeys();
        }

        if(enteredRoom)
        {
            int misFortuneChance = rand() % 10;

            if(misFortuneChance <= 5)
            {
                player.misfortunes(false, map);
            }
        }

        currentStatus(player, merchant);
        map.displayMap();
    }
    else
    {
        cout << "\n\nYou were too weak to defeat the monster, you have endured heavy losses\n\n";
        player.loseFight();
        player.monsterFightDecrementFullness();

        if(enteredRoom)
        {
            int misFortuneChance = rand() % 10;

            if(misFortuneChance <= 3)
            {
                player.misfortunes(false, map);
            }
        }

        currentStatus(player, merchant);
        map.displayMap();
    }
}


bool Prompts::roomKeyPrompt(Player &player)
{
    char confirm = '-';

        while(confirm != 'y' && confirm != 'n')
        {
            cout << "Would you like to use a key to access this room? (y/n)\n";
            cin >> confirm;
        }

    if(confirm == 'y')
    {
        player.decrementKeys();
    }

    return confirm == 'y';
}


// Imaginary glasses prompt - user tries to sell treasures they don't have
void Prompts::imaginaryGlassesPrompt()
{
cout << "Here's some imaginary glasses so you can look for the non-existant treasure you just tried to sell me since you want to play make believe.\n\n\n";
}

// Player doesn't have enough money
void Prompts::brokePrompt()
{
    cout << "You're too broke to buy that. Dont come around here with your empty pockets trying to play games. I dont got time for that, ain't nobody got time for that!\n\n\n";
}

// Informs user which actions they can take within the movement menu
void Prompts::movementExplorePrompt()
{
    cout << "Press 'w', 'a', 's' or 'd' to move. Press 'e' to explore the space.\nPress 'c' to cook ingrediants. Press 'f' to pick a fight. Press 'q' to give up.\n";
}

// Informs user which actions they can take when on a room space
void Prompts::onRoomSpacePrompt()
{
    cout << "Press 'w', 'a', 's', or 'd' to move. Press 'e' to open the door. Press 'q' to give up.\n";
}

// Informs user which actions they can take when on an NPC space
void Prompts::onNPCSpacePrompt()
{
    cout << "Press 'w', 'a', 's', or 'd' to move. Press 'e' to interact with the NPC. Press 'q' to give up.\n";
}

// Informs player which actions they can take on the exit space
void Prompts::onExitSpacePrompt()
{
    cout << "Press 'w', 'a', 's', or 'd' to move. Press to try the exit. Press 'q' to give up.\n";
}

// Error with player movement
void Prompts::movementErrorPrompt()
{
    cout << "Something went wrong with player movement\n";
}

// Invalid position for party
void Prompts::invalidPositionPrompt()
{
    cout << "Invalid player position\n";
}

// Invalid user input
void Prompts::invalidInputPrompt()
{
    cout << "Invalid Input\n";
}

void Prompts::npcInteractionPrompt(Player &player, Merchant &merchant, Map &map, Monster &monster){ 
    int numRoomsCleared = merchant.getRoomsCleared();
    double combatScore = player.calculateCombatScore(numRoomsCleared);
    string currentMonster = monster.getRandomMonster(numRoomsCleared);
    
    npcWelcomeMessage();
    if(npcRiddle()){
        if(barterPrompt()){
            merchantPrompt(player,merchant);
        }
    }else{
        launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster, monster, false);
    } 

}

bool Prompts::barterPrompt(){
    char confirm;
    do{
        cout<<"\n\n\nYou have succeeded. Do you wish to barter? (y/n)\n";
        cin>>confirm;
        if(confirm!='n'&&confirm!='y'){
            cout<<"\nplease enter a valid input.\n";
        }
    }while(confirm!='n'&&confirm!='y');
    switch(confirm){
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            return false;
    }
}
void Prompts::npcWelcomeMessage(){
    srand(time (0));
    int chaos=rand()%4;
    if(chaos==3){
        std::cout<<"You have encountered a lowly peasant\n\n***extremely raspy voice*** Helllo there stranger. I have an offer for you. If you answer my riddle, I will let you take a look at my wares.\n\n";
    }else if(chaos==2){
        std::cout<<"You have encountered Porcha\n\nLet's see if you have any brain behind all that brawn. I am thinking of something, if you can guess it, I'll let you see what I have to offer.\n\n";       
    }else if(chaos==1){
        std::cout<<"You have encountered a friendly goblin\n\n***some goblin gibberish*** riddle for wares???\n proceeds to read you the following scripture:\n\n";
    }else if(chaos==0){
        std::cout<<"You have encountered a scholar\n\n***Smiles in a highly condesending way***A warrior? Im assuming you would like to buy some crude object to bluggon or stab your enemys with. It seems a fool such as yourself would be served better by sharpening your mind. answer my riddle, and I'll let you peruse my collection.\n\n";
    }
    
}

bool Prompts::npcRiddle(){
    bool success = false;
    string answer;
    string arr[6][2];
    srand(time (0));
    int chaos=rand()%6;
    int remaining_attempts = 2;
    read("riddles.txt", arr, 6);
    cout<<arr[chaos][0]<<endl;
    //cout<<"checking answer:"<<arr[chaos][1];
    cin.clear ();    // Restore input stream to working state
    cin.ignore ( 100 , '\n' );
    for(int i=0; i<3 && !success;i++){
        cin.clear ();    // Restore input stream to working state
        //cin.ignore ( 100 , '\n' );    
        getline(cin,answer);
        if(arr[chaos][1]==answer){
            success =true;
        }else{
            cout<<"you have failed, you have " << remaining_attempts << " attempts left.\n";
        }
        remaining_attempts--;
    }
    return success;
}

void Prompts::split(string input_string, char seperator, string arr[], int arr_size){
    //initalizing required variables
    int j=0;
    for(int i=0;i<arr_size;i++){
        arr[i]="";   
    }
    
    //Ensuring we dont go outside the string length
    for(int i=0;i<input_string.length();i++){
        //Changing index of new array if current index value is a seperator
        if(input_string[i]==seperator){
            j++;
        }//Ensuring we dont go outide of the new array size
        else if(j<arr_size){
            //storing character values in current array index 
            arr[j]=arr[j]+input_string[i];
        }
    }
}

void Prompts::exitInteractionPrompt(Player &player, Merchant &merchant, bool &gameEnd)
{
    if(!player.isSorcererDefeated())
    {
        cout << "You have not cleared all rooms! The dungeon exit is locked.\n";
    }
    else
    {
        gameEnd = true;
    }
}

void Prompts::read(string file_name,string arr[][2], int array_size){  
    string arr2[2];
    string line;    // variable for storing each line as we read it
    ifstream fin;   // file input stream

    fin.open(file_name); // Open input file
    
    if (fin.fail())
    {
        cout << "Unable to open file";
    }
    else
    {
        // read every line of file, count number of matches on each line
        for (int j = 0;!fin.eof()&&j<array_size;) // continue looping as long as there is data to be processed in the file
        {
            getline(fin,line);
            if(line!=""){
                split(line,'|',arr2,2);
                for(int i=0;i<2;i++){
                    if(arr2[i]!=""){
                        arr[j][i]=arr2[i];   
                    }
                }
                j++;
            }    
        } 
        // close files
        fin.close();
    }
}

 int Prompts::foodQuantityPrompt(int available){
    string quantity = "0";

    while(stoi(quantity) <= 0)
    {
        cout<<"How many servings (5kg each) of ingredients would you like to cook? Enter 0 to cancel.\n";

        cin >> quantity;

        if(!validNumericalInput(quantity))
        {
            quantity = "0";
            continue;
        }

        if(stoi(quantity) == 0)
        {
            return 0;
        }

        if(available < stoi(quantity))
        {
            cout << "You don't have enough ingredients for this meal. Please enter a valid quantity\n";
            quantity = "-1";
            continue;
        }
    }
    return stoi(quantity);
 }

 int Prompts::cookWithPrompts(Player &player){
    string choice = "0";
    do{
    cout<<"What would you like to cook your food with? Enter 0 to cancel.(please select an item you have in your inventory)\n"
    <<"1.) Ceramic pot\n"
    <<"2.) Frying pan\n"
    <<"3.) Cauldron\n";
    cin>>choice;

    if(!validNumericalInput(choice))
    {
        choice = "0";
        continue;
    }
    switch(stoi(choice)){
        case 1:
            if(player.getCeramicPots() < 1){
                cout<<"You do not have any cermaic pots.\n";
                return-1;
            }
            break;
        case 2:
            if(player.getFryingPans() < 1){
                cout<<"You do not have any frying pans.\n";
                return-1;
            }
            break;
        case 3:
            if(player.getCauldrons() < 1){
                cout<<"You do not have any cauldrons.\n";
                return-1;
            }
            break;
        default:
            cout<<"Please enter a valid input\n";
            break;
    }
    }while(stoi(choice) <= 0 || stoi(choice) > 3);
    return stoi(choice);
 }

bool Prompts::validNumericalInput(string userInput)
{
    for(int i = 0; i < userInput.length(); i ++)
    {
        if(!isdigit(userInput[i]))
        {
            return false;
        }
    }

    return true;
}
void Prompts::endgameStats(Player &player, Map &map){
    ofstream scores;
    scores.open("stats.txt",std::ios_base::app);

    if(player.isSorcererDefeated())std::cout << "Congratulations "<<player.getPlayerName()<<"!\nYou made it through the dungeon with";
    else std::cout<<player.getPlayerName()<<"'s final stats\n";
    if(player.getFullness(player.getMember1Name())>=0)std::cout<<" "<<player.getMember1Name();
    if(player.getFullness(player.getMember1Name())>=0&&player.getFullness(player.getMember2Name())>=0)std::cout<<",";
    if(player.getFullness(player.getMember2Name())>=0)std::cout<<" "<<player.getMember2Name();
    if(player.getFullness(player.getMember2Name())>=0&&player.getFullness(player.getMember3Name())>=0)std::cout<<",";
    if(player.getFullness(player.getMember3Name())>=0)std::cout<<" "<<player.getMember3Name();
    if(player.getFullness(player.getMember3Name())>=0&&player.getFullness(player.getMember4Name())>=0)std::cout<<",";
    if(player.getFullness(player.getMember4Name())>=0)std::cout<<" "<<player.getMember4Name()<<"\n";
    cout<<".\n"
        <<"+------------------+\n"
        <<"| Gold: "<<player.getGold()<<"\n"
        <<"| Treasures R:"<<player.getSilverRings()<<" | N: "<<player.getRubyNecklaces()<<" | B:"<<player.getEmeraldBracelets()<<" | C:"<<player.getDiamondCirclets()<<" | G:"<<player.getGemGoblets()<<"\n"
        <<"| Explored Spaces: "<<map.getNumSpacesExplored()<<"\n"
        <<"| Number of monsters defeated: "<<player.getMonstersDefeated()<<"\n"
        <<"| Number of turns elapsed: "<<"**# of turns elapsed"<<"\n"
        <<"+------------------+\n\n";
    scores<<player.getPlayerName()<<"|"<<player.getGameScore()<<"|"<<player.getMember1Name()<<"|"<<player.getMember2Name()<<"|"<<player.getMember3Name()<<"|"<<player.getMember4Name()<<"|"<<player.getGold()<<"|"<<player.getSilverRings()<<"|"<<player.getRubyNecklaces()<<"|"<<player.getEmeraldBracelets()<<"|"<<player.getDiamondCirclets()<<"|"<<player.getGemGoblets()<<"\n";
}
void Prompts::vectorSplit(std::string line, std::vector<std::pair<string, int>> &vect){
    string c_data;
    pair<string, int> c_pair;
    int j = 0;
    //cout<<line<<endl;
    if(line!=""){
        for(int i=0; j<2; i++){
            if(line[i]!='|'){
                c_data+=line[i];
            }else{
                if(j==0){
                    c_pair.first=c_data;
                }else{
                    //cout<<c_data<<endl;
                    c_pair.second=stoi(c_data);
                }
                c_data="";
                j++; 
            }
        }
        vect.push_back(c_pair);
    }

}
void Prompts::vectorRead(std::string file_name, std::vector<std::pair<string, int>> &vect){
    ifstream info;
    string line;
    info.open(file_name);
    while(getline(info,line)){
        vectorSplit(line,vect);
    }

}
void Prompts::printBoard(std::vector<pair<std::string, int>> &vect){
    cout<<"|++++++++++  High Scores  +++++++++++|\n";
    for(int i=0; i<vect.size(); i++){
        cout<<"             "<<i+1<<" > "<<vect[i].first<<" -> "<<vect[i].second<<endl; 
    }

}


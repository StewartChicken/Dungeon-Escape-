// Todo:
//   teamMemberNamePrompt needs to account for duplicate names - they should not be allowed

#include <iostream>
#include <string>
#include "GamePrompts.h"

using std::cin;  
using std::cout;
using std::string;

// playerName prompt
string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}

// memberName prompt
string Prompts::memberNamePrompt()
{
    string memberName;

    cout << "Please enter a team member name: \n";
    cin >> memberName;

    return memberName;
}

void Prompts::teamGreetingPrompt(string playerName, string member1, string member2, string member3, string member4)
{
    cout << "Welcome " << playerName << "!\n";
    cout << "Welcome " << member1 << "!\n";
    cout << "Welcome " << member2 << "!\n";
    cout << "Welcome " << member3 << "!\n";
    cout << "Welcome " << member4 << "!\n";
}

// Good luck
void Prompts::goodLuckPrompt()
{
    cout << "Good Luck!\n";
}

// Merchant prompt
void Prompts::merchantPrompt(Player &player, Merchant &merchant)
{
    int choice = 0;
    bool merchantMenuActive = true;

    while(merchantMenuActive)
    {
        merchantInteraction(player, merchant, merchantMenuActive);
    }
    
}

void Prompts::merchantInteraction(Player &player, Merchant &merchant, bool &active)
{
    int choice = 0;

    //While the input is not a valid choice
    while(choice < 1 || choice > 6)
    {
        merchantGreeting(player);
        cin >> choice;
    }

    int itemCount;

    switch(choice)
    {
        case 1:
            itemCount = itemBuyMenu(player, merchant, merchant.getIngredientPrice(), "kg(s) of Ingredients");
            player.setIngredients(player.getIngredients() + itemCount);
            break;
        case 2:
            cookwareBuyMenu(player, merchant);
            break;
        case 3:
            weaponBuyMenu(player, merchant);
            break;
        case 4:
            itemCount = itemBuyMenu(player, merchant, merchant.getArmorSuitPrice(), "Armor suit(s)");

            //check if player's suits exceed 5 - create method later
            player.setArmorSuits(player.getArmorSuits() + itemCount);
            break;
        case 5:
            sellTreasureMenu(player, merchant);
            break;
        case 6:
            active = false;
            break;
        default:
            cout << "Error - merchantInteraction\n";
            break;
    };
}

//Prints the greeting card from the merchant
void Prompts::merchantGreeting(Player &player)
{
    cout << "If you're looking to get supplies, you've come to the right place.\n";
    cout << "I would be happy to part with some of my wares...for the proper price!\n\n\n";

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
    int amount = -1;

    while(amount < 0)
    {
        cout << "How many " << itemLabel << " would you like to buy? (" << price << " Gold each). Press 0 to cancel.\n";
        cin >> amount;

        if(amount < 0)
        {
            negativeAmountWarning();
            continue;
        }
    }

    if(amount > 0)
    {
        int itemsBought = confirmPurchase(player, merchant, amount, price, itemLabel);

        if(itemsBought == 0)
        {
            itemBuyMenu(player, merchant, price, itemLabel);
        }
        else
        {
            return itemsBought;
        }
    }

    return 0;
}

//Returns number of items purchased
int Prompts::confirmPurchase(Player &player, Merchant &merchant, int numItems, int price, string item)
{
    char confirmation;

    bool transaction = true;

    while(transaction)
    {
        cout << "Are you sure you want to buy " << numItems << " " << item << "? (y/n)\n";
        cin >> confirmation;
        
        if(confirmation != 'y' && confirmation != 'n')
        {
            cout << "Invalid input\n\n";
            continue;
        }

        switch(confirmation)
        {
        case 'y':
            
            if(canPurchaseGoods(player, numItems, price))
            {
                player.setGold(player.getGold() - numItems * price);
                return numItems;
            }
            else
            {
                brokePrompt();
                return 0;
            }

            break;
        case 'n':
            transaction = false;
            break;
        default:
            cout << "Error - confirmIngredientPurchase\n";
            break;
        };
    }

    return 0;
}

// Sell treasure menu
void Prompts::sellTreasureMenu(Player &player, Merchant &merchant)
{

    int choice = -1;

    while(choice < 0)
    {
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
    }

    switch(choice)
    {
        case 1:
            if(player.getSilverRings() <= 0)
            {
                imaginaryGlassesPrompt();
                player.incrementImaginaryGlasses();
                break;
            }
            else
            {
                player.setGold(player.getGold() + player.getSilverRings() * merchant.getSilverRingValue());
                player.setSilverRings(0);
            }
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
        default:
            cout << "Error - sellTreasureMenu\n";
            break;
    };

}

// Cookware buy menu
void Prompts::cookwareBuyMenu(Player &player, Merchant &merchant)
{

    int cookwareChoice = -1;

    while(cookwareChoice < 0 || cookwareChoice > 3)
    {
        cout << "You need cookware in order to turn your ingredients into food wich, when consumed, will replenish\n"
            "your fullness levels or that of your companions.\n"
            "1.) Ceramic pot (25% chance of breaking)\n"
            "2.) Frying pan (10% chance of breaking)\n"
            "3.) Cauldron (2% chance of breaking)\n"
            "The more dependable items will be more expensive, are you a chaepskate?"
            "(Enter a positive integer, or 0 to cancel)\n";

        cin >> cookwareChoice;
    }

    if(cookwareChoice == 0)
    {
        return;
    }

    int itemCount;
    switch(cookwareChoice)
    {
        case 1:
            itemCount = itemBuyMenu(player, merchant, merchant.getCeramicPotPrice(), "Ceramic pots");
            player.setCeramicPots(player.getCeramicPots() + itemCount);
            break;
        case 2:
            itemCount = itemBuyMenu(player, merchant, merchant.getFryingPanPrice(), "Frying pans");
            player.setFryingPans(player.getFryingPans() + itemCount);
            break;
        case 3:
            itemCount = itemBuyMenu(player, merchant, merchant.getCauldronPrice(), "Cauldrons");
            player.setCauldrons(player.getCauldrons() + itemCount);
            break;
        default:
            cout << "Error - cookwareBuyMenu\n";
            break;
    }
   
}

// Weapon buy menu
void Prompts::weaponBuyMenu(Player &player, Merchant &merchant)
{
    int choice = -1;

    while(choice < 0 || choice > 5)
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
    }

    if(choice == 0)
    {
        return;
    }

    int itemCount;
    switch(choice)
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

void Prompts::currentStatus(Player &player, Merchant &merchant, Map &map){
    cout << "+-------------------+\n"
         << "|  Status           | Rooms Cleared: "<< merchant.getRoomsCleared()<<" | Keys: "<<player.getNumKeys()<<" | Sorcerer's Anger Level: " << map.getNumSpacesExplored()
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
    cout << "+-------------------+\n"
         << "\n| "<<player.getPlayerName()<<" | Fullness: "<< player.getFullness(player.getPlayerName())
         << "\n| "<<player.getMember1Name()<<" | Fullness: "<< player.getFullness(player.getMember1Name())
         << "\n| "<<player.getMember2Name()<<" | Fullness: "<< player.getFullness(player.getMember2Name())
         << "\n| "<<player.getMember3Name()<<" | Fullness: "<< player.getFullness(player.getMember3Name())
         << "\n| "<<player.getMember4Name()<<" | Fullness: "<< player.getFullness(player.getMember4Name())
         << "\n\n+---------------------+\n";
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
        cout << "You do not have enough keys to access this room!\n";
        return;
    }

    int numRoomsCleared = merchant.getRoomsCleared();
    double combatScore = player.calculateCombatScore(numRoomsCleared);
    string currentMonster = monster.getMonsterFromCombatOrder(numRoomsCleared);

    if(enteredRoom)
    {
        launchMonsterFight(player, merchant, map, combatScore, numRoomsCleared, currentMonster);
    }
}

void Prompts::launchMonsterFight(Player &player, Merchant &merchant, Map &map, double combatScore, int roomsCleared, string monsterName)
{
    cout << monsterName << " ahead!! They got beef wit u bro! COMBATSCORE: " << combatScore << "\n";

    if(player.winsFight(combatScore))
    {
        cout << "Not to fear, your team is strong enough to overcome the adversary!\n";
        map.clearSpace(map.getPlayerRow(), map.getPlayerCol());
        player.winFight(roomsCleared + 2);
        merchant.incrementRoomsCleared();
    }
    else
    {
        cout << "You were too weak to defeat the monster, you have endured heavy losses\n";
        map.clearSpace(map.getPlayerRow(), map.getPlayerCol());
        merchant.incrementRoomsCleared();
        player.loseFight();
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
    cout << "Press 'w', 'a', 's' or 'd' to move. Press 'e' to explore the space\n";
}

// Informs user which actions they can take within the movement menu
void Prompts::movementInteractPrompt()
{
    cout << "Press 'w', 'a', 's' or 'd' to move. Press 'e' to interact with the space\n";
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

void Prompts::negativeAmountWarning()
{
    cout << "\nInvalid input, cannot buy negative ingredients!\n\n";
}

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
void goodLuckPrompt()
{
    cout << "Good Luck!\n";
}

// Merchant prompt
int Prompts::merchantPrompt(Player &player)
{
    int choice = 0;

    while (choice < 1 || choice > 6)
    {
        initialMerchantPrompt(player);
        cin >> choice;
    }

    return choice;
}

void Prompts::initialMerchantPrompt(Player &player)
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

int Prompts::purchaseCost(int choice, Merchant &merchant, Player &player)
{
    string item = "";
    int costPerUnit = 0;
    string suffix = "";
    string quantitySuffix = "";
    string prefix = "";
    int quantity = 0;
    bool selling = false;
    bool finished = false;
    char confirm = 'o';
    bool valid = false;
    int price = 0;
    switch (choice)
    {
    case 1:
        do
        {
            ingredientBuyMenu(merchant, costPerUnit, item, quantitySuffix);
            cin >> quantity;
        } while (quantity < 0);
        break;
    case 2:
        do
        {
            cookwareBuyMenu();
            cin >> choice;
        } while (choice < 0 || choice > 3);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            item = "Ceramic pot";
            costPerUnit = merchant.getCeramicPotPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold]" << std::endl;
            cin >> quantity;
            break;
        case 2:
            item = "Frying pan";
            costPerUnit = merchant.getFryingPanPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold]" << std::endl;
            cin >> quantity;
            break;
        case 3:
            item = "Cauldron";
            costPerUnit = merchant.getCauldronPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold]" << std::endl;
            cin >> quantity;
            break;
        case 4:
            item = "Flaming Battle-Axe";
            costPerUnit = merchant.getFlamingAxePrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold]" << std::endl;
            cin >> quantity;
            break;
        case 5:
            item = "Vorpal Longswords";
            costPerUnit = merchant.getStoneClubPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold]" << std::endl;
            cin >> quantity;
            break;
        }
        break;
    case 3:
        do
        {
            weaponBuyMenu();
            cin >> choice;
        } while (choice < 0 || choice > 5);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            item = "Stone Club";
            costPerUnit = merchant.getStoneClubPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold] (Enter a positive integer, or 0 to cancel)" << std::endl;
            cin >> quantity;
            break;
        case 2:
            item = "Iron Spear";
            costPerUnit = merchant.getIronSpearPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold] (Enter a positive integer, or 0 to cancel)" << std::endl;
            cin >> quantity;
            break;
        case 3:
            item = "Mythril Rapier";
            costPerUnit = merchant.getMythrilRapierPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold] (Enter a positive integer, or 0 to cancel)" << std::endl;
            cin >> quantity;
            break;
        case 4:
            item = "Flaming Battle-Axe";
            costPerUnit = merchant.getFlamingAxePrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold] (Enter a positive integer, or 0 to cancel)" << std::endl;
            cin >> quantity;
            break;
        case 5:
            item = "Vorpal Longswords";
            costPerUnit = merchant.getStoneClubPrice();
            cout << "How many " << item << "s can I get you? [" << costPerUnit << " gold] (Enter a positive integer, or 0 to cancel)" << std::endl;
            cin >> quantity;
            break;
        }
        break;
    case 4:
        armorBuyMenu(merchant, item);
        cin >> quantity;
        prefix = " suit";
        break;
    case 5:
        selling = true;
        do
        {
            sellTreasureMenu(merchant);
            cin >> choice;
        } while (choice < 0 || choice > 4);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            item = "silver ring";
            cout << "How many " << item << "s would you like to sell me?" << std::endl;
            cin >> quantity;
            costPerUnit = merchant.getSilverRingValue();
            if(player.getSilverRings()>0){
                valid=true;
            }
            break;
        case 2:
            item = "emerald bracelet";
            cout << "How many " << item << "s would you like to sell me?" << std::endl;
            cin >> quantity;
            costPerUnit = merchant.getEmeraldBraceletValue();
            if(player.getEmeraldBracelets()>0){
                valid=true;
            }
            break;
        case 3:
            item = "diamond circlet";
            cout << "How many " << item << "s would you like to sell me?" << std::endl;
            cin >> quantity;
            costPerUnit = merchant.getDiamondCircletValue();
            if(player.getDiamondCirclets()>0){
                valid=true;
            }
            break;
        case 4:
            item = "gem-encrusted goblet";
            cout << "How many " << item << "s would you like to sell me?" << std::endl;
            cin >> quantity;
            costPerUnit = merchant.getGemGobletValue();
            if(player.getGemGoblets()>0){
                valid = true;
            }
            break;
        }
        break;
    }
    if (quantity > 0 && !selling)
    {
        price = costPerUnit * quantity;
        if (quantity > 1 && quantitySuffix != "kg" && item != "Armor")
        {
            suffix += "s";
        }
        if (item == "Armor" || item == "Ingredients")
        {
            if (quantity > 1)
            {
                prefix += "s";
            }
            prefix += " of ";
        }
        do
        {
            cout << "You want to buy " << quantity <<quantitySuffix<<" "<< prefix << item << suffix << " for " << price << " gold?(y/n)" << std::endl;
            cin >> confirm;
        } while (confirm != 'y' && confirm != 'n');
        switch (confirm)
        {
        case 'y':
            cout << "You have good taste my friend.\n\n\n------------------------------------------------------------\n\n\n" << std::endl;
            return -price;
            break;
        case 'n':
            cout << "You're smart, only a fool would have made that purchase.\n\n\n------------------------------------------------------------\n\n\n" << std::endl;
            return 0;
            break;
        }
    }
    else if (quantity > 0 && selling)
    {
        if (quantity>1)suffix += "s";
        price = costPerUnit * quantity;
        cout << "You wish to sell to me " << quantity << " " << item << suffix << "?(y/n)" << std::endl;
        cin >> confirm;
        switch (confirm)
        {
        case 'y':
            cout << "Thank you dearly for your buisness.\n\n\n------------------------------------------------------------\n\n\n" << std::endl;
            if(!valid){
                return 1;
            }
            return price;
            break;
        case 'n':
            cout << "I didn't want your " << item << suffix << " anyway!\n\n\n------------------------------------------------------------\n\n\n" << std::endl;
            return 0;
            break;
        }
    }
    else if (quantity < 0)
    {
        cout << "please enter a valid quantity next time\n\n\n------------------------------------------------------------\n\n\n" << std::endl;
        return 0;
    } 
    return 0;
}

void Prompts::currentStatus(Player &player, Merchant &merchant, Map &map){
    cout << "+-------------------+\n"
         << "|  Status           | Rooms Cleared: "<< merchant.getRoomsCleared()<<" | Keys: "<<player.getNumKeys()<<" | Sorcerer's Anger Level: "<<map.getNumSpacesExplored()
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
         if(player.getImaginaryGlasses() > 0)cout<<"| Imaginary Glasses | "<<player.getImaginaryGlasses()<<" |\n";
    cout << "+-------------------+\n"
         << "\n| "<<player.getPlayerName()<<" | Fullness: "<< player.getFullness(player.getPlayerName())
         << "\n| "<<player.getMember1Name()<<" | Fullness: "<< player.getFullness(player.getMember1Name())
         << "\n| "<<player.getMember2Name()<<" | Fullness: "<< player.getFullness(player.getMember2Name())
         << "\n| "<<player.getMember3Name()<<" | Fullness: "<< player.getFullness(player.getMember3Name())
         << "\n| "<<player.getMember4Name()<<" | Fullness: "<< player.getFullness(player.getMember4Name())
         << "\n\n+---------------------+\n";
 }

// Ingredient buy menu
void Prompts::ingredientBuyMenu(Merchant &merchant, int &costPerUnit, string &item, string &quantitySuffix)
{
    costPerUnit = merchant.getIngredientPrice();
    cout << "You should by atleast 10kg of ingredients per player. [" << costPerUnit << " gold per kg]" << std::endl;
    item = "Ingredients";
    cout << "How many kg of " << item << " can I get you?(Enter a positive integer, or 0 to cancel)" << std::endl;
    quantitySuffix = "kg";
}

// Cookware buy menu
void Prompts::cookwareBuyMenu()
{
    cout << "You need cookware in order to turn your ingredients into food wich, when consumed, will replenish\n"
            "your fullness levels or that of your companions.\n"
            "1.) Ceramic pot (25% chance of breaking)\n"
            "2.) Frying pan (10% chance of breaking)\n"
            "3.) Cauldron (2% chance of breaking)\n"
            "The more dependable items will be more expensive, are you a chaepskate?"
            "(Enter a positive integer, or 0 to cancel)\n";
}

// Weapon buy menu
void Prompts::weaponBuyMenu()
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
            "Which weapon catches your fancy?(Enter a positive integer, or 0 to cancel)\n";
}

// Sell treasure menu
void Prompts::sellTreasureMenu(Merchant &merchant)
{
    cout << "During your journey, you may encounter pieces of treasure in each room. When you The price of each treasure\n"
            "depends upon the number of rooms cleared when it was found. Once you sell a piece of treasure, I cannot sell\n"
            "it back to you\n"
            "1.) Silver ring [" << merchant.getSilverRingValue() << " gold]\n"
            "2.) Emerald bracelet [" << merchant.getSilverRingValue() << " gold]\n"
            "3.) Diamond circlet [" << merchant.getSilverRingValue() << " gold]\n"
            "4.) Gem-encrusted goblet [" << merchant.getSilverRingValue() << " gold]\n"
            "What do you have for me?\n";
}

// Armor buy menu
void Prompts::armorBuyMenu(Merchant &merchant, string &item)
{
    cout << "Armor protects you from monsters. Equipping your team with the maximum amount of armor (1 armor per person)\n"
            "will maximize your chances of survival during an attack. Adding more armor on top of the maximum amount will\n"
            "not increase your chances further.\n"
             "How many suits of Armor can I get you? [" << merchant.getArmorSuitPrice() << " gold](Enter a positive integer, or 0 to cancel)\n";

             item = "Armor";
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
    cout << "Press 'w', 'a', 's' or 'd' to move. Press 'e' to clear the explore the space\n";
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
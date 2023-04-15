#include <iostream>
#include <string>
#include "GamePrompts.h"

using std::cout;
using std::cin;
using std::string;

string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}
int Prompts::merchantPrompt(Player &player){
    int choice = 0;
    do{
    cout<<"If you're looking to get supplies, you've come to the right place.
    I would be happy to part with some of my wares...for the proper price!"<<endl;
    cout<<endl<<endl<<
    "+-------------+"<<endl<<
    "|  Inventory  |"<<endl<<
    "+-------------+"<<endl<<
    "| Gold        |"<<player.getGold()<<"|"<<endl
    "| Indregients |"<<player.getIngredients()<<"kg |"<<endl<<
    "| Cookware    | P: "<<player.getPots()<<"| F: "<<player.getFryingPans()<<"| C:"<<player.getCauldrons()<<"|"<<endl<<
    "| Weapons     | C: "<<player.getStoneClubs()<<"| S: "<<player.getIronSpears()<<"| R: "<<player.getMythrilRapier()<<"| B: "<<player.getBattleAxe()<<"| L: "<<player.getVorpalSword()<<"|"<<endl<<
    "| Armor       |"<<player.getArmor()<<"|"<<endl<<
    "| Treasures   | R:"<<player.getSilverRing()<<"| N: "<<player.getRubyNecklace()<<"| B: "<<player.getEmeraldBracelet()<<"| C: "<<player.getDiamondCirclet()<<"| G: "<<player.gemGoblets()<<"|"<<endl<<
    "Choose one of the following:"<<endl<<
    "1. Ingredients: To make food, you have to cook raw ingredients."<<endl<<
    "2. Cookware: You will need something to cook those ingredients."<<endl<<
    "3. Weapons: It's dangerous to go alone, take this!"<<endl<<
    "4. Armor: If you want to survive monster attacks, you will need some armor."<<endl<<
    "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands."<<endl<<
    "6. Leave: Make sure you get everything you need, I'm leaving after this sale!"<<endl;
    cout<<">";
    cin>>choice;
    }while(choice<1||choice>6);
    return choice
}
int Prompts::purchaseCost(int choice, Merchant &merchant){
    string item="";
    int costPerUnit = 0;
    string suffix = "";
    int quantity = 0;
    switch (choice)
    {
    case 1:
        do{
        costPerUnit = merchant.getIngredientPrice();
        cout<<"You should by atleast 10kg of ingredients per player. ["<<costPerUnit<<" gold per kg]"<<endl;
        item ="Ingredients";
        cout<<"How many kg of "<<item<<" can I get you?(Enter a positive integer, or 0 to cancel)"<<endl;
        cin>>quantity;
        suffix="kg";
        }while(quantity<0);
    break;
    case 2:
        do{
        cout<<"You need cookware in order to turn your ingredients into food wich, when consumed, will replenish"<<endl<<
        "your fullness levels or that of your companions."<<endl<<
        "1.) Ceramic pot (25% chance of breaking)"<<endl<<
        "2.) Frying pan (10% chance of breaking)"<<endl<<
        "3.) Cauldron (2% chance of breaking)"<<endl<<\
        "The more dependable items will be more expensive, are you a chaepskate?"<<"(Enter a positive integer, or 0 to cancel)"<<endl;
        cin>>choice;
        }while(choice<0||choice>3);
        if(choice==0){
            break;
        }
        switch(choice)
        {
            case 1:
                item="Ceramic pot";
                costPerUnit=merchant.getCeramicPotPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<endl;
                cin>>quantity;
            break;
            case 2:
                item="Frying pan";
                costPerUnit=merchant.getFryingPanPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<endl;
                cin>>quantity;
            break; 
            case 3:
                item="Cauldron";
                costPerUnit=merchant.getCauldronPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<endl;
                cin>>quantity;
            break; 
            case 4:
                item="Flaming Battle-Axe";
                costPerUnit=merchant.getFlamingAxePrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<endl;
                cin>>quantity;
            break; 
            case 5:
                item="Vorpal Longswords";
                costPerUnit=merchant.getStoneClubPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<endl;
                cin>>quantity;
            break;
        }  
    break;
    case 3:
        do{
        cout<<"You need weapons to be able to fend off"<<endl<<
        "monsters, otherwise, you can only run!"<<endl<<
        "Equipping your team with the maximum"<<endl<<
        "number of weapons (1 weapon per person)"<<endl<<
        "and buying upgraded weapons that are"<<endl<<
        "worth 5 gold pieces will maximize your"<<endl<<
        "chances of survival during an attack. You can"<<endl<
        "have a maximum of 5 weapons. These are"<<endl<<" the different types of weapons: "<<endl<<
        "1.) Club"<<endl<<
        "2.) Spear"<<endl<<
        "3.) +1 Rapier"<<endl<<
        "4.) +2 Battle-axe"<<endl<<
        "5.) +3 Longsword"<<endl<<
        "Which weapon catches your fancy?(Enter a positive integer, or 0 to cancel)"<<endl;
        cin>>choice;
        }while(choice<0||choice>5);
        if(choice==0){
            break;
        }
        switch(choice)
        {
            case 1:
                item="Stone Club";
                costPerUnit=merchant.getStoneClubPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<endl;
                cin>>quantity;
            break;
            case 2:
                item="Iron Spear";
                costPerUnit=merchant.getIronSpearPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<endl;
                cin>>quantity;
            break; 
            case 3:
                item="Mythril Rapier";
                costPerUnit=merchant.getMythrilRapierPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<endl;
                cin>>quantity;
            break; 
            case 4:
                item="Flaming Battle-Axe";
                costPerUnit=merchant.getFlamingAxePrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<endl;
                cin>>quantity;
            break; 
            case 5:
                item="Vorpal Longswords";
                costPerUnit=merchant.getStoneClubPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<endl;
                cin>>quantity;
            break;  
        }
    break;
    case 4:
        item = "Armor";
        costPerUnit = merchant.getArmorSuitPrice();
        cout<<"How many suits of "<<item<<" can I get you? ["<<costPerUnit<<" gold](Enter a positive integer, or 0 to cancel)"<<endl;
        cin>>quantity;
    break;
    case 5:
        
    break;
    }

}

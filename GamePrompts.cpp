//Todo:
//  teamMemberNamePrompt needs to account for duplicate names - they should not be allowed

#include <iostream>
#include <string>
#include "GamePrompts.h"

using std::cout;
using std::cin;
using std::string;

//playerName prompt
string Prompts::playerNamePrompt()
{
    string playerName;

    cout << "Please enter the player name: \n";
    cin >> playerName;

    return playerName;
}

//memberName prompt
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

//Merchant prompt
int Prompts::merchantPrompt(Player &player){
    int choice = 0;
    do{
    cout<<"If you're looking to get supplies, you've come to the right place."<<std::endl<<
    "I would be happy to part with some of my wares...for the proper price!"<<std::endl;
    cout<<std::endl<<std::endl<<
    "+-------------+"<<std::endl<<
    "|  Inventory  |"<<std::endl<<
    "+-------------+"<<std::endl<<
    "| Gold        |"<<player.getGold()<<"|"<<std::endl<<
    "| Indregients |"<<player.getIngredients()<<"kg |"<<std::endl<<
    "| Cookware    | P: "<<player.getCeramicPots()<<"| F: "<<player.getFryingPans()<<"| C:"<<player.getCauldrons()<<"|"<<std::endl<<
    "| Weapons     | C: "<<player.getStoneClubs()<<"| S: "<<player.getIronSpears()<<"| R: "<<player.getMythrilRapiers()<<"| B: "<<player.getFlamingAxes()<<"| L: "<<player.getVorpalSwords()<<"|"<<std::endl<<
    "| Armor       |"<<player.getArmorSuits()<<"|"<<std::endl<<
    "| Treasures   | R:"<<player.getSilverRings()<<"| N: "<<player.getRubyNecklaces()<<"| B: "<<player.getEmeraldBracelets()<<"| C: "<<player.getDiamondCirclets()<<"| G: "<<player.getGemGoblets()<<"|"<<std::endl<<
    "Choose one of the following:"<<std::endl<<
    "1. Ingredients: To make food, you have to cook raw ingredients."<<std::endl<<
    "2. Cookware: You will need something to cook those ingredients."<<std::endl<<
    "3. Weapons: It's dangerous to go alone, take this!"<<std::endl<<
    "4. Armor: If you want to survive monster attacks, you will need some armor."<<std::endl<<
    "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands."<<std::endl<<
    "6. Leave: Make sure you get everything you need, I'm leaving after this sale!"<<std::endl;
    cout<<">";
    cin>>choice;
    }while(choice>1||choice<6);
    return choice;
}
int Prompts::purchaseCost(int choice, Merchant &merchant){
    string item="";
    int costPerUnit = 0;
    string suffix = "";
    string prefix ="";
    int quantity = 0;
    bool selling = false;
    bool finished = false;
    char confirm = 'o';
    int price = 0;
    switch (choice)
    {
    case 1:
        do{
        costPerUnit = merchant.getIngredientPrice();
        cout<<"You should by atleast 10kg of ingredients per player. ["<<costPerUnit<<" gold per kg]"<<std::endl;
        item ="Ingredients";
        cout<<"How many kg of "<<item<<" can I get you?(Enter a positive integer, or 0 to cancel)"<<std::endl;
        cin>>quantity;
        suffix="kg";
        }while(quantity<0);
    break;
    case 2:
        do{
        cout<<"You need cookware in order to turn your ingredients into food wich, when consumed, will replenish"<<std::endl<<
        "your fullness levels or that of your companions."<<std::endl<<
        "1.) Ceramic pot (25% chance of breaking)"<<std::endl<<
        "2.) Frying pan (10% chance of breaking)"<<std::endl<<
        "3.) Cauldron (2% chance of breaking)"<<std::endl<<\
        "The more dependable items will be more expensive, are you a chaepskate?"<<"(Enter a positive integer, or 0 to cancel)"<<std::endl;
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
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<std::endl;
                cin>>quantity;
            break;
            case 2:
                item="Frying pan";
                costPerUnit=merchant.getFryingPanPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<std::endl;
                cin>>quantity;
            break; 
            case 3:
                item="Cauldron";
                costPerUnit=merchant.getCauldronPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<std::endl;
                cin>>quantity;
            break; 
            case 4:
                item="Flaming Battle-Axe";
                costPerUnit=merchant.getFlamingAxePrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<std::endl;
                cin>>quantity;
            break; 
            case 5:
                item="Vorpal Longswords";
                costPerUnit=merchant.getStoneClubPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold]"<<std::endl;
                cin>>quantity;
            break;
        }  
    break;
    case 3:
        do{
        cout<<"You need weapons to be able to fend off"<<std::endl<<
        "monsters, otherwise, you can only run!"<<std::endl<<
        "Equipping your team with the maximum"<<std::endl<<
        "number of weapons (1 weapon per person)"<<std::endl<<
        "and buying upgraded weapons that are"<<std::endl<<
        "worth 5 gold pieces will maximize your"<<std::endl<<
        "chances of survival during an attack. You can"<<std::endl<<
        "have a maximum of 5 weapons. These are"<<std::endl<<" the different types of weapons: "<<std::endl<<
        "1.) Club"<<std::endl<<
        "2.) Spear"<<std::endl<<
        "3.) +1 Rapier"<<std::endl<<
        "4.) +2 Battle-axe"<<std::endl<<
        "5.) +3 Longsword"<<std::endl<<
        "Which weapon catches your fancy?(Enter a positive integer, or 0 to cancel)"<<std::endl;
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
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<std::endl;
                cin>>quantity;
            break;
            case 2:
                item="Iron Spear";
                costPerUnit=merchant.getIronSpearPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<std::endl;
                cin>>quantity;
            break; 
            case 3:
                item="Mythril Rapier";
                costPerUnit=merchant.getMythrilRapierPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<std::endl;
                cin>>quantity;
            break; 
            case 4:
                item="Flaming Battle-Axe";
                costPerUnit=merchant.getFlamingAxePrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<std::endl;
                cin>>quantity;
            break; 
            case 5:
                item="Vorpal Longswords";
                costPerUnit=merchant.getStoneClubPrice();
                cout<<"How many "<<item<<"s can I get you? ["<<costPerUnit<<" gold] (Enter a positive integer, or 0 to cancel)"<<std::endl;
                cin>>quantity;
            break;  
        }
    break;
    case 4:
        item = "Armor";
        costPerUnit = merchant.getArmorSuitPrice();
        cout<<"Armor protects you from monsters. Equipping your team with the maximum amount of armor (1 armor per person)"<<std::endl<<
        "will maximize your chances of survival during an attack. Adding more armor on top of the maximum amount will"<<std::endl<<
        "not increase your chances further."<<std::endl<<
        "How many suits of "<<item<<" can I get you? ["<<costPerUnit<<" gold](Enter a positive integer, or 0 to cancel)"<<std::endl;
        cin>>quantity;
        prefix=" suit";
    break;
    case 5:
        selling = true;
        do{
        cout<<"During your journey, you may encounter pieces of treasure in each room. When you The price of each treasure"<<std::endl<<
        "depends upon the number of rooms cleared when it was found. Once you sell a piece of treasure, I cannot sell"<<std::endl<<
        "it back to you"<<std::endl<<
        "1.) Silver ring ["<<merchant.getSilverRingValue()<<" gold]"<<std::endl<<
        "2.) Emerald bracelet ["<<merchant.getSilverRingValue()<<" gold]"<<std::endl<<
        "3.) Diamond circlet ["<<merchant.getSilverRingValue()<<" gold]"<<std::endl<<
        "4.) Gem-encrusted goblet ["<<merchant.getSilverRingValue()<<" gold]"<<std::endl<<
        "What do you have for me?"<<std::endl;
        cin>>choice;
        }while(choice<0||choice>4);
        if(choice=0){
            break;
        }
        switch (choice)
        {
        case 1:
            item = "silver ring";
            cout<<"How many "<<item<<"s would you like to sell me?"<<std::endl;
            cin>>quantity;
            costPerUnit = merchant.getSilverRingValue();
        break;
        case 2:
            item = "emerald bracelet";
            cout<<"How many "<<item<<"s would you like to sell me?"<<std::endl;
            cin>>quantity;
            costPerUnit = merchant.getEmeraldBraceletValue();
        break;
        case 3:
            item = "diamond circlet";
            cout<<"How many "<<item<<"s would you like to sell me?"<<std::endl;
            cin>>quantity;
            costPerUnit = merchant.getDiamondCircletValue();
        break;
        case 4:
            item = "gem-encrusted goblet";
            cout<<"How many "<<item<<"s would you like to sell me?"<<std::endl;
            cin>>quantity;
            costPerUnit = merchant.getGemGobletValue();
        break;
        }
    break;
    }
    if(quantity>0&&!selling){
        price = costPerUnit*quantity;
        if(quantity>1&&suffix!="kg"&&item!="Armor"){
            suffix += "s";
        }
        if(item=="Armor"||item=="Ingredients"){
            if(quantity>1){
                prefix += "s";
            }
            prefix +=" of ";
        }
        do{
        cout<<"You want to buy "<<quantity<<prefix<<item<<suffix<<" for "<<price<<" gold?(y/n)"<<std::endl;
        cin>>confirm;
        }while(confirm!='y'&&confirm!='n');
        switch(confirm)
        {
            case 'y':
                cout<<"You have good taste my friend."<<std::endl;
                return -price;
            break;
            case 'n':
                cout<<"You're smart, only a fool would have made that purchase."<<std::endl;
                return 0;
            break;
        }
    }else if(quantity>0&&selling){
        price = costPerUnit*quantity;
        cout<<"You wish to sell to me "<<quantity<<" "<<item<<suffix<<"?"<<std::endl;
        cin>>confirm;
        switch(confirm)
        {
            case 'y':
                cout<<"Thank you dearly for your buisness"<<std::endl;
                return price;
            break;
            case 'n':
                cout<<"I didnt want your "<<item<<suffix<<" anyway!"<<std::endl;
                return 0;
            break;
        }
    }else if(quantity<0){
        cout<<"please enter a valid quantity next time"<<std::endl;
        return 0;
    }
    return 0;

}

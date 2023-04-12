

//Inclusions
#include "player.h"
#include "TeamMember.h"
#include "Merchant.h"
#include "gameStats.h"

#include <iostream>
#include <string>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{

    Player player;
    teamMember member;
    Merchant merchant;
    GameStats stats;
    
    cout<<"Player info:"<<endl<<endl;
    
    player.setFullness(12);
    player.setGold(50);
    player.setIngredients(38);
    player.setCeramicPots(90);
    player.setFryingPans(87);
    player.setCauldrons(42);
    player.setStoneClubs(59);
    player.setIronSpears(4);
    player.setMythrilRapiers(1);
    player.setFlamingAxes(7);
    player.setVorpalSwords(35);
    player.setArmorSuits(27);
    player.setSilverRings(75);
    player.setRubyNecklaces(83);
    player.setEmeraldBracelets(85);
    player.setDiamondCirclets(92);
    player.setGemGoblets(100000023);
    player.setNumKeys(0);
    player.setName("couger");
    player.incrementFullness();
    player.incrementFullness();
    player.decrementFullness();
    player.incrementKeys();
    player.incrementKeys();
    player.decrementKeys();
    player.cookFood(int);
    cout<<"Player's Fullness: "<<player.getFullness()<<endl<<endl;
    cout<<"Player's Gold: "<<player.getGold()<<endl;
    cout<<"Player's Ingredients: "<<player.getIngredients()<<endl;
    cout<<"Player's Ceramic Pots: "<<player.getCeramicPots()<<endl;
    cout<<"Player's Frying Pans: "<<player.getFryingPans()<<endl;
    cout<<"Player's Cauldrons: "<<player.getCauldrons()<<endl;
    cout<<"Player's Clubs: "<<player.getStoneClubs()<<endl;
    cout<<"Player's Iron Spears: "<<player.getIronSpears()<<endl;
    cout<<"Player's Mythril Rapiers: "<<player.getMythrilRapiers()<<endl;
    cout<<"Player's Flaming Axes: "<<player.getFlamingAxes()<<endl;
    cout<<"Player's Vorpal Swords: "<<player.getVorpalSwords()<<endl;
    cout<<"Player's Armour Sits: "<<player.getArmorSuits()<<endl;
    cout<<"Player's Silver Rings: "<<player.getSilverRings()<<endl;
    cout<<"Player's Ruby Necklace: "<<player.getRubyNecklaces()<<endl;
    cout<<"Player's Emerald Bracelets: "<<player.getEmeraldBracelets()<<endl;
    cout<<"Player's Diamond Circlets: "<<player.getDiamondCirclets()<<endl;
    cout<<"Player's Gem Goblets: "<<player.getGemGoblets()<<endl;
    cout<<"Player's Keys: "<<player.getNumKeys()<<endl;
    cout<<"Player's Name: "<<player.getName()<<endl;
    
    cout<<endl<<endl<<endl;
    
    cout<<"Merchant's Pricing:"<<endl<<endl;
    
    cout<<"Ingredient cost: "<<merchant.getIngredientPrice()<<endl;
    cout<<"Ceramic Pot cost: "<<merchant.getCeramicPotPrice()<<endl;
    cout<<"Frying Pan cost: "<<merchant.getFryingPanPrice()<<endl;
    cout<<"Couldron cost: "<<merchant.getCauldronPrice()<<endl;
    cout<<"Stone Club cost: "<<merchant.getStoneClubPrice()<<endl;
    cout<<"Iron Spear cost: "<<merchant.getIronSpearPrice()<<endl;
    cout<<"Mythril Rapier cost: "<<merchant.getMythrilRapierPrice()<<endl;
    cout<<"Flaming Axe cost: "<<merchant.getFlamingAxePrice()<<endl;
    cout<<"Vorpal Sword cost: "<<merchant.getVorpalSwordPrice()<<endl;
    cout<<"Armor Suit cost: "<<merchant.getArmorSuitPrice()<<endl;
    cout<<"Silver Ring Value cost: "<<merchant.getSilverRingValue()<<endl;
    cout<<"Ruby Necklace cost: "<<merchant.getRubyNecklaceValue()<<endl;
    cout<<"Emerald Bracelet cost: "<<merchant.getEmeraldBraceletValue()<<endl;
    cout<<"Diamond Circlet cost: "<<merchant.getDiamondCircletValue()<<endl;
    cout<<"Gem Goblet cost: "<<merchant.getGemGobletValue()<<endl;
    merchant.setRoomsCleared(3);
    merchant.incrementRoomsCleared();
    cout<<"Number of rooms cleared: "<<merchant.getRoomsCleared()<<endl;
    
    cout<<endl<<endl<<endl;
   
    cout<<"Team Member Info:"<<endl<<endl;
    
    member.setFullness(int);
    member.setName(std::string);
    member.incrementFullness();
    member.decrementFullness();
    cout<<"Team Member's fullness: "<<member.getFullness();
    cout<<"Team Member's name: "<<member.getName();
    
    cout<<endl<<endl<<endl
        
    cout<<"Game Statistics: "<<endl<<endl;
    
    stats.setRoomsCleared(3);
    stats.setNumKeys(3);
    stats.setAngerlevel(50);
    stats.setGoldAmount(20);
    stats.setIngredients(0);
    stats.setCeramicPots(12);
    stats.setFryingPans(10);
    stats.setCauldrons(90); 
    stats.setStoneClubs(8);
    stats.setIronSpears(90);
    stats.setMythrilRapiers(93);
    stats.setFlamingAxes(85);
    stats.setVorpalSwords(82);
    stats.setArmor(12);
    stats.setSilverRings(15);
    stats.setRubyNecklaces(1);
    stats.setEmeraldBracelets(1);
    stats.setDiamondCirclets(2);
    stats.setGemGoblets(27);
    stats.setPlayerFullness(5);
    stats.setMember1Fullness(1);
    stats.setMember2Fullness(1);
    stats.setMember3Fullness(4);
    stats.setMember4Fullness(.5);
    stats.incrementRoomsCleared();
    stats.incrementRoomsCleared();
    stats.incrementRoomsCleared();
    stats.decrementRoomsCleared();
    stats.incrementNumKeys();
    stats.incrementNumKeys();
    stats.incrementNumKeys();
    stats.decrementNumKeys();
    stats.incrementAngerlevel();
    stats.incrementAngerlevel();
    stats.incrementAngerlevel();
    stats.decrementAngerlevel();
    stats.incrementPlayerFullness();
    stats.incrementPlayerFullness();
    stats.incrementPlayerFullness();
    stats.decrementPlayerFullness();
    stats.incrementMember1Fullness();
    stats.incrementMember1Fullness();
    stats.incrementMember1Fullness();
    stats.decrementMember1Fullness();
    stats.incrementMember2Fullness();
    stats.incrementMember2Fullness();
    stats.incrementMember2Fullness();
    stats.decrementMember2Fullness();
    stats.incrementMember3Fullness();
    stats.incrementMember3Fullness();
    stats.incrementMember3Fullness();
    stats.decrementMember3Fullness();
    stats.incrementMember4Fullness();
    stats.incrementMember4Fullness();
    stats.incrementMember4Fullness();
    stats.decrementMember4Fullness();
    cout<<"Rooms cleared: "<<stats.getRoomsCleared()<<endl;
    cout<<"Number of Keys: "<<stats.getNumKeys()<<endl;
    cout<<"Sorcer's Anger Level: "<<stats.getAngerlevel()<<endl;
    cout<<"Party's Gold Amount"<<stats.getGoldAmount()<<endl;
    cout<<"Party's Ingredients"<<stats.getIngredients()<<endl;
    cout<<"Party's Ceramic Pots"<<stats.getCeramicPots()<<endl;
    cout<<"Party's Frying Pans"<<stats.getFryingPans()<<endl;
    cout<<"Party's Cauldrons"<<stats.getCauldrons()<<endl;
    cout<<"Party's Stone Clubs"<<stats.getStoneClubs()<<endl;
    cout<<"Party's Iron Spears"<<stats.getIronSpears()<<endl;
    cout<<"Party's Mythril Rapiers"<<stats.getMythrilRapiers()<<endl;
    cout<<"Party's Flaming Axes"<<stats.getFlamingAxes()<<endl;
    cout<<"Party's Vorpal Swords: "<<stats.getVorpalSwords()<<endl;
    cout<<"Party's Armour: "<<stats.getArmor()<<endl;
    cout<<"Party's Silver Rings: "<<stats.getSilverRings()<<endl;
    cout<<"Party's Ruby Necklaces: "<<stats.getRubyNecklaces()<<endl;
    cout<<"Party's Emerald Bracelets: "<<stats.getEmeraldBracelets()<<endl;
    cout<<"Party's Diamond Circlets"<<stats.getDiamondCirclets()<<endl;
    cout<<"Party's Gem Goblets"<<stats.getGemGoblets()<<endl;
    cout<<"Player's Fullness"<<stats.getPlayerFullness()<<endl;
    cout<<"1st Team Members's Fullness: "<<stats.getMember1Fullness()<<endl;
    cout<<"1st Team Members's Fullness: "<<stats.getMember2Fullness()<<endl;
    cout<<"1st Team Members's Fullness: "<<stats.getMember3Fullness()<<endl;
    cout<<"1st Team Members's Fullness: "<<stats.getMember4Fullness()<<endl;
    return 0;
}

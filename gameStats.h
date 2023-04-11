#ifndef GAMESTATS_H
#define GAMESTATS_H

class GameStats
{
    private:
        //Game stats
        int roomsCleared;
        int numKeys;
        int angerLevel;

        //Inventory
        int gold;
        int ingredients;
        int ceramicPots;
        int fryingPans;
        int cauldrons;
        int stoneClubs;
        int ironSpears;
        int mythrilRapiers;
        int flamingAxes;
        int vorpalSwords;
        int armor;
        int silverRings;
        int rubyNecklaces;
        int emeraldBracelets;
        int diamondCirclets;
        int gemGoblets;

        //Fullness levels
        int playerFullness;
        int member1Fullness;
        int member2Fullness;
        int member3Fullness;
        int member4Fullness;

    public:

        //Constructor
        GameStats();

        //Getters

        int getRoomsCleared();
        int getNumKeys();
        int getAngerlevel();
        int getGoldAmount();
        int getIngredients();
        int getCeramicPots();
        int getFryingPans();
        int getCauldrons();
        int getStoneClubs();
        int getIronSpears();
        int getMythrilRapiers();
        int getFlamingAxes();
        int getVorpalSwords();
        int getArmor();
        int getSilverRings();
        int getRubyNecklaces();
        int getEmeraldBracelets();
        int getDiamondCirclets();
        int getGemGoblets();
        int getPlayerFullness();
        int getMember1Fullness();
        int getMember2Fullness();
        int getMember3Fullness();
        int getMember4Fullness();

        //Setters
        void setRoomsCleared(int);
        void setNumKeys(int);
        void setAngerlevel(int);
        void setGoldAmount(int);
        void setIngredients(int);
        void setCeramicPots(int);
        void setFryingPans(int);
        void setCauldrons(int); 
        void setStoneClubs(int);
        void setIronSpears(int);
        void setMythrilRapiers(int);
        void setFlamingAxes(int);
        void setVorpalSwords(int);
        void setArmor(int);
        void setSilverRings(int);
        void setRubyNecklaces(int);
        void setEmeraldBracelets(int);
        void setDiamondCirclets(int);
        void setGemGoblets(int);
        void setPlayerFullness(int);
        void setMember1Fullness(int);
        void setMember2Fullness(int);
        void setMember3Fullness(int);
        void setMember4Fullness(int);
        
        //Incremental methods

        void incrementRoomsCleared();
        void decrementRoomsCleared();

        void incrementNumKeys();
        void decrementNumKeys();

        void incrementAngerlevel();
        void decrementAngerlevel();

        void incrementPlayerFullness();
        void decrementPlayerFullness();

        void incrementMember1Fullness();
        void decrementMember1Fullness();

        void incrementMember2Fullness();
        void decrementMember2Fullness();

        void incrementMember3Fullness();
        void decrementMember3Fullness();

        void incrementMember4Fullness();
        void decrementMember4Fullness();
};

#endif
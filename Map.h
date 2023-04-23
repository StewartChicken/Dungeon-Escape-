#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "time.h"

using namespace std;

class Map
{
private:
    const char moveUpKey = 'w';
    const char moveDownKey = 's';
    const char moveRightKey = 'd';
    const char moveLeftKey = 'a';
    const char exploreSpaceKey = 'e';

    const char UNEXPLORED = '-'; // marker for unexplored spaces
    const char EXPLORED = ' ';   // marker for explored spaces
    const char ROOM = 'R';       // marker for room locations
    const char NPC = 'N';        // marker for NPC locations
    const char PARTY = 'X';      // marker for party position
    const char EXIT = 'E';       // marker for dungeon exit

    static const int numRows = 12; // number of rows in map
    static const int numCols = 12; // number of columns in map
    static const int numNPCs = 5;  // max non-player characters
    static const int numRooms = 5; // max number of rooms

    //Contains all the position data for the map as well as
    //the isFound status for each NPC
    //player row, player col, exit row, exit col, 
    //(room row, room col) * 5,
    //(NPC row, NPC col) * 5
    //(NPC isFound status) * 5
    vector<int> positionData;

    int numSpacesExplored = 0;
    bool exploredData[numRows][numCols]; //Is a space explored
    bool clearedData[numRows][numCols]; //Is a room/NPC cleared (no longer accessible)
    char mapData[numRows][numCols]; // stores the character that will be shown at a given (row,col)

public:
    Map();//Constructor

    //Map rendering functions
    void resetMap();//Fills map with empty spaces
    void updateMap(); //Fill map with the position data
    void calculatePositionData(); //Fill map with position data of entities
    void checkOverlap(); //Check for overlap in position data
    void displayMap(); //Render map to terminal

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getDungeonExitRow();
    int getDungeonExitCol();
    int getRoomCount();
    int getNPCCount();
    int getNumRows();
    int getNumCols();
    int getNumSpacesExplored();
    bool isOnMap(int row, int col);
    bool isNPCLocation(int row, int col);
    bool isRoomLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);
    bool isDungeonExit(int row, int col);
    char getMoveUpKey();
    char getMoveDownKey();
    char getMoveRightKey();
    char getMoveLeftKey();
    char getExploreKey();
    bool isMovementKey(char);

    // setters
    void setPlayerPosition(int row, int col);
    void setDungeonExit(int row, int col);

    // other
    void incrementNumSpacesExplored();
    void clearSpace(int row, int col);
    void exploreSpace(int row, int col);

    //debugging functions
    void printPositionData(); //Prints position data 
};

#endif
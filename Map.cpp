#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Map.h"

using namespace std;

Map::Map()
{
    //Calculates position of each map entity - Player, Exit, NPC, Room
    fillPositionData();
    checkOverlap();

    resetMap();
    fillInitialMapPositionData();
}

void Map::displayMap()
{
    for(int i{}; i < numRows; i ++)
    {
        for(int j{}; j < numCols; j ++)
        {
            cout << mapData[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::fillPositionData()
{
    //Random number generator seed
    srand(time(0));

    //Adds initial player position to position vector
    positionData.push_back(0);
    positionData.push_back(0);

    //Adds exit and room position data to the positionData vector
    //There are 12 iterations because the exit has two values 
    // and each of the five rooms have 2 values. 2 + 5*2 = 12.
    for(int i = 0; i < 12; i ++)
    {
        positionData.push_back(rand() % 12);
        
        //Debugging Print 
        //cout << "ROOM PUSH ROW, COL: (" << randVal << ", " << randVal2 << ")\n";
    }

    //Adds NPC position to positionData vector
    for(int i = 0; i < 5; i ++)
    {

        positionData.push_back(rand() % 12);
        positionData.push_back(rand() % 12);

        //Debugging Print
        //cout << "NPC PUSH ROW, COL: (" << rand1 << ", " << rand2 << ")\n";
    }


    //Adds NPC isFound status to positionData vector
    for(int i{}; i < 5; i ++)
    {
        positionData.push_back(0);
    }

}

//Checks for overlapping coordinates in the map vector
void Map::checkOverlap()
{
    //Tracks index of position currently being checked
    int currIndex = 0;

    //If vector is clear of duplicate coordinates
    bool isClear = true;

    while(true)
    {
        //If the current index is further into the vector than the position data
        if(currIndex >= positionData.size() - 5)
        {
            break;
        }

        //cout << "Current index: " << currIndex << " | Current Index Coordinates: (" << positionData.at(currIndex) << " , " <<
        //positionData.at(currIndex + 1) << ")" << endl;

        //Starts at the next pair of coordinates and iterates until the isFound data in the vector
        for(int i = currIndex + 2; i < positionData.size() - 5; i +=2)
        {
            //cout << "I index: " << i << " | Current Index Coordinates: (" << positionData.at(i) << " , " <<
            //positionData.at(i + 1) << ")\n";

            //If coordinate is duplicate, assigns new random values to coordinates
            //sets isClear to false meaning that the current coordinate is in question
            //Breaks out of for loop and enters next iteration of while loop which 
            // will essentially restart the for loop for the same index
            if(positionData.at(currIndex) == positionData.at(i) && positionData.at(currIndex + 1) == positionData.at(i + 1))
            {
                //Debugging Print
                //cout << "DUPLICATES FOUND : (" << positionData.at(currIndex) << ", " << positionData.at(currIndex + 1)
                //<< ") Matches (" << positionData.at(i) << ", " << positionData.at(i + 1) << ")\n";
                
                positionData.at(i) = rand() % 12;
                positionData.at(i + 1) = rand() % 12;
                isClear = false;
                break;
            }

            //If no duplicate is found, then the for loop is able to reach this part
            //of the code and the isClear boolean is set to true
            isClear = true;
        }

        //After exiting the for loop, if isClear is true, it means that this pair of coordinates
        //are not duplicates with any other coordinate pair. The currIndex variable will be incrememnted
        //by two. If isNot is false, it means that the for loop found a duplicate coordinate pair 
        //and is attempting to restart the for-loop within the next iteration of the while loop after 
        //the duplicate coordinates have been reassigned new values. 
        if(isClear)
        {
            currIndex += 2;
        }
    }
}

//Prints all the position data for each entity on the map
// - mostly for debugging
void Map::printPositionData()
{
    cout << "Player row, col: " << positionData.at(0) << ", " << positionData.at(1) << endl;
    cout << "Exit row, col: " << positionData.at(2) << ", " << positionData.at(3) << endl;

    for(int i{}; i < 5; i ++)
    {
        cout << "Room" << i << " row, col: " << positionData.at(4 + 2*i) << ", " << positionData.at(5 + 2*i) << endl;
    }

    for(int i{}; i < 5; i ++)
    {
        cout << "NPC" << i << " row, col: " << positionData.at(14 + 2*i) << ", " << 
        positionData.at(15 + 2*i) << endl;
    }

    for(int i{}; i < 5; i ++)
    {
        cout << "NPC" << i << " IsFound: " << positionData.at(24 + i) << endl;
    }
}

//Sets entirety of the ma to unexplored
void Map::resetMap()
{
    for(int i{}; i < numRows; i ++)
    {
        for(int j{}; j < numCols; j ++)
        {
            mapData[i][j] = '-';
        }
    }
}

void Map::fillInitialMapPositionData()
{
    //Set player and exit characters on map
    mapData[positionData.at(0)][positionData[1]] = 'X';
    mapData[positionData.at(2)][positionData.at(3)] = 'E';

    //Set Room data on map
    for(int i{}; i < 5; i ++)
    {
        mapData[positionData.at(4 + 2*i)][positionData.at(5 + 2*i)] = 'R';
    }

    //Set NPC data on map
    for(int i{}; i < 5; i ++)
    {
        mapData[positionData.at(14 + 2*i)][positionData.at(15 + 2*i)] = 'N';
    }
}

//Setters

void Map::setPlayerPosition(int row, int col)
{

}

//Getters 

int Map::getPlayerRow()
{
    return positionData.at(0);
}

int Map::getPlayerCol()
{
    return positionData.at(1);
}

int Map::getDungeonExitRow()
{
    return positionData.at(2);
}

int Map::getDungeonExitCol()
{
    return positionData.at(3);
}

int Map::getRoomCount()
{
    return numRooms;
}

int Map::getNPCCount()
{
    return numNPCs;
}

int Map::getNumRows()
{
    return numRows;
}

int Map::getNumCols()
{
    return numCols;
}

bool Map::isOnMap(int row, int col)
{
    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}

bool Map::isNPCLocation(int row, int col)
{
    for(int i{}; i < 5; i ++)
    {
        if(positionData.at(14 + 2*i) == row && positionData.at(15 + 2*i) == col)
        {
            return true;
        }
    }

    return false;
}

bool Map::isRoomLocation(int row, int col)
{
    for(int i{}; i < 5; i ++)
    {
        if(positionData.at(4 + 2*i) == row && positionData.at(5 + 2*i) == col)
        {
            return true;
        }
    }

    return false;
}

bool Map::isExplored(int row, int col)
{
    return(mapData[row][col] == ' ');
}

bool Map::isFreeSpace(int row, int col)
{
    return(mapData[row][col] == '-');
}

bool Map::isDungeonExit(int row, int col)
{
    return(row == positionData.at(2) && col == positionData.at(3));
}
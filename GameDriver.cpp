/**
 * This class acts as the driver for the entire game
 * It instantiates a "Game" object and calls its various functions which control 
 * the various 'states' of the game
 * 
 */

#include "Game.h"

// Main
int main()
{
    Game game; // Instantiate game object

    Player player; // Create player object
    Merchant merchant; // Create merchant object
 
    game.start(player, merchant); // Start the game

    game.merchantInteraction(player, merchant); // First interaction between the player and the merchant

    game.movementPhase(player, merchant); // Progress to map interaction and the actual game

    game.endGame(player, merchant);//Initiates end game sequence
    
    return 0;
}

#include "Game.h"
#include "Monster.h"

int main()
{
    Game game;

    game.start();

    Player tempPlayer = game.getPlayer();
    Merchant tempMerchant = game.getMerchant();

    game.merchantInteraction(tempPlayer, tempMerchant);

    game.movementPhase();

    return 0;
}
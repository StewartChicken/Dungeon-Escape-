#include "Game.h"
#include "Monster.h"

int main()
{
    Game game;

    
    Player player;
    Merchant merchant;

    game.start(player, merchant);

    game.merchantInteraction(player, merchant);

    game.movementPhase(player, merchant);

    return 0;
}
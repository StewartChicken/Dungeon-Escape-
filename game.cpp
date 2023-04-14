#include <iostream>
#include "game.h"

void Game::start()
{
    player.setName(prompts.playerNamePrompt());
}
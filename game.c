#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "list.h"

void startGame(gameStructRef game)
{
    game->currentPlayer = 0;
    nodeRef first_ref = newNode(0, 0, 0, 0);
    addNode(first_ref, newNode(0, 1, 0, 0));
    
}

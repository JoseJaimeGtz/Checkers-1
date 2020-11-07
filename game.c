#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void startGame(gameStructRef game)
{
    game->board->currentPlayer = 0;
    game->board->boardMatrix[0][0] = malloc(sizeof(pieceStructRef));
    game->board->boardMatrix[0][0].x = 0;
    game->board->piece->y
}

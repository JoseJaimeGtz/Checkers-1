#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"

// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY, int possibleX, int possibleY)
{
    int type = game->board[currentX][currentY]->type;
    int color = game->board[currentX][currentY]->color;
    if(game->board[possibleX][possibleY]->type == 0){ // 0 = empty slot
        return 1;
    } else {
        return 0;
    }
}

// considerando que el movimiento si es válido
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY)
{
    game->board[newX][newY]->playerHolder = game->board[currentX][currentY]->playerHolder;
    game->board[newX][newY]->type = game->board[currentX][currentY]->type;

    game->board[currentX][currentY]->playerHolder = 0;
    game->board[currentX][currentY]->type = 0;
}
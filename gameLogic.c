#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"

// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY, int possibleX, int possibleY)
{
    // revisar si la posición está vacía
    if(game->board[possibleX][possibleY]->type == 0){
        return 1;
    } else {
        // revisar si a la posición donde se desea mover, hay otra ficha del equipo contrario
        if(game->board[possibleX][possibleY]->playerHolder != game->board[currentX][currentY]->playerHolder && game->board[possibleX][possibleY]->playerHolder != 0){
            //
            // comer ficha [agregar código]
            //
        } else {
            // el movimiento no es válido
            return 0;
        }
    }
}

// considerando que el movimiento si es válido
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY)
{
    // asignar al nuevo lugar la ficha
    game->board[newX][newY]->playerHolder = game->board[currentX][currentY]->playerHolder;
    game->board[newX][newY]->type = game->board[currentX][currentY]->type;

    // poner la ficha antigua vacia
    game->board[currentX][currentY]->playerHolder = 0;
    game->board[currentX][currentY]->type = 0;
}
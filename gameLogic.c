#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"
/*
void seleccionarFicha(){
    if(game.turno = negras)
        if normal
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
        else
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
            isPossible(game, currentX, currentY, currentX-1, currentY+1);
            isPossible(game, currentX, currentY, currentX-1, currentY-1);
    else if blancas
        if normal
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
        else
            isPossible(game, currentX, currentY, currentX+1, currentY+1);
            isPossible(game, currentX, currentY, currentX+1, currentY-1);
            isPossible(game, currentX, currentY, currentX-1, currentY+1);
            isPossible(game, currentX, currentY, currentX-1, currentY-1);
}
*/
// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY)
{ // 1,2    2,1
    // nivel de abstracción superior
    //
    if(game->currentPlayer == "blancas"){
        // verifica si puede avanzar
        if(currentY+1 <= game->boardsize){

            if(game->board[currentX+1][currentY-1]->playerHolder == 0){
                // no se, espero haberte ayudado
                // camelCase master
            }
            if(game->board[currentX-1][currentY-1]->playerHolder == 0){

            }
        }
    } else if(game->currentPlayer == "negras") {
        // suicide
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
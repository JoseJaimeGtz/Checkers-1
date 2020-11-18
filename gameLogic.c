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
{
    // nivel de abstracción superior
    //
    if(game->currentPlayer == "blancas"){
        // verifica si puede avanzar
        if(currentY+1 <= game->boardsize){
            // verifica si la izquierda es valida
            if(currentX+1 <= game->boardsize){
                if (game->board[currentX+1][currentY+1]->playerHolder == 0){ // si esta libre en la posicion siguiente
                    // se ilumina la izquierda disponible
                } else if (game->board[currentX+1][currentY+1]->playerHolder == 1){ // si hay una negra en la siguiente posicion
                    // si en 2 espacios es valido
                    if(currentY+2 <= game->boardsize && currentX+2 <= game->boardsize) { // si sigue dentro del tablero
                        if(game->board[currentX+2][currentY+2]->playerHolder == 0){ // si en 2 posiciones esta libre
                            // se ilumina 2 a la izquierda y se come a la ficha negra
                            // aqui puede volver a llamarse esta funcion
                        }
                    }
                } // aqui es si habia una ficha blanca
            }
            // verifica si la derecha es valida
            if(currentX-1 >= 1){
                if (game->board[currentX-1][currentY+1]->playerHolder == 0){
                    // se ilumina la derecha disponible
                }  else if (game->board[currentX-1][currentY+1]->playerHolder == 1) { // si hay una negra
                    // si en 2 espacios es valido
                    if(currentY+2 <= game->boardsize && currentX-2 >= 1){
                        if (game->board[currentX-2][currentY+2]->playerHolder == 0){
                            // se ilumina 2 a la derecha y se come la ficha blanca
                            // aqui puede volver a llamarse esta funcion
                        }
                    }
                }
            }
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;

            if(currentY-1 >= 1){
                if(currentX+1 <= game->boardsize){ // verifica si la izquierda es valida
                    if (game->board[currentX+1][currentY-1]->playerHolder == 0){
                        // se ilumina la izquierda disponible
                    } else if (game->board[currentX+1][currentY-1]->playerHolder == 1){ // si hay una ficha negra en la sig posicion
                        // si en 2 espacios es valido
                        if(currentY-2 >= 1 && currentX+2 <= game->boardsize) { // izquierda
                            if(game->board[currentX+2][currentY-2]->playerHolder == 0){
                                // se ilumina 2 a la izquierda y se come a la ficha negra
                                // aqui puede volver a llamarse esta funcion
                            }
                        }
                    }
                }
                // verifica si la derecha es valida
                if(currentX-1 >= 1){
                    if (game->board[currentX-1][currentY-1]->playerHolder == 0){
                        // se ilumina la derecha disponible
                    }  else if (game->board[currentX-1][currentY+1]->playerHolder == 1) { // si hay una ficha negra
                        if(currentY-2 >= 1 && currentX-2 >= 1){// si en 2 espacios es valido
                            if (game->board[currentX-2][currentY-2]->playerHolder == 0){
                                // se ilumina 2 a la derecha y se come la ficha blanca
                                // aqui puede volver a llamarse esta funcion
                            }
                        }
                    }
                }
            }
        }
    } else if(game->currentPlayer == "negras") {

        if(currentY-1 >= 1){
            if(currentX+1 <= game->boardsize){ // verifica si la izquierda es valida
                if (game->board[currentX+1][currentY-1]->playerHolder == 0){
                    // se ilumina la izquierda disponible
                } else if (game->board[currentX+1][currentY-1]->playerHolder == 1){ // si hay una ficha negra en la sig posicion
                    // si en 2 espacios es valido
                    if(currentY-2 >= 1 && currentX+2 <= game->boardsize) { // izquierda
                        if(game->board[currentX+2][currentY-2]->playerHolder == 0){
                            // se ilumina 2 a la izquierda y se come a la ficha negra
                            // aqui puede volver a llamarse esta funcion
                        }
                    }
                }
            }
            // verifica si la derecha es valida
            if(currentX-1 >= 1){
                if (game->board[currentX-1][currentY-1]->playerHolder == 0){
                    // se ilumina la derecha disponible
                }  else if (game->board[currentX-1][currentY+1]->playerHolder == 1) { // si hay una ficha negra
                    if(currentY-2 >= 1 && currentX-2 >= 1){// si en 2 espacios es valido
                        if (game->board[currentX-2][currentY-2]->playerHolder == 0){
                            // se ilumina 2 a la derecha y se come la ficha blanca
                            // aqui puede volver a llamarse esta funcion
                        }
                    }
                }
            }
        } else {
            game->board[currentX][currentY]->type = 2;

            if(currentY+1 <= game->boardsize){
                // verifica si la izquierda es valida
                if(currentX+1 <= game->boardsize){
                    if (game->board[currentX+1][currentY+1]->playerHolder == 0){ // si esta libre en la posicion siguiente
                        // se ilumina la izquierda disponible
                    } else if (game->board[currentX+1][currentY+1]->playerHolder == 1){ // si hay una negra en la siguiente posicion
                        // si en 2 espacios es valido
                        if(currentY+2 <= game->boardsize && currentX+2 <= game->boardsize) { // si sigue dentro del tablero
                            if(game->board[currentX+2][currentY+2]->playerHolder == 0){ // si en 2 posiciones esta libre
                                // se ilumina 2 a la izquierda y se come a la ficha negra
                                // aqui puede volver a llamarse esta funcion
                            }
                        }
                    } // aqui es si habia una ficha blanca
                }
                // verifica si la derecha es valida
                if(currentX-1 >= 1){
                    if (game->board[currentX-1][currentY+1]->playerHolder == 0){
                        // se ilumina la derecha disponible
                    }  else if (game->board[currentX-1][currentY+1]->playerHolder == 1) { // si hay una negra
                        // si en 2 espacios es valido
                        if(currentY+2 <= game->boardsize && currentX-2 >= 1){
                            if (game->board[currentX-2][currentY+2]->playerHolder == 0){
                                // se ilumina 2 a la derecha y se come la ficha blanca
                                // aqui puede volver a llamarse esta funcion
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
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
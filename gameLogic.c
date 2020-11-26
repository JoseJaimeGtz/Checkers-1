#include "checkersLibrary.h"

// considerando que el movimiento si es válido
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY)
{
    // asignar al nuevo lugar la ficha
    game->board[newX][newY]->color = game->board[currentX][currentY]->color;
    game->board[newX][newY]->type = game->board[currentX][currentY]->type;

    // poner la ficha antigua vacia
    game->board[currentX][currentY]->color = 0;
    game->board[currentX][currentY]->type = 0;
}

// Verifica si existe un posible movimiento hacia abajo del tablero
// tanto como en diagonal izquierda como la derecha
// y tambien verifica si se puede comer una ficha
int pieceDown(gameStructRef game, int currentX, int currentY, int op_piese){
    int move = 0;
    // verifica si la izquierda es valida
    if(currentX+1 <= game->boardsize){
        if (game->board[currentX+1][currentY+1]->color == 0){ // si esta libre en la posicion siguiente
            // se ilumina la izquierda disponible
            move = 1;
        } else if (game->board[currentX+1][currentY+1]->color == op_piese){ // si hay una negra en la siguiente posicion
            // si en 2 espacios es valido
            if(currentY+2 <= game->boardsize && currentX+2 <= game->boardsize) { // si sigue dentro del tablero
                if(game->board[currentX+2][currentY+2]->color == 0){ // si en 2 posiciones esta libre
                    // se ilumina 2 a la izquierda y se come a la ficha negra
                    // aqui puede volver a llamarse esta funcion
                    move = 1;
                }
            }
        } // aqui es si habia una ficha blanca
    }
    // verifica si la derecha es valida
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY+1]->color == 0){
            // se ilumina la derecha disponible
            move = 1;
        }  else if (game->board[currentX-1][currentY+1]->color == op_piese) { // si hay una negra
            // si en 2 espacios es valido
            if(currentY+2 <= game->boardsize && currentX-2 >= 1){
                if (game->board[currentX-2][currentY+2]->color == 0){
                    // se ilumina 2 a la derecha y se come la ficha blanca
                    // aqui puede volver a llamarse esta funcion
                    move = 1;
                }
            }
        }
    }
    return move;
}

// Verifica si existe un posible movimiento hacia arriba del tablero
// tanto como en diagonal izquierda como la derecha
// y tambien verifica si se puede comer una ficha
int pieceUp(gameStructRef game, int currentX, int currentY, int op_piese) {
    int move = 0;
    if(currentX+1 <= game->boardsize){ // verifica si la izquierda es valida
        if (game->board[currentX+1][currentY-1]->color == 0){
            // se ilumina la izquierda disponible
            move = 1;
        } else if (game->board[currentX+1][currentY-1]->color == op_piese){ // si hay una ficha negra en la sig posicion
            // si en 2 espacios es valido
            if(currentY-2 >= 1 && currentX+2 <= game->boardsize) { // izquierda
                if(game->board[currentX+2][currentY-2]->color == 0){
                    // se ilumina 2 a la izquierda y se come a la ficha negra
                    // aqui puede volver a llamarse esta funcion
                    move = 1;
                }
            }
        }
    }
    // verifica si la derecha es valida
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY-1]->color == 0){
            // se ilumina la derecha disponible
            move = 1;
        }  else if (game->board[currentX-1][currentY+1]->color == op_piese) { // si hay una ficha negra
            if(currentY-2 >= 1 && currentX-2 >= 1){// si en 2 espacios es valido
                if (game->board[currentX-2][currentY-2]->color == 0){
                    // se ilumina 2 a la derecha y se come la ficha blanca
                    // aqui puede volver a llamarse esta funcion
                    move = 1;
                }
            }
        }
    }
    return move;
}

// esta función se correrá en todas las fichas
// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY)
{
    // nivel de abstracción superior
    if(game->currentPlayer == "blancas"){
        if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
            pieceDown(game, currentX, currentY, 1);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY-1 >= 1){ // verifica si se puede mover hacia adelante
                pieceUp(game, currentX, currentY, 1);
            }
        }
    } else if(game->currentPlayer == "negras") { // porque el rodri luego se confunde
        if(currentY-1 >= 1){
            pieceUp(game, currentX, currentY, 2);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
                pieceUp(game, currentX, currentY, 2);
            }
        }
    }
    return 0;
}

// Se necesitan pasar los valores guardados de las fichas en esta funcion
// en este momento la función cada vez que se llama esta en la posición inicial del tablero
void turnPieces(gameStructRef game, int x, int y){
    if(game->currentPlayer == "blancas"){
        if(game->board[x][y]->color = 2){
            isPossible(game, x, y);
        }
        
        /*for(int y = 1; y <= game->boardsize/2-1; y++){ // verifica todas las fichas creadas en y
            for(int x = 1; x <= game->boardsize/2; x++){ // verifica todas las fichas creadas en x
                if (y<=game->boardsize/2-1){
                    if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                        // isPossible(game, x, y); // tamal xdxd 
                        isPossible(game, game->board[x][y]->x, y); // tamal xdxd salu2
                    }
                }
            }
        }*/
    } else if (game->currentPlayer == "negras") {
        if(game->board[x][y]->color = 1){
            isPossible(game, x, y);
        }
        /*for(int y = game->boardsize/2+2; y <= game->boardsize; y++){ // verifica todas las fichas creadas en y apartir de su aparicion
            for(int x = game->boardsize/2; x <= game->boardsize; x++){
                if (y>=game->boardsize/2+2){
                    if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                        isPossible(game, x, y);
                    }
                }
            }
        }*/
    }
}
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
int pieceDown(gameStructRef game, int currentX, int currentY, int op_piese, int draw){
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
int pieceUp(gameStructRef game, int currentX, int currentY, int op_piese, int draw) {
    int move = 0;
    fprintf(stderr,"\n\033[1;32m (%d <= %d) ??? \n", currentX+1, game->boardsize);
    fprintf(stderr,"Verifica la derecha\n");
    if(currentX+1 <= game->boardsize){ // verifica si la derecha es valida
        fprintf(stderr,"primer if\n");
        if (game->board[currentX+1][currentY-1]->color == 0){
            fprintf(stderr,"\n\033[0;35m Pos actual (%d,%d)\n", currentX, currentY);
            fprintf(stderr,"\033[0;36m Pos siguiente (%d,%d)\n", currentX+1, currentY-1);
            fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[currentX][currentY]->color, game->board[currentX+1][currentY-1]->color);
            int posx = game->board[currentX][currentY]->circle.x+80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            game->board[currentX+1][currentY-1]->type = 3;
            fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                DrawRectangle(posx, posy, w, h, YELLOW);
            } else {
                DrawRectangle(posx, posy, w, h, BROWN);
            }
            move = 1;
        } else if (game->board[currentX+1][currentY-1]->color == op_piese){ // si hay una ficha negra en la sig posicion
            // si en 2 espacios es valido
            if(currentY-2 >= 1 && currentX+2 <= game->boardsize) { // izquierda
                if(game->board[currentX+2][currentY-2]->color == 0){
                    // se ilumina 2 a la izquierda y se come a la ficha negra
                    // aqui puede volver a llamarse esta funcion
                    int posx = game->board[currentX][currentY]->circle.x+160;
                    int posy = game->board[currentX][currentY]->circle.y-160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    game->board[currentX+2][currentY-2]->type = 3;
                    //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        DrawRectangle(posx, posy, w, h, YELLOW);
                    } else {
                        DrawRectangle(posx, posy, w, h, BROWN);
                    }
                    move = 1;
                }
            }
        } else { // hay una ficha de tu color adelante de ti
            // fprintf racista
            fprintf(stderr,"hay una ficha de tu mismo color adelante de ti!(derecha)\n");
        }
    }
    fprintf(stderr,"Verifica la izquierda\n");
    fprintf(stderr,"\n\033[1;32m (%d >= %d) ??? \n", currentX-1, 1);
    // verifica si la izquierda es valida
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY-1]->color == 0){
            // se ilumina la derecha disponible
            int posx = game->board[currentX][currentY]->circle.x-80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            game->board[currentX-1][currentY-1]->type = 3;
            //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                DrawRectangle(posx, posy, w, h, YELLOW);
            } else {
                DrawRectangle(posx, posy, w, h, BROWN);
            }
            move = 1;
        }  else if (game->board[currentX-1][currentY-1]->color == op_piese) { // si hay una ficha negra
            if(currentY-2 >= 1 && currentX-2 >= 1){// si en 2 espacios es valido
                if (game->board[currentX-2][currentY-2]->color == 0){
                    // se ilumina 2 a la derecha y se come la ficha blanca
                    // aqui puede volver a llamarse esta funcion
                    int posx = game->board[currentX][currentY]->circle.x-160;
                    int posy = game->board[currentX][currentY]->circle.y-160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    game->board[currentX-2][currentY-2]->type = 3;
                    fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        DrawRectangle(posx, posy, w, h, YELLOW);
                    } else {
                        DrawRectangle(posx, posy, w, h, BROWN);
                    }
                    move = 1;
                }
            }
        } else { // hay una ficha de tu color adelante de ti
            // fprintf racista
            fprintf(stderr,"hay una ficha de tu mismo color adelante de ti!(izquierda)\n");
        }
    }
    return move;
}

// esta función se correrá en todas las fichas
// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
int isPossible(gameStructRef game, int currentX, int currentY)
{
    // nivel de abstracción superior
    if(game->currentPlayer){ // blancas
        if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
            fprintf(stderr, "\033[0;31m   pieceDown\n");
            pieceDown(game, currentX, currentY, 1, 1);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY-1 >= 1){ // verifica si se puede mover hacia adelante
                fprintf(stderr, "\033[0;31m   pieceUp\n");
                pieceUp(game, currentX, currentY, 1, 1); // le pasamos el negro
            }
        }
    } else { // negras
        if(currentY-1 >= 1){ // si no es el limite superior
            pieceUp(game, currentX, currentY, 2, 1);
            fprintf(stderr, "\033[0;31m   pieceUp\n");
            fprintf(stderr, "\033[0;31m   isPossible->pieceUp\n");
        } else {
            // Significa que mi barrio me respalda
            game->board[currentX][currentY]->type = 2;
            if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
                pieceUp(game, currentX, currentY, 2, 1); // le pasamos el blanco
                fprintf(stderr, "\033[0;31m   pieceUp\n");
            }
        }
    }
    return 0;
}

// Se necesitan pasar los valores guardados de las fichas en esta funcion
// en este momento la función cada vez que se llama esta en la posición inicial del tablero
void turnPieces(gameStructRef game, int x, int y){
    fprintf(stderr, "\033[0;32mit works? [%d]\n", game->currentPlayer);
    if(game->currentPlayer){
        fprintf(stderr, "\033[0;34m turno blancas\n");
        if(game->board[x][y]->color = 2){
            isPossible(game, x, y);
        }
    } else {
        fprintf(stderr, "\033[0;34m turno negras\n");
        if(game->board[x][y]->color = 1){
            isPossible(game, x, y);
        }
    }
}
#include "checkersLibrary.h"

void deleteAll(gameStructRef game)
{
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                if(game->board[x][y]->type == 3){
                    game->board[x][y]->type = 0;
                }
            }
        }
    }
}

void winner(gameStructRef game){
    fprintf(stderr, "Piezas negras restantes: [%d]\n", game->totalBlackPieces);
    fprintf(stderr, "Piezas blantas restantes: [%d]\n", game->totalWhitePieces);
    if(game->totalWhitePieces == 0){
        fprintf(stderr, "Ganaron las Negras!!!!\n");
    }
    if(game->totalBlackPieces == 0){
        fprintf(stderr, "Ganaron las Blancas!!!!\n");
    }
}

void eatPiece(gameStructRef game, int newX, int newY, int currentX, int currentY, int op_piese){
    int eatPiece = 0;
    if(currentY - newY == 2 || currentY - newY == -2){
        if(currentY - newY == 2){ // up
            if(currentX - newX == 2){ // left
                game->board[currentX-1][currentY-1]->color = 0;
                game->board[currentX-1][currentY-1]->type = 0;
                eatPiece = 1;
            } else { // right
                game->board[currentX+1][currentY-1]->color = 0;
                game->board[currentX+1][currentY-1]->type = 0;
                eatPiece = 1;
            }
        } else { // down
            if(currentX - newX == 2){ // left
                game->board[currentX-1][currentY+1]->color = 0;
                game->board[currentX-1][currentY+1]->type = 0;
                eatPiece = 1;
            } else { // right
                game->board[currentX+1][currentY+1]->color = 0;
                game->board[currentX+1][currentY+1]->type = 0;
                eatPiece = 1;
            }
        }
    }
    if(op_piese == 0 && eatPiece == 1){ // blanca
        game->totalBlackPieces--;
    } else if(op_piese == 1 && eatPiece == 1) { // negra
        game->totalWhitePieces--;
    }
    winner(game);
}

// considerando que el movimiento si es válido
void movePiece(gameStructRef game, int newX, int newY, int currentX, int currentY)
{
    if(game->currentPlayer){ // blanca
        // asignar al nuevo lugar la ficha
        //fprintf(stderr,"\033[0;35m newX:%d, newY:%d\n",newX, newY);
        //fprintf(stderr,"\033[0;35m CurrentX:%d, CurrentY:%d\n",currentX, currentY);
        game->board[newX][newY]->color = game->board[currentX][currentY]->color;
        game->board[newX][newY]->type = game->board[currentX][currentY]->type;
        DrawCircle(340+(80*(newX-1)), 80+(80*(newY-1)), 30, WHITEPIECES);

        // poner la ficha antigua vacia
        game->board[currentX][currentY]->color = 0;
        game->board[currentX][currentY]->type = 0;
        DrawCircle(340+(80*(currentX-1)), 80+(80*(currentY-1)), 30, BOARD);
        game->currentPlayer = 0;
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, WHITE);    
        DrawText("negras", ((game->screenWidth)-200), 100, 20, WHITE);  
        fprintf(stderr, "\033[0;35m Turno negras\n");

        eatPiece(game, newX, newY, currentX, currentY, 0);

    } else { // negra
        // asignar al nuevo lugar la ficha
        //fprintf(stderr,"\033[0;35m newX:%d, newY:%d\n",newX, newY);
        //fprintf(stderr,"\033[0;35m CurrentX:%d, CurrentY:%d\n",currentX, currentY);
        game->board[newX][newY]->color = game->board[currentX][currentY]->color;
        game->board[newX][newY]->type = game->board[currentX][currentY]->type;
        DrawCircle(340+(80*(newX-1)), 80+(80*(newY-1)), 30, BLACKPIECES);

        // poner la ficha antigua vacia
        game->board[currentX][currentY]->color = 0;
        game->board[currentX][currentY]->type = 0;
        DrawCircle(340+(80*(currentX-1)), 80+(80*(currentY-1)), 30, BOARD);
        game->currentPlayer = 1;
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, RAYWHITE);
        DrawRectangleLines((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, BLACK);    
        DrawText("blancas", ((game->screenWidth)-200), 100, 20, BLACK);  
        fprintf(stderr, "\033[0;35m Turno Blancas\n");

        eatPiece(game, newX, newY, currentX, currentY, 1);

    }
    updateBoard(game);
}

// Verifica si existe un posible movimiento hacia abajo del tablero
// tanto como en diagonal izquierda como la derecha
// y tambien verifica si se puede comer una ficha
void pieceDown(gameStructRef game, int currentX, int currentY, int op_piese, int draw){
    // verifica si la derecha es valida
    if(currentX+1 <= game->boardsize){
        if (game->board[currentX+1][currentY+1]->color == 0){ // si esta libre en la posicion siguiente
            // se ilumina la derecha disponible
            //fprintf(stderr,"\n\033[0;35m Pos actual (%d,%d)\n", currentX, currentY);
            //fprintf(stderr,"\033[0;36m Pos siguiente (%d,%d)\n", currentX+1, currentY-1);
            //fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[currentX][currentY]->color, game->board[currentX+1][currentY-1]->color);
            int posx = game->board[currentX][currentY]->circle.x+80;
            int posy = game->board[currentX][currentY]->circle.y+80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            game->board[currentX+1][currentY+1]->type = 3;
            //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                fprintf(stderr,"DownPossible 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, POSSIBLE);
                game->board[currentX+1][currentY+1]->type = 3;
            } else {
                fprintf(stderr,"DownErase 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, BOARD);
                game->board[currentX+1][currentY+1]->type = 0;
            }
            //fprintf(stderr,"Posicion a la izquierda iluminada\n");
        } else if (game->board[currentX+1][currentY+1]->color == op_piese){ // si hay una negra en la siguiente posicion
            // si en 2 espacios es valido
            if(currentY+2 <= game->boardsize && currentX+2 <= game->boardsize) { // si sigue dentro del tablero
                if(game->board[currentX+2][currentY+2]->color == 0){ // si en 2 posiciones esta libre
                    // se ilumina 2 a la izquierda y se come a la ficha negra
                    // aqui puede volver a llamarse esta funcion
                    int posx = game->board[currentX][currentY]->circle.x+160;
                    int posy = game->board[currentX][currentY]->circle.y+160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    ////fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        fprintf(stderr,"DownPossible 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, POSSIBLE);
                        game->board[currentX+2][currentY+2]->type = 3;
                    } else {
                        fprintf(stderr,"DownErase 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, BOARD);
                        game->board[currentX+2][currentY+2]->type = 0;
                    }
                }
            }
        } // aqui es si habia una ficha blanca
    }
    // verifica si la izquierda es valida
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY+1]->color == 0){
            // se ilumina la izquierda disponible
            int posx = game->board[currentX][currentY]->circle.x-80;
            int posy = game->board[currentX][currentY]->circle.y+80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            ////fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                fprintf(stderr,"DownPossible 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, POSSIBLE);
                game->board[currentX-1][currentY+1]->type = 3;
            } else {
                fprintf(stderr,"DownErase 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, BOARD);
                game->board[currentX-1][currentY+1]->type = 0;
            }
            //fprintf(stderr,"Posicion a la derecha iluminada\n");
        }  else if (game->board[currentX-1][currentY+1]->color == op_piese) { // si hay una negra
            // si en 2 espacios es valido
            if(currentY+2 <= game->boardsize && currentX-2 >= 1){
                if (game->board[currentX-2][currentY+2]->color == 0){
                    // se ilumina 2 a la derecha y se come la ficha blanca
                    // aqui puede volver a llamarse esta funcion
                    int posx = game->board[currentX][currentY]->circle.x-160;
                    int posy = game->board[currentX][currentY]->circle.y+160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        fprintf(stderr,"DownPossible 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, POSSIBLE);
                        game->board[currentX-2][currentY+2]->type = 3;
                    } else {
                        fprintf(stderr,"DownErase 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, BOARD);
                        game->board[currentX-2][currentY+2]->type = 0;
                    }
                }
            }
        }
    }
}

// Verifica si existe un posible movimiento hacia arriba del tablero
// tanto como en diagonal izquierda como la derecha
// y tambien verifica si se puede comer una ficha
void pieceUp(gameStructRef game, int currentX, int currentY, int op_piese, int draw) {
    //fprintf(stderr,"\n\033[1;32m (%d <= %d) ??? \n", currentX+1, game->boardsize);
    //fprintf(stderr,"Verifica la derecha\n");
    if(currentX+1 <= game->boardsize){ // verifica si la derecha es valida
        //fprintf(stderr,"primer if\n");
        if (game->board[currentX+1][currentY-1]->color == 0){
            //fprintf(stderr,"\n\033[0;35m Pos actual (%d,%d)\n", currentX, currentY);
            //fprintf(stderr,"\033[0;36m Pos siguiente (%d,%d)\n", currentX+1, currentY-1);
            //fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[currentX][currentY]->color, game->board[currentX+1][currentY-1]->color);
            int posx = game->board[currentX][currentY]->circle.x+80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                fprintf(stderr,"UpPossible 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, POSSIBLE);
                game->board[currentX+1][currentY-1]->type = 3;
            } else {
                fprintf(stderr,"UpErase 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, BOARD);
                game->board[currentX+1][currentY-1]->type = 0;
            }
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
                    ////fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        fprintf(stderr,"UpPossible 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, POSSIBLE);
                        game->board[currentX+2][currentY-2]->type = 3;
                    } else {
                        fprintf(stderr,"UpErase 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, BOARD);
                        game->board[currentX+2][currentY-2]->type = 0;
                    }
                }
            }
        }/* else { // hay una ficha de tu color adelante de ti
            // //fprintf racista
            //fprintf(stderr,"hay una ficha de tu mismo color adelante de ti!(derecha)\n");
        }*/
    }
    //fprintf(stderr,"Verifica la izquierda\n");
    //fprintf(stderr,"\n\033[1;32m (%d >= %d) ??? \n", currentX-1, 1);
    // verifica si la izquierda es valida
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY-1]->color == 0){
            // se ilumina la izquierda disponible
            int posx = game->board[currentX][currentY]->circle.x-80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            ////fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
            if(draw){
                fprintf(stderr,"UpPossible 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, POSSIBLE);
                game->board[currentX-1][currentY-1]->type = 3;
            } else {
                fprintf(stderr,"UpErase 1: %d\n", draw);
                DrawRectangle(posx, posy, w, h, BOARD);
                game->board[currentX-1][currentY-1]->type = 0;
            }
        }  else if (game->board[currentX-1][currentY-1]->color == op_piese) { // si hay una ficha negra
            if(currentY-2 >= 1 && currentX-2 >= 1){// si en 2 espacios es valido
                if (game->board[currentX-2][currentY-2]->color == 0){
                    // se ilumina 2 a la derecha y se come la ficha blanca
                    // aqui puede volver a llamarse esta funcion
                    int posx = game->board[currentX][currentY]->circle.x-160;
                    int posy = game->board[currentX][currentY]->circle.y-160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    //fprintf(stderr, "\033[0;32m   draw a rectangle [%d %d %d %d]\n", posx, posy, w, h);
                    if(draw){
                        fprintf(stderr,"UpPossible 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, POSSIBLE);
                        game->board[currentX-2][currentY-2]->type = 3;
                    } else {
                        fprintf(stderr,"UpErase 2: %d\n", draw);
                        DrawRectangle(posx, posy, w, h, BOARD);
                        game->board[currentX-2][currentY-2]->type = 0;
                    }
                }
            }
        }/* else { // hay una ficha de tu color adelante de ti
            // //fprintf racista
            //fprintf(stderr,"hay una ficha de tu mismo color adelante de ti!(izquierda)\n");
        }*/
    }
}

// esta función se correrá en todas las fichas
// revisar todos los posibles movimientos y ver si son válidos. regresa 1 si es válido y 0 si no
void isPossible(gameStructRef game, int currentX, int currentY)
{
    // nivel de abstracción superior
    if(game->currentPlayer){ // blancas
        if(currentY+1 <= game->boardsize && game->board[currentX][currentY]->type == 1){ // verifica si se puede mover hacia adelante
            //fprintf(stderr, "\033[0;31m   pieceDown\n");
            pieceDown(game, currentX, currentY, 1, 1);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
                fprintf(stderr, "\033[0;31m IM KING (WHITE)\n");
                //fprintf(stderr, "\033[0;31m   pieceUp\n");
                pieceDown(game, currentX, currentY, 1, 1);
                fprintf(stderr, "\033[0;31m PIECE DOWN WHITE\n");
            }
            if(currentY-1 >= 1){
                pieceUp(game, currentX, currentY, 1, 1); // le pasamos el negro
                fprintf(stderr, "\033[0;31m PIECE UP WHITE\n");
            }

        }
    } else { // negras
        if(currentY-1 >= 1 && game->board[currentX][currentY]->type == 1){ // si no es el limite superior
            pieceUp(game, currentX, currentY, 2, 1);
            //fprintf(stderr, "\033[0;31m   pieceUp\n");
            //fprintf(stderr, "\033[0;31m   isPossible->pieceUp\n");
        } else {
            // Significa que mi barrio me respalda
            game->board[currentX][currentY]->type = 2;
            if(currentY-1 >= 1){ // verifica si se puede mover hacia adelante
                fprintf(stderr, "\033[0;31m IM KING (BLACK)\n");
                pieceUp(game, currentX, currentY, 2, 1); // le pasamos el blanco
                fprintf(stderr, "\033[0;31m PIECE UP BLACK\n");
                //fprintf(stderr, "\033[0;31m   pieceUp\n");
            }
            if(currentY+1 <= game->boardsize){
                pieceDown(game, currentX, currentY, 2, 1);
                fprintf(stderr, "\033[0;31m PIECE DOWN BLACK\n");
            }
        }
    }
}

// Se necesitan pasar los valores guardados de las fichas en esta funcion
// en este momento la función cada vez que se llama esta en la posición inicial del tablero
void turnPieces(gameStructRef game, int x, int y){
    //fprintf(stderr, "\033[0;32mit works? [%d]\n", game->currentPlayer);
    deleteAll(game);
    if(game->currentPlayer){
        //fprintf(stderr, "\033[0;34m turno blancas\n");
        if(game->board[x][y]->color == 2){
            isPossible(game, x, y);
        }
    } else {
        //fprintf(stderr, "\033[0;34m turno negras\n");
        if(game->board[x][y]->color == 1){
            isPossible(game, x, y);
        }
    }
}

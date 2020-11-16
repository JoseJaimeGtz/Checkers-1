#include <stdio.h>
#include <stdlib.h>
#include "gameLogic.h"

int isPossible(gameStructRef game, int currentX, int currentY){
    int type = game->board[currentX][currentY]->type;
    int color = game->board[currentX][currentY]->color;
    if(color == 0){ // negras
        if(type == 1){ // normal

        } else if(type == 2){ // rey

        } else { // algo pasó :(
            printf("");
        }
    } else if(color == 1){ // blancas

        if(type == 1){ // normal

        } else if(type == 2){ // rey

        } else { // algo pasó :(
            printf("");
        }
    } else { // algo pasó :(
        printf("");
    }
}
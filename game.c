#include <stdio.h>
#include <stdlib.h>

#include "game.h"

pieceStructRef newPiece(gameStructRef game, int color, int type)
{
    pieceStructRef new = malloc(sizeof(struct pieceStruct));
    new->color = color;
    new->type = type;
    return new;
}

void createBoard(gameStructRef game)
{
    game->boardsize = 8;
    game->currentPlayer = 0;
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){
                pieceStructRef new = newPiece(game, 1, 0);
                if(y%2!=0 && x%2==0){
                    game->board[x][y] = new;
                    printf("[%d,%d][%d]  ", x, y, game->board[x][y]->color);
                } else if (y%2==0 && x%2!=0) {
                    game->board[x][y] = new;
                    printf("[%d,%d][%d]  ", x, y, game->board[x][y]->color);
                }
            } else if (y>=game->boardsize/2+2){
                pieceStructRef new = newPiece(game, 0, 0);
                if(y%2!=0 && x%2==0){
                    game->board[x][y] = new;
                    printf("[%d,%d][%d]  ", x, y, game->board[x][y]->color);
                } else if (y%2==0 && x%2!=0) {
                    game->board[x][y] = new;
                    printf("[%d,%d][%d]  ", x, y, game->board[x][y]->color);
                }
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct pieceStruct{
    int color; // 0 = black; 1 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king
};

typedef struct pieceStruct* pieceStructRef;

struct gameStruct{
    int currentPlayer, boardsize;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
};

typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void createBoard(gameStructRef game);

pieceStructRef newPiece(gameStructRef game, int color, int type);

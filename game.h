#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

struct pieceStruct{
    int color; // 0 = nothing; 1 = black ; 2 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king
    int playerHolder; // 0 = nothing; 1 = black; 2 = white
    int size;
};

typedef struct pieceStruct* pieceStructRef;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow;
    int gameType; // 0 = 1vs1; 1 = 1vsCPU
    char* currentPlayer;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
};

typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

pieceStructRef newPiece(gameStructRef game, int color, int type, int player);
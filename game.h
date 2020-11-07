#include <stdio.h>

struct boardStruct{
    pieceStructRef piece;
    int currentPlayer;
    void*** boardMatrix;
};

typedef struct boardStruct* boardStructRef;

struct pieceStruct{
    int color;
    int type;
    int x;
    int y;
};

typedef struct pieceStruct* pieceStructRef;

struct gameStruct{
    boardStructRef board;
};

typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void startGame(gameStructRef game);
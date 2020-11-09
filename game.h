#include <stdio.h>

/*struct boardStruct{
    void*** boardMatrix;
};*/

typedef struct boardStruct* boardStructRef;

struct pieceStruct{
    int color;
    int type;
    int x;
    int y;
};

typedef struct pieceStruct* pieceStructRef;

struct gameStruct{
    int currentPlayer;
    //boardStructRef board;
};

typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void startGame(gameStructRef game);

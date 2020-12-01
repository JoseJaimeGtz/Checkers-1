#include "checkersLibrary.h"

pieceStructRef newPiece(gameStructRef game, int color, int type)
{
    pieceStructRef new = malloc(sizeof(struct pieceStruct));
    new->color = color;
    new->type = type;
    new->circle = (Rectangle) {0, 0, 0, 0};
    return new;
}

void createBoard(gameStructRef game)
{
    ClearBackground(WHITE);
    game->currentPiecex = 0;
    game->currentPiecey = 0;
    game->boardCreated++;
    game->currentPlayer = 0;
    game->totalBlackPieces = game->boardsize + game->boardsize/2;
    game->totalWhitePieces = game->boardsize + game->boardsize/2;
    fprintf(stderr, "Total piezas blancas: [%d]\n", game->totalWhitePieces);
    fprintf(stderr, "Total piezas negras: [%d]\n", game->totalBlackPieces);
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){ // Fichas blancas
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    //fprintf(stderr, "Ficha blanca [%d][%d]\n", x, y);
                    pieceStructRef new = newPiece(game, 2, 1);
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){ // Fichas Negras
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    //fprintf(stderr, "Ficha negra [%d][%d]\n", x, y);
                    pieceStructRef new = newPiece(game, 1, 1);
                    game->board[x][y] = new;
                }
            } else if ((y == game->boardsize/2 && ((y%2==0 && x%2!=0) || (y%2!=0 && x%2==0))) || (y == game->boardsize/2+1 && ((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)))){
                //fprintf(stderr, "posición vacia [%d][%d]\n", x, y);
                pieceStructRef new = newPiece(game, 0, 0);
                game->board[x][y] = new;
            }
        }
    }
    fprintf(stderr, "Tablero creado\n");
}

void saveGame(gameStructRef game, int slot)
{
    FILE* gameData;
    printf("\033[1;31m          [GUARDANDO JUEGO]\033[0m\n");
    printf("\033[0;33mSlot elegido: %d\033[0m\n", slot);
    switch(slot){
        case 1:
            gameData = fopen("../slot1.txt", "w+");
            break;

        case 2:
            gameData = fopen("../slot2.txt", "w+");
            break;

        case 3:
            gameData = fopen("../slot3.txt", "w+");
            break;
    }

    fprintf(gameData, "%d,%d,%d,%d,%d,%d,%d,%d\n", game->boardsize, game->screenWidth, game->screenHeight, game->currentPlayer, game->currentPiecex, game->currentPiecey, game->totalWhitePieces, game->totalBlackPieces);
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){       
                printf("\033[0;33mPosición guardada: [%d:%d]\033[0m\n", x, y);
                fprintf(gameData, "[%d:%d][%d,%d]\n", x, y, game->board[x][y]->color, game->board[x][y]->type);
            }
        }
    }
    printf("\033[1;32m          [JUEGO GUARDADO]\033[0m\n");
    fclose(gameData);
}

void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen)
{
    FILE* gameData;
    bool fileExist = false;
    printf("\033[1;31m          [CARGANDO JUEGO]\033[0m\n");
    printf("\033[0;33mSlot elegido: %d\033[0m\n", slot);
    switch(slot){
        case 1:
            if(access( "../slot1.txt", F_OK ) != -1 ) {
                gameData = fopen("../slot1.txt", "r");
                fileExist = true;
            } else {
                printf("\033[0;33mEL slot %d no existe\033[0m\n", slot);
            }
            break;

        case 2:
            if(access( "../slot2.txt", F_OK ) != -1 ) {
                gameData = fopen("../slot2.txt", "r");
                fileExist = true;
            } else {
                printf("\033[0;33mEL slot %d no existe\033[0m\n", slot);
            }
            break;

        case 3:
            if(access( "../slot3.txt", F_OK ) != -1 ) {
                gameData = fopen("../slot3.txt", "r");
                fileExist = true;
            } else {
                printf("\033[0;33mEL slot %d no existe\033[0m\n", slot);
            }
            break;
    }
    if(fileExist == true){
        int ignore = 0;
        printf("\033[0;33mLos archivos necesarios existen\033[0m\n");
        fscanf(gameData, "%d,%d,%d,%d,%d,%d,%d,%d\n", &game->boardsize, &game->screenWidth, &game->screenHeight, &game->currentPlayer, &game->currentPiecex, &game->currentPiecey, &game->totalWhitePieces, &game->totalBlackPieces);
        createBoard(game);
        for(int y = 1; y <= game->boardsize; y++){
            for(int x = 1; x <= game->boardsize; x++){
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){  
                    printf("\033[0;33mReading [%d:%d][%d,%d]\033[0m\n", x, y, game->board[x][y]->color, game->board[x][y]->type);
                    fscanf(gameData, "[%d:%d][%d,%d]\n", &ignore, &ignore, &game->board[x][y]->color, &game->board[x][y]->type);
                }
            }
        }
        *screen = GAME;
        updateBoard(game);
        fclose(gameData);
    }
    printf("\033[1;32m          [JUEGO CARGADO]\033[0m\n");
}

queueRef queueCreate(gameStructRef game)
{
    queueRef queue = malloc(sizeof(game->queue));

    queue->count = 0;
    queue->First = NULL;
    queue->Last = NULL;

    return queue;
}
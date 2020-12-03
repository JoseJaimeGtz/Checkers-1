#include "checkersLibrary.h"

pieceStructRef newPiece(int color, int type)
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
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    pieceStructRef new = newPiece(2, 1);
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    pieceStructRef new = newPiece(1, 1);
                    game->board[x][y] = new;
                }
            } else if ((y == game->boardsize/2 && ((y%2==0 && x%2!=0) || (y%2!=0 && x%2==0))) || (y == game->boardsize/2+1 && ((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)))){
                pieceStructRef new = newPiece(0, 0);
                game->board[x][y] = new;
            }
        }
    }
}

void saveGame(gameStructRef game, int slot, Queue* queue)
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

    fprintf(gameData, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n", queue->count, game->boardsize, game->screenWidth, game->screenHeight, game->currentPlayer, game->currentPiecex, game->currentPiecey, game->totalWhitePieces, game->totalBlackPieces);

    nodeRef focusNode = queue->First;
    printf("\033[0;33m queueCount = %d\033[0m\n", queue->count);
    while(focusNode != NULL){
        printf("\033[0;33mGuardando queue [%d,%d,%d,%d,%d]\033[0m\n", focusNode->currentX, focusNode->currentY, focusNode->newX, focusNode->newY, focusNode->currentPlayer);
        fprintf(gameData, "%d,%d,%d,%d,%d\n", focusNode->currentX, focusNode->currentY, focusNode->newX, focusNode->newY, focusNode->currentPlayer);
        focusNode = focusNode->next;
    }

    printf("\033[1;32m          [JUEGO GUARDADO]\033[0m\n");
    fclose(gameData);
}

void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen, Queue* queue)
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
        fscanf(gameData, "%d,%d,%d,%d,%d,%d,%d,%d,%d\n", &queue->count, &game->boardsize, &game->screenWidth, &game->screenHeight, &game->currentPlayer, &game->currentPiecex, &game->currentPiecey, &game->totalWhitePieces, &game->totalBlackPieces);
        createBoard(game);
        //int old = queue->count;
        int final = queue->count, newX, newY, currentX, currentY, currentPlayer;
        queue->count = 0;
        printf("\033[0;33mInicio de for\033[0m\n");
        for(int i = 0; i < final; i++){
            fscanf(gameData, "%d,%d,%d,%d,%d\n", &currentX, &currentY, &newX, &newY, &currentPlayer);
            printf("\033[0;32mLeído correctamente %d,%d,%d,%d,%d\033[0m\n", currentX, currentY, newX, newY, currentPlayer);
            queueOffer(queue, newX, newY, currentX, currentY, currentPlayer);
            movePiece(game, newX, newY, currentX, currentY, currentPlayer);
        }
        printf("\033[0;33mqueueCount = %d\033[0m\n", queue->count);
        //queue->count += old;
        *screen = GAME;
        updateBoard(game);
        fclose(gameData);
    }
    printf("\033[1;32m          [JUEGO CARGADO]\033[0m\n");
}

Queue* queueCreate()
{
    Queue* queue = malloc(sizeof(Queue));

    queue->count = 0;
    queue->currentMove = 0;
    queue->First = NULL;
    queue->Last = NULL;

    return queue;
}

nodeRef queuePoll(Queue* queue)
{
    nodeRef toRemove = queue->First;

    if(toRemove != NULL){
        nodeRef dataToRemove = toRemove;
        queue->First = toRemove->next;
        queue->count--;
        queue->currentMove--;
        return dataToRemove;
    }
    return 0;
}

nodeRef newNode(int newX, int newY, int currentX, int currentY, int currentPlayer)
{
    nodeRef node = malloc(sizeof(Node));
    node->newX = newX;
    node->newY = newY;
    node->currentX = currentX;
    node->currentY = currentY;
    node->currentPlayer = currentPlayer;
    node->next = NULL;
}

void queueOffer(Queue* queue, int newX, int newY, int currentX, int currentY, int currentPlayer)
{

    nodeRef toAdd = newNode(newX, newY, currentX, currentY, currentPlayer);
    if(queue->count == 0)
    {      
        queue->First = toAdd;
        queue->Last = toAdd;
    } else {
        queue->Last->next = toAdd;
        queue->Last = toAdd;
    }
    queue->count++;
    queue->currentMove++;
}

void queueDestroy(Queue* queue)
{
    while(queue->count > 0)
        queuePoll(queue);
    free(queue);
}

void nextMovement(gameStructRef game, Queue* queue)
{

}

void previousMovement(gameStructRef game, Queue* queue)
{
    if(queue->count > 0 && queue->currentMove > 0){
        Queue* newQueue = queue;
        nodeRef prevMovement = queuePoll(newQueue);
        queue->currentMove--;
        movePiece(game, prevMovement->currentX, prevMovement->currentY, prevMovement->newX, prevMovement->newY, prevMovement->currentPlayer);        
    }
}
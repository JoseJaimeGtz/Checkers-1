#include "checkersLibrary.h"

void drawSave(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    DrawRectangle(50, 50, 150, 50, GRAY);
    DrawText("   Regresar", 50, 65, 20, BLACK);
}

void checkSaveButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    fprintf(stderr, "[%.2f,%.2f]\n", mouse.x, mouse.y);
    Rectangle returnRect = {50, 50, 150, 50};

    if(click == true && CheckCollisionPointRec(mouse, returnRect)){
        saveGame(game);
    }
}

void drawMain(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    game->screenWidth = 1240;
    game->screenHeight = 760;
    game->boardCreated = 0;
    ClearBackground(WHITE);
    board->board8x8 = (Rectangle) {470, 100, 100, 50};
    board->board10x10 = (Rectangle) {580, 100, 100, 50};
    board->board12x12 = (Rectangle) {690, 100, 100, 50};
    
    DrawRectangle(470, 40, 320, 50, BLACK);
    DrawText("Escoge el tamaño del tablero", 480, 55, 20, WHITE);

    DrawRectangleRec(board->board8x8, GRAY);
    DrawText("8x8", 505, 115, 20, BLACK);    

    DrawRectangleRec(board->board10x10, GRAY);
    DrawText("10x10", 610, 115, 20, BLACK);    

    DrawRectangleRec(board->board12x12, GRAY);
    DrawText("12x12", 720, 115, 20, BLACK);

}

void checkMainButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    if(click == true && CheckCollisionPointRec(mouse, board->board8x8))
    {
        game->boardsize = 8;
        *screen = GAME;
    } else if(click == true && CheckCollisionPointRec(mouse, board->board10x10))
    {
        game->boardsize = 10;
        game->screenWidth += 160;
        game->screenHeight += 120;
        *screen = GAME;
    } else if(click == true && CheckCollisionPointRec(mouse, board->board12x12))
    {
        game->boardsize = 12;
        game->screenWidth += 320;
        game->screenHeight += 280;
        *screen = GAME;
    }
}

void updateBoard(gameStructRef game)
{

    if(game->boardsize == 8) DrawRectangleLines(300, 40, 640, 640, BLACK);
    if(game->boardsize == 10) DrawRectangleLines(300, 40, 800, 800, BLACK);
    if(game->boardsize == 12) DrawRectangleLines(300, 40, 960, 960, BLACK);

    if(game->currentPlayer == 1) {
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, RAYWHITE);
        DrawRectangleLines((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, BLACK);    
        DrawText("blancas", ((game->screenWidth)-200), 100, 20, BLACK);   
    } else {
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, WHITE);    
        DrawText("negras", ((game->screenWidth)-200), 100, 20, WHITE);  
    }

    DrawRectangle((game->screenWidth)-250, 240, 200, 60, BLACK);
    DrawText("Guardar", ((game->screenWidth)-200), 260, 20, WHITE);   

    for(int y = 0; y < game->boardsize; y++){
        for (int x = 0; x < game->boardsize; x++) {
            if ((y%2==0 && x%2!=0) || (y%2!=0 && x%2==0)){
                DrawRectangle(300+(80*(x)), 40+(y*80), 80, 80, BOARD);
            }
        }
    }
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                if(game->board[x][y]->color == 2){
                    if(game->board[x][y]->type == 1){
                        DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, WHITEPIECES);
                    } else if(game->board[x][y]->type == 2){
                        DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, WHITEPIECESKING);
                    }
                } else if(game->board[x][y]->color == 1){
                    if(game->board[x][y]->type == 1){
                        DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, BLACKPIECES);
                    } else if(game->board[x][y]->type == 2){
                        DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, BLACKPIECESKING);
                    }
                } else if(game->board[x][y]->type == 3){
                    game->board[x][y]->type == 0;
                }
            }
        }
    }
}

void drawGame(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    if(!game->boardCreated)
        createBoard(game);
    SetWindowSize(game->screenWidth, game->screenHeight);

    // Creación de las fichas del tablero
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){ // Fichas blancas
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    //DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, WHITEPIECES); // par en x impar en y
                    game->board[x][y]->circle = (Rectangle) {
                        310+(80*(x-1)),
                        50+(80*(y-1)),
                        60,
                        60
                    };
                }
            } else if (y>=game->boardsize/2+2){ // Fichas Negras
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    //DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, BLACKPIECES); // par en x, impar en y
                    game->board[x][y]->circle = (Rectangle) {
                        310+(80*(x-1)),
                        50+(80*(y-1)),
                        60,
                        60
                    };
                }
            } else if ((y == game->boardsize/2 && (y%2==0 && x%2!=0)) || (y == game->boardsize/2+1 && (y%2!=0 && x%2==0))){
                game->board[x][y]->circle = (Rectangle) {
                    310+(80*(x-1)),
                    50+(80*(y-1)),
                    60,
                    60
                };
            }
        }
    }
    updateBoard(game);
}

void checkGameButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    Rectangle saveRect = {(game->screenWidth)-250, 240, 200, 60};

    if(click == true && CheckCollisionPointRec(mouse, saveRect)){
        saveGame(game);
    }

    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            //fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
            //printf("\033[0;34m[%f, %f]\n", mouse.x, mouse.y);
            if(game->currentPlayer){ // blanca
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        updateBoard(game);
                        //fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        if(game->board[x][y]->type == 3 && game->currentColor == 2){
                            movePiece(game, x,y,game->currentPiecex, game->currentPiecey);
                        }
                        if(game->currentPiecex != 0){
                            //fprintf(stderr, "delete Selected done\n");
                        }
                        //fprintf(stderr, "\033[0;33misPossible [%d][%d]\n", x, y);
                        turnPieces(game, x, y); // regresa los colores de las casillas iluminadas
                        game->currentColor = game->board[x][y]->color;
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                        //fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                    }
                }
            } else { // negra
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        updateBoard(game);
                        //fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        if(game->board[x][y]->type == 3 && game->currentColor == 1){
                            //fprintf(stderr, "\033[0;35mTYPE==3\n");
                            movePiece(game, x,y,game->currentPiecex, game->currentPiecey);
                        }
                        //fprintf(stderr, "\033[0;33misPossible   [%d][%d]\n", x, y);
                        turnPieces(game, x, y);
                        //fprintf(stderr, "\033[0;35mturnPieces done\n");
                        game->currentColor = game->board[x][y]->color;
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                        //fprintf(stderr,"\033[0;32m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                    }
                }
            }
        }
    }
}

void deleteSelected(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    if(game->currentPlayer){ // blanco
        if(game->board[game->currentPiecex][game->currentPiecey]->type == 2){ // si es king
            // nada por ahora, paga la versión completa para desbloquear esta función
            pieceUp(game, game->currentPiecex, game->currentPiecey, 1, 0);
            pieceDown(game, game->currentPiecex, game->currentPiecey, 1, 0);
        } else {
            pieceDown(game, game->currentPiecex, game->currentPiecey, 1, 0);
        }
    } else { // negro
        if(game->board[game->currentPiecex][game->currentPiecey]->type == 2){ // si es king
            // nada por ahora, paga la versión completa para desbloquear esta función
            pieceDown(game, game->currentPiecex, game->currentPiecey, 1, 0);
            pieceUp(game, game->currentPiecex, game->currentPiecey, 1, 0);
        } else {
            pieceUp(game, game->currentPiecex, game->currentPiecey, 1, 0);
        }
    }
}

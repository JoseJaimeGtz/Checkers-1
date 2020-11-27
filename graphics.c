#include "checkersLibrary.h"

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

    checkMainButton(game, board, screen);

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

void drawGame(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    if(!game->boardCreated)
        createBoard(game);
    SetWindowSize(game->screenWidth, game->screenHeight);

    if(game->boardsize == 8) DrawRectangleLines(300, 40, 640, 640, BLACK);
    if(game->boardsize == 10) DrawRectangleLines(300, 40, 800, 800, BLACK);
    if(game->boardsize == 12) DrawRectangleLines(300, 40, 960, 960, BLACK);
    
    // Creación del tablero
    for(int i = 0; i < game->boardsize; i++){
        if (i%2 != 0){
            DrawRectangle(300, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(460, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(620, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(780, 40+(i*80), 80, 80, BROWN);
            if(game->boardsize >= 10) DrawRectangle(940, 40+(i*80), 80, 80, BROWN);
            if(game->boardsize == 12) DrawRectangle(1100, 40+(i*80), 80, 80, BROWN);
        } else {
            DrawRectangle(380, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(540, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(700, 40+(i*80), 80, 80, BROWN);
            DrawRectangle(860, 40+(i*80), 80, 80, BROWN);
            if(game->boardsize >= 10) DrawRectangle(1020, 40+(i*80), 80, 80, BROWN);
            if(game->boardsize == 12) DrawRectangle(1180, 40+(i*80), 80, 80, BROWN);
        }
    }

    // Creación de las fichas del tablero
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){ // Fichas blancas
                if(y%2!=0 && x%2==0){
                    DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, WHITE); // par en x impar en y
                    game->board[x][y]->circle = (Rectangle) {
                        390+(80*(x-2)),
                        50+(80*(y-1)),
                        60,
                        60
                    };
                } else if(y%2==0 && x%2!=0){
                    DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, WHITE); // impar en x, par en y
                    game->board[x][y]->circle = (Rectangle) {
                        310+(80*(x-1)), // si funciona
                        130+(80*(y-2)), 
                        60,
                        60
                    };
                }
            } else if (y>=game->boardsize/2+2){ // Fichas Negras
                if(y%2!=0 && x%2==0){
                    DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, BLACK); // par en x, impar en y
                    game->board[x][y]->circle = (Rectangle) {
                        390+(80*(x-2)),
                        50+(80*(y-1)),
                        60,
                        60
                    };
                } else if(y%2==0 && x%2!=0){
                    DrawCircle(340+(80*(x-1)), 80+(80*(y-1)), 30, BLACK); // impar en x, par en y
                    game->board[x][y]->circle = (Rectangle) {
                        390+(80*(x-2)),
                        50+(80*(y-1)),
                        60,
                        60
                    };
                }
            } else if (y == game->boardsize/2 && (y%2==0 && x%2!=0)){
                game->board[x][y]->circle = (Rectangle) {0, 0, 0, 0};
            } else if (y == game->boardsize/2+1 && (y%2!=0 && x%2==0)){
                game->board[x][y]->circle = (Rectangle) {0, 0, 0, 0};
            }
        }
    }
}

void checkGameButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();

    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if(game->currentPlayer){ // blanca
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        if(game->currentPiecex != 0){
                            deleteSelected(game, board, screen);
                            fprintf(stderr, "delete Selected done\n");
                        }
                        fprintf(stderr, "\033[0;33misPossible [%d][%d]\n", x, y);
                        turnPieces(game, x, y);
                        if(game->board[x][y]->type == 3 && (y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                            movePiece(game, x,y,game->currentPiecex, game->currentPiecey);                                
                        }
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                        //fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                    }
                }
            } else { // negra
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        if(game->currentPiecex != 0){
                            deleteSelected(game, board, screen);
                            fprintf(stderr, "delete Selected done\n");
                        }
                        fprintf(stderr, "\033[0;33misPossible   [%d][%d]\n", x, y);
                        turnPieces(game, x, y);
                        fprintf(stderr, "\033[0;35mturnPieces done\n");
                        if(game->board[x][y]->type == 3){
                            movePiece(game, x,y,game->currentPiecex, game->currentPiecey);                                
                        }
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                        //fprintf(stderr,"\033[0;32m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                    }
                }
            }
        }
    }


    /*
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if(game->currentPlayer == 1){
                if (y<=game->boardsize/2){ // Fichas blancas
                    if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                        if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                            printf("Posicion seleccionada\033[0;34m[%f, %f]\n", mouse.x, mouse.y);
                            if(game->currentPiecex != 0){
                                deleteSelected(game, board, screen);
                                fprintf(stderr, "delete Selected done\n");
                            }
                            fprintf(stderr, "\033[0;33misPossible [%d][%d]\n", x, y);
                            turnPieces(game, x, y);
                            if(game->board[x][y]->type == 3 && (y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                                movePiece(game, x,y,game->currentPiecex, game->currentPiecey);                                
                            }
                            game->currentPiecex = x;
                            game->currentPiecey = y;
                            //fprintf(stderr,"\033[0;37m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                        }
                    }
                }
            }
            if(game->currentPlayer == 0){
                if (y>=game->boardsize/2+1){ // Fichas Negras
                    if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                        if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                            if(game->currentPiecex != 0){
                                deleteSelected(game, board, screen);
                                fprintf(stderr, "delete Selected done\n");
                            }
                            fprintf(stderr, "\033[0;33misPossible   [%d][%d]\n", x, y);
                            turnPieces(game, x, y);
                            fprintf(stderr, "\033[0;35mturnPieces done\n");
                            if(game->board[x][y]->type == 3){
                                movePiece(game, x,y,game->currentPiecex, game->currentPiecey);                                
                            }
                            game->currentPiecex = x;
                            game->currentPiecey = y;
                            //fprintf(stderr,"\033[0;32m color actual:[%d], color siguiente:[%d]\n", game->board[x][y]->color, game->board[x+1][y-1]->color);
                        }
                    }
                }
            }
        }
    }*/
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
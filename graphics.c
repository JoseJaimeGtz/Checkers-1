#include "checkersLibrary.h"

void drawLoad(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    DrawRectangle(50, 50, 150, 50, GRAY);
    DrawText("   Regresar", 50, 65, 20, BLACK);

    DrawRectangle(200, 170, 250, 30, BLACK);
    DrawRectangle(200, 200, 250, 400, GRAY);
    DrawText("           Slot 1", 200, 175, 20, WHITE);
    if(access("../slot1.txt", F_OK ) != -1 ) {
        DrawRectangle(200, 600, 250, 30, LIME);
        DrawText("          Cargar", 200, 605, 20, WHITE);
    } else {
        DrawRectangle(200, 600, 250, 30, RED);
        DrawText("        No disponible", 200, 605, 20, WHITE);
    }

    DrawRectangle(500, 170, 250, 30, BLACK);
    DrawRectangle(500, 200, 250, 400, GRAY);
    DrawText("           Slot 2", 500, 175, 20, WHITE);
    if(access("../slot2.txt", F_OK ) != -1 ) {
        DrawRectangle(500, 600, 250, 30, LIME);
        DrawText("          Cargar", 500, 605, 20, WHITE);
    } else {
        DrawRectangle(500, 600, 250, 30, RED);
        DrawText("        No disponible", 500, 605, 20, WHITE);
    }

    DrawRectangle(800, 170, 250, 30, BLACK);
    DrawRectangle(800, 200, 250, 400, GRAY);
    DrawText("           Slot 3", 800, 175, 20, WHITE);
    if(access("../slot3.txt", F_OK ) != -1 ) {
        DrawRectangle(800, 600, 250, 30, LIME);
        DrawText("          Cargar", 800, 605, 20, WHITE);
    } else {
        DrawRectangle(800, 600, 250, 30, RED);
        DrawText("        No disponible", 800, 605, 20, WHITE);
    }
}

void checkLoadButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    Rectangle returnRect = {50, 50, 150, 50};

    if(click == true && CheckCollisionPointRec(mouse, returnRect)){
        *screen = MAIN;
    }

    Rectangle slot1 = {200, 200, 250, 400};
    Rectangle slot2 = {500, 200, 250, 400};
    Rectangle slot3 = {800, 200, 250, 400};

    if(CheckCollisionPointRec(mouse, slot1)){
        DrawRectangle(200, 200, 250, 400, SKYBLUE);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, GRAY);
        if(click == true){
            loadGame(game, 1, board, screen);
        }
    } else if(CheckCollisionPointRec(mouse, slot2)){
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, SKYBLUE);
        DrawRectangle(800, 200, 250, 400, GRAY);
        if(click == true){
            loadGame(game, 2, board, screen);
        }
    } else if(CheckCollisionPointRec(mouse, slot3)){
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, SKYBLUE);
        if(click == true){
            loadGame(game, 3, board, screen);
        }
    } else {
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, GRAY);
    }
}

void drawSave(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    DrawRectangle(50, 50, 150, 50, GRAY);
    DrawText("   Regresar", 50, 65, 20, BLACK);

    DrawRectangle(200, 170, 250, 30, BLACK);
    DrawRectangle(200, 200, 250, 400, GRAY);
    DrawText("           Slot 1", 200, 175, 20, WHITE);
    if(access("../slot1.txt", F_OK ) != -1 ) {
        DrawRectangle(200, 600, 250, 30, RED);
        DrawText("        Sobreescribir", 200, 605, 20, WHITE);
    } else {
        DrawRectangle(200, 600, 250, 30, LIME);
        DrawText("         Disponible", 200, 605, 20, WHITE);
    }

    DrawRectangle(500, 170, 250, 30, BLACK);
    DrawRectangle(500, 200, 250, 400, GRAY);
    DrawText("           Slot 2", 500, 175, 20, WHITE);
    if(access("../slot2.txt", F_OK ) != -1 ) {
        DrawRectangle(500, 600, 250, 30, RED);
        DrawText("        Sobreescribir", 500, 605, 20, WHITE);
    } else {
        DrawRectangle(500, 600, 250, 30, LIME);
        DrawText("         Disponible", 500, 605, 20, WHITE);
    }

    DrawRectangle(800, 170, 250, 30, BLACK);
    DrawRectangle(800, 200, 250, 400, GRAY);
    DrawText("           Slot 3", 800, 175, 20, WHITE);
    if(access("../slot3.txt", F_OK ) != -1 ) {
        DrawRectangle(800, 600, 250, 30, RED);
        DrawText("        Sobreescribir", 800, 605, 20, WHITE);
    } else {
        DrawRectangle(800, 600, 250, 30, LIME);
        DrawText("         Disponible", 800, 605, 20, WHITE);
    }
}

void checkSaveButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    Rectangle returnRect = {50, 50, 150, 50};
    Rectangle slot1 = {200, 200, 250, 400};
    Rectangle slot2 = {500, 200, 250, 400};
    Rectangle slot3 = {800, 200, 250, 400};

    if(click == true && CheckCollisionPointRec(mouse, returnRect)){
        *screen = GAME;
    }

    if(CheckCollisionPointRec(mouse, slot1)){
        DrawRectangle(200, 200, 250, 400, SKYBLUE);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, GRAY);
        if(click == true){
            saveGame(game, 1);
            DrawRectangle(200, 600, 250, 30, RED);
            DrawText("        Sobreescribir", 200, 605, 20, WHITE);
        }
    } else if(CheckCollisionPointRec(mouse, slot2)){
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, SKYBLUE);
        DrawRectangle(800, 200, 250, 400, GRAY);
        if(click == true){
            saveGame(game, 2);
            DrawRectangle(500, 600, 250, 30, RED);
            DrawText("        Sobreescribir", 500, 605, 20, WHITE);
        }
    } else if(CheckCollisionPointRec(mouse, slot3)){
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, SKYBLUE);
        if(click == true){
            saveGame(game, 3);
            DrawRectangle(800, 600, 250, 30, RED);
            DrawText("        Sobreescribir", 800, 605, 20, WHITE);
        }
    } else {
        DrawRectangle(200, 200, 250, 400, GRAY);
        DrawRectangle(500, 200, 250, 400, GRAY);
        DrawRectangle(800, 200, 250, 400, GRAY);
    }
}

void drawMain(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    game->screenWidth = 1560;
    game->screenHeight = 1040;
    //game->screenWidth = 1240;
    //game->screenHeight = 760;
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

    DrawRectangle(470, 165, 320, 50, GRAY);
    DrawText("            Cargar juego", 470, 177, 20, BLACK);

}

void checkMainButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen)
{
    bool click = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    Vector2 mouse = GetMousePosition();
    Rectangle loadGameRect = {470, 165, 320, 50};

    if(click == true && CheckCollisionPointRec(mouse, board->board8x8))
    {
        game->boardsize = 8;
        *screen = GAME;
    } else if(click == true && CheckCollisionPointRec(mouse, board->board10x10))
    {
        game->boardsize = 10;
        //game->screenWidth += 160;
        //game->screenHeight += 120;
        *screen = GAME;
    } else if(click == true && CheckCollisionPointRec(mouse, board->board12x12))
    {
        game->boardsize = 12;
        //game->screenWidth += 320;
        //game->screenHeight += 280;
        *screen = GAME;
    } else if(click == true && CheckCollisionPointRec(mouse, loadGameRect)){
        *screen = LOAD;
    }
}

void updateBoard(gameStructRef game)
{
    ClearBackground(WHITE);
    DrawRectangle(50, 50, 150, 50, RED);
    DrawText("   Regresar", 50, 65, 20, BLACK);
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

    // Creacion del tablero
    for(int y = 0; y < game->boardsize; y++){
        for (int x = 0; x < game->boardsize; x++) {
            if ((y%2==0 && x%2!=0) || (y%2!=0 && x%2==0)){
                DrawRectangle(300+(80*(x)), 40+(y*80), 80, 80, BOARD);
            }
        }
    }

    // Creación de las fichas del tablero
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
        *screen = SAVE;
    }

    Rectangle returnRect = {50, 50, 150, 50};

    if(click == true && CheckCollisionPointRec(mouse, returnRect)){
        *screen = MAIN;
    }

    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if(game->currentPlayer){ // blanca
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        //fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        updateBoard(game);
                        if(game->board[x][y]->type == 3 && game->currentColor == 2){
                            movePiece(game, x, y, game->currentPiecex, game->currentPiecey);
                        }
                        turnPieces(game, x, y);
                        game->currentColor = game->board[x][y]->color;
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                    }
                }
            } else { // negra
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    //printf("\033[0;34m[%f, %f]\n", mouse.x, mouse.y);
                    if(click == true && CheckCollisionPointRec(mouse, (game->board[x][y]->circle))){
                        //fprintf(stderr, "\033[0;33m SELECTED [%d][%d]\n", x, y);
                        updateBoard(game);
                        if(game->board[x][y]->type == 3 && game->currentColor == 1){
                            movePiece(game, x,y,game->currentPiecex, game->currentPiecey);
                        }
                        turnPieces(game, x, y);
                        game->currentColor = game->board[x][y]->color;
                        game->currentPiecex = x;
                        game->currentPiecey = y;
                    }
                }
            }
        }
    }
}

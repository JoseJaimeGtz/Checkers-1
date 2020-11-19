#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

pieceStructRef newPiece(gameStructRef game, int color, int type, int player)
{
    pieceStructRef new = malloc(sizeof(struct pieceStruct));
    new->color = color;
    new->type = type;
    new->playerHolder = player;
    new->size = 30;
    new->position.x = 0;
    new->position.y = 0;
    new->collision.x = 0;
    new->collision.y = 0;
    new->collision.height = 80;
    new->collision.width = 80;
    return new;
}

void initGame(gameStructRef game)
{
    game->currentPlayer = "negras";
    game->boardsize = 0;
    game->currentWindow = 0;
    game->gameType = 2;
}

void drawMain(gameStructRef game)
{
    game->screenWidth = 1240;
    game->screenHeight = 760;

    Rectangle button_boardSize_8 = {470, 100, 100, 50};
    int state_boardSize_8 = 0;
    bool action_boardSize_8 = false;

    Rectangle button_boardSize_10 = {580, 100, 100, 50};
    int state_boardSize_10 = 0;
    bool action_boardSize_10 = false;

    Rectangle button_boardSize_12 = {690, 100, 100, 50};
    int state_boardSize_12 = 0;
    bool action_boardSize_12 = false;

    Rectangle button_boardSize_1vs1 = {470, 220, 155, 50};
    int state_boardSize_1vs1 = 0;
    bool action_boardSize_1vs1 = false;

    Rectangle button_boardSize_1vsCPU = {635, 220, 155, 50};
    int state_boardSize_1vsCPU = 0;
    bool action_boardSize_1vsCPU = false;

    Rectangle button_boardSize_start = {470, 280, 320, 50};
    int state_boardSize_start = 0;
    bool action_boardSize_start = false;

    Vector2 mousePoint = { 0.0f, 0.0f };

    InitWindow(game->screenWidth, game->screenHeight, "Checkers");
    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePoint = GetMousePosition();
        action_boardSize_8 = false;
        action_boardSize_10 = false;
        action_boardSize_12 = false;
        action_boardSize_1vs1 = false;
        action_boardSize_1vsCPU = false;
        // Check button state
        if (CheckCollisionPointRec(mousePoint, button_boardSize_8))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_8 = 2;
            else state_boardSize_8 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_8 = true;
        }
        else state_boardSize_8 = 0;

        if (action_boardSize_8)
        {
            game->boardsize = 8;
            DrawRectangle(470, 100, 100, 50, LIME);
            DrawRectangle(580, 100, 100, 50, WHITE);
            DrawRectangle(690, 100, 100, 50, WHITE);
        }

        if (CheckCollisionPointRec(mousePoint, button_boardSize_10))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_10 = 2;
            else state_boardSize_10 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_10 = true;
        }
        else state_boardSize_10 = 0;

        if (action_boardSize_10)
        {
            game->boardsize = 10;
            DrawRectangle(470, 100, 100, 50, WHITE);
            DrawRectangle(580, 100, 100, 50, LIME);
            DrawRectangle(690, 100, 100, 50, WHITE);
        }

        if (CheckCollisionPointRec(mousePoint, button_boardSize_12))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_12 = 2;
            else state_boardSize_12 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_12 = true;
        }
        else state_boardSize_12 = 0;

        if (action_boardSize_12)
        {
            game->boardsize = 12;
            DrawRectangle(470, 100, 100, 50, WHITE);
            DrawRectangle(580, 100, 100, 50, WHITE);
            DrawRectangle(690, 100, 100, 50, LIME);
        }

        if (CheckCollisionPointRec(mousePoint, button_boardSize_1vs1))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_1vs1 = 2;
            else state_boardSize_1vs1 = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_1vs1 = true;
        }
        else state_boardSize_1vs1 = 0;

        if (action_boardSize_1vs1)
        {
            game->gameType = 1;
            DrawRectangle(470, 220, 155, 50, LIME);
            DrawRectangle(635, 220, 155, 50, WHITE);
        }

        if (CheckCollisionPointRec(mousePoint, button_boardSize_1vsCPU))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_1vsCPU = 2;
            else state_boardSize_1vsCPU = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_1vsCPU = true;
        }
        else state_boardSize_1vsCPU = 0;

        if (action_boardSize_1vsCPU)
        {
            game->gameType = 1;
            DrawRectangle(470, 220, 155, 50, WHITE);
            DrawRectangle(635, 220, 155, 50, LIME);
        }

        if (CheckCollisionPointRec(mousePoint, button_boardSize_start) && game->boardsize != 0 && game->gameType != 2)
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state_boardSize_start = 2;
            else state_boardSize_start = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) action_boardSize_start = true;
        }
        else state_boardSize_start = 0;

        if (action_boardSize_start)
        {
            CloseWindow();
            createWindow(game);
        }

        if(game->boardsize != 0 && game->gameType != 2){
            DrawRectangleLines(470, 280, 320, 50, BLACK);
            DrawText("Empezar juego", 550, 298, 20, BLACK); 
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        DrawRectangle(470, 40, 320, 50, BLACK);
        DrawText("Escoge el tamaño del tablero", 480, 55, 20, WHITE);    

        DrawRectangleLines(470, 100, 100, 50, BLACK);
        DrawText("8x8", 505, 115, 20, BLACK);    

        DrawRectangleLines(580, 100, 100, 50, BLACK);
        DrawText("10x10", 610, 115, 20, BLACK);    

        DrawRectangleLines(690, 100, 100, 50, BLACK);
        DrawText("12x12", 720, 115, 20, BLACK);

        DrawRectangle(470, 160, 320, 50, BLACK);    
        DrawText("Escoge el tipo de juego", 500, 175, 20, WHITE);

        DrawRectangleLines(470, 220, 155, 50, BLACK);
        DrawText("   1 vs 1", 505, 235, 20, BLACK);     

        DrawRectangleLines(635, 220, 155, 50, BLACK);
        DrawText("   1 vs CPU", 650, 235, 20, BLACK);       

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();
}

void drawBoard(gameStructRef game)
{
    // Tamaño del tablero
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
            if (x <= game->boardsize/2 && y <= game->boardsize/2-1){ // blancas
                if (y%2==0){
                    DrawCircle(340+(160*(x-1)), 80+(80*(y-1)), 30, WHITE);
                    // guardar las posiciones en un vector
                    
                    //game->board[x][y]->position.x = 340+(160*(x-1));
                    //game->board[x][y]->position.y = 80+(80*(y-1));
                } else {
                    DrawCircle(420+(160*(x-1)), 80+(80*(y-1)), 30, WHITE);
                }
            } else if (y>=game->boardsize/2+2 && x <= game->boardsize/2){ // Negras
                if (y%2==0){
                    DrawCircle(340+(160*(x-1)), 80+(80*(y-1)), 30, BLACK);
                } else {
                    DrawCircle(420+(160*(x-1)), 80+(80*(y-1)), 30, BLACK);
                }
            }
        }
    }
}

void createBoard(gameStructRef game)
{
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){ // Fichas blancas
                pieceStructRef new = newPiece(game, 1, 1, 1);
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){ // Fichas Negras
                pieceStructRef new = newPiece(game, 0, 1, 2);
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    game->board[x][y] = new;
                }
            } else { // posiciones vacias
                pieceStructRef new = newPiece(game, 0, 0, 0);
                game->board[x][y] = new;
            }
        }
    }
}

void createWindow(gameStructRef game)
{
    if(game->boardsize == 10){
        game->screenWidth += 160;
        game->screenHeight += 120;
    } else if(game->boardsize == 12) {
        game->screenWidth += 320;
        game->screenHeight += 280;
    }

    InitWindow(game->screenWidth, game->screenHeight, "Checkers");

    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(game->currentWindow == 0){
            if(game->currentPlayer == "blancas") {
                DrawRectangleLines((game->screenWidth)-250, 40, 200, 120, BLACK);
                DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, BLACK);    
                DrawText(game->currentPlayer, ((game->screenWidth)-200), 100, 20, BLACK);   
            } else {
                DrawRectangle((game->screenWidth)-250, 40, 200, 120, BLACK);
                DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, WHITE);    
                DrawText(game->currentPlayer, ((game->screenWidth)-200), 100, 20, WHITE);  
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        drawBoard(game);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();
}

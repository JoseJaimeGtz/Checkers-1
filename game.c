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
    return new;
}

void initGame(gameStructRef game)
{
    game->currentPlayer = "negras";
    game->boardsize = 8;
    game->currentWindow = 0;
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

    Rectangle button_boardSize_start = {470, 500, 320, 50};
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

        if (CheckCollisionPointRec(mousePoint, button_boardSize_start))
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
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        DrawRectangleLines(470, 40, 320, 50, BLACK);
        DrawText("Escoge el tamaño del tablero", 480, 55, 20, BLACK);    

        DrawRectangleLines(470, 100, 100, 50, BLACK);
        DrawText("8x8", 505, 115, 20, BLACK);    

        DrawRectangleLines(580, 100, 100, 50, BLACK);
        DrawText("10x10", 610, 115, 20, BLACK);    

        DrawRectangleLines(690, 100, 100, 50, BLACK);
        DrawText("12x12", 720, 115, 20, BLACK);    

        DrawRectangleLines(470, 500, 320, 50, BLACK);
        DrawText("Empezar juego", 550, 518, 20, BLACK);   

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();
}

void drawBoard(gameStructRef game)
{
    if(game->boardsize == 8) DrawRectangleLines(300, 40, 640, 640, BLACK);
    if(game->boardsize == 10) DrawRectangleLines(300, 40, 800, 800, BLACK);
    if(game->boardsize == 12) DrawRectangleLines(300, 40, 960, 960, BLACK);           

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
    /*for(int i = 0; i < game->boardsize; i++){
        for(int j = 0; i < game->boardsize; i++){
            game->board[i][j]->rectangle = {580, 100, 100, 50};
        }
    }*/
    for(int i = 0; i < game->boardsize; i++){
        if(i <= ((game->boardsize)/2)-2) {
            if(i%2 != 0) {
                DrawCircle(340, 80+(i*80), 30, WHITE);
                DrawCircle(500, 80+(i*80), 30, WHITE);
                DrawCircle(660, 80+(i*80), 30, WHITE);
                DrawCircle(820, 80+(i*80), 30, WHITE);
                if(game->boardsize >= 10) DrawCircle(980, 80+(i*80), 30, WHITE);
                if(game->boardsize == 12) DrawCircle(1140, 80+(i*80), 30, WHITE);
            } else {
                DrawCircle(420, 80+(i*80), 30, WHITE);
                DrawCircle(580, 80+(i*80), 30, WHITE);
                DrawCircle(740, 80+(i*80), 30, WHITE);
                DrawCircle(900, 80+(i*80), 30, WHITE);
                if(game->boardsize >= 10) DrawCircle(1060, 80+(i*80), 30, WHITE);
                if(game->boardsize == 12) DrawCircle(1220, 80+(i*80), 30, WHITE);
            }
        } else if(i >= ((game->boardsize)/2)+1) {
            if(i%2 == 0) {
                DrawCircle(420, 80+(i*80), 30, BLACK);
                DrawCircle(580, 80+(i*80), 30, BLACK);
                DrawCircle(740, 80+(i*80), 30, BLACK);
                DrawCircle(900, 80+(i*80), 30, BLACK);
                if(game->boardsize >= 10) DrawCircle(1060, 80+(i*80), 30, BLACK);
                if(game->boardsize == 12) DrawCircle(1220, 80+(i*80), 30, BLACK);
            } else {
                DrawCircle(340, 80+(i*80), 30, BLACK);
                DrawCircle(500, 80+(i*80), 30, BLACK);
                DrawCircle(660, 80+(i*80), 30, BLACK);
                DrawCircle(820, 80+(i*80), 30, BLACK);
                if(game->boardsize >= 10) DrawCircle(980, 80+(i*80), 30, BLACK);
                if(game->boardsize == 12) DrawCircle(1140, 80+(i*80), 30, BLACK);
            }
        }
    }
}

void createBoard(gameStructRef game)
{
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){
                pieceStructRef new = newPiece(game, 1, 1, 1);
                if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){
                pieceStructRef new = newPiece(game, 0, 1, 2);
                if((y%2!=0 && x%2==0) || y%2==0 && x%2!=0){
                    game->board[x][y] = new;
                }
            } else {
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

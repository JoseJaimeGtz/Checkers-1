#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "game.h"

pieceStructRef newPiece(gameStructRef game, int color, int type)
{
    pieceStructRef new = malloc(sizeof(struct pieceStruct));
    new->color = color;
    new->type = type;
    return new;
}

void createBoard(gameStructRef game)
{
    game->boardsize = 8;
    game->currentPlayer = 0;
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if (y<=game->boardsize/2-1){
                pieceStructRef new = newPiece(game, 1, 1);
                if(y%2!=0 && x%2==0){
                    game->board[x][y] = new;
                } else if (y%2==0 && x%2!=0) {
                    game->board[x][y] = new;
                }
            } else if (y>=game->boardsize/2+2){
                pieceStructRef new = newPiece(game, 0, 1);
                if(y%2!=0 && x%2==0){
                    game->board[x][y] = new;
                } else if (y%2==0 && x%2!=0) {
                    game->board[x][y] = new;
                }
            } else {
                pieceStructRef new = newPiece(game, 0, 0);
                game->board[x][y] = new;
            }
        }
    }
}

void createWindow(gameStructRef game)
{
    game->screenWidth = 1240;
    game->screenHeight = 800;
    if(game->boardsize == 10){
        game->screenWidth += 160;
        game->screenHeight += 160;
    } else if(game->boardsize == 12) {
        game->screenWidth += 320;
        game->screenHeight += 320;
    }

    InitWindow(game->screenWidth, game->screenHeight, "Checkers");

    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if(game->boardsize == 8) DrawRectangleLines(300, 80, 640, 640, BLACK);
        if(game->boardsize == 10) DrawRectangleLines(300, 80, 800, 800, BLACK);
        if(game->boardsize == 12)DrawRectangleLines(300, 80, 960, 960, BLACK);

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
        for(int i = 0; i < game->boardsize; i++){
            if(i <= 2) {
                if(i == 1) {
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
            } else if(i >= 5) {
                if(i == 6) {
                    DrawCircle(420, 80+(i*80), 30, BLACK);
                    DrawCircle(580, 80+(i*80), 30, BLACK);
                    DrawCircle(740, 80+(i*80), 30, BLACK);
                    DrawCircle(900, 80+(i*80), 30, BLACK);
                    if(game->boardsize >= 10) DrawCircle(1060, 80+(i*80), 30, WHITE);
                    if(game->boardsize == 12) DrawCircle(1220, 80+(i*80), 30, WHITE);
                } else {
                    DrawCircle(340, 80+(i*80), 30, BLACK);
                    DrawCircle(500, 80+(i*80), 30, BLACK);
                    DrawCircle(660, 80+(i*80), 30, BLACK);
                    DrawCircle(820, 80+(i*80), 30, BLACK);
                    if(game->boardsize >= 10) DrawCircle(980, 80+(i*80), 30, WHITE);
                    if(game->boardsize == 12) DrawCircle(1140, 80+(i*80), 30, WHITE);
                }
            }
        }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();
}

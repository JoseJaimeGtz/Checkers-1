#include "checkersLibrary.h"

int main() {
    int gameDrawn = 0;
    int mainDrawn = 0;
    struct gameStruct game;
    struct mainButtons board;
    ScreenFlag *screen = malloc(sizeof(ScreenFlag));
    
    InitWindow(1240, 760, "Checkers");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        Vector2 mouse = GetMousePosition();

        BeginDrawing();

        switch(*screen)
        {
            case MAIN:
                if(mainDrawn == 0){
                    ClearBackground(WHITE);
                    drawMain(&game, &board, screen);
                    mainDrawn = 1;
                }
                checkMainButton(&game, &board, screen);
                break;

            case GAME:
                if(gameDrawn == 0){
                    ClearBackground(WHITE);
                    drawGame(&game, &board, screen);
                    gameDrawn = 1;
                }
                checkGameButton(&game, &board, screen);   
                break;

            case SAVE:

                break;

            case LOAD:

                break;

        }

        EndDrawing();

    }
    CloseWindow();
}
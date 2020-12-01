#include "checkersLibrary.h"

int main() {
    int gameDrawn = 0;
    int mainDrawn = 0;
    int saveDrawn = 0;
    int loadDrawn = 0;
    struct gameStruct game;
    struct mainButtons board;
    ScreenFlag *screen = malloc(sizeof(ScreenFlag));
    queueRef queue = queueCreate(&game);
    
    InitWindow(1560, 1040, "Checkers");
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
                    loadDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                }
                checkMainButton(&game, &board, screen);
                break;
            case GAME:
                if(gameDrawn == 0){
                    ClearBackground(WHITE);
                    drawGame(&game, &board, screen);
                    gameDrawn = 1;
                    saveDrawn = 0;
                    mainDrawn = 0;
                    loadDrawn = 0;
                }
                checkGameButton(&game, &board, screen);   
                break;

            case SAVE:
                if(saveDrawn == 0){
                    ClearBackground(WHITE);
                    drawSave(&game, &board, screen);
                    saveDrawn = 1;
                    gameDrawn = 0;
                    mainDrawn = 0;
                    loadDrawn = 0;
                }
                checkSaveButton(&game, &board, screen);   
                break;

            case LOAD:
                if(loadDrawn == 0){
                    ClearBackground(WHITE);
                    drawLoad(&game, &board, screen);
                    loadDrawn = 1;
                    mainDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                }
                checkLoadButton(&game, &board, screen);   
                break;

        }

        EndDrawing();

    }
    CloseWindow();
}
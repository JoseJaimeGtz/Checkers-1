#include "checkersLibrary.h"

int main() {
    int gameDrawn = 0;
    int mainDrawn = 0;
    int saveDrawn = 0;
    int loadDrawn = 0;
    struct gameStruct game;
    struct mainButtons board;
    ScreenFlag *screen = malloc(sizeof(ScreenFlag));
    Queue* queue = queueCreate();
    
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
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
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
                checkGameButton(&game, &board, screen, queue);   
                break;

            case SAVE:
                if(saveDrawn == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
                    drawSave(&game, &board, screen);
                    saveDrawn = 1;
                    gameDrawn = 0;
                    mainDrawn = 0;
                    loadDrawn = 0;
                }
                checkSaveButton(&game, &board, screen, queue);   
                break;

            case LOAD:
                if(loadDrawn == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
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
#include "checkersLibrary.h"

int main() {
    int gameDrawn = 0;
    int mainDrawn = 0;
    int saveDrawn = 0;
    int loadDrawn = 0;
    int winWhite = 0;
    int winBlack = 0;
    struct gameStruct game;
    struct mainButtons board;
    ScreenFlag *screen = malloc(sizeof(ScreenFlag));
    Queue* queue = queueCreate();
    
    InitWindow(1240, 760, "Checkers");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        switch(*screen)
        {
            case MAIN:
                if(mainDrawn == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
                    drawMain(&game, &board);
                    mainDrawn = 1;
                    loadDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                    winWhite = 0;
                    winBlack = 0;
                }
                checkMainButton(&game, &board, screen);
                break;
            case GAME:
                if(gameDrawn == 0){
                    ClearBackground(WHITE);
                    drawGame(&game);
                    gameDrawn = 1;
                    saveDrawn = 0;
                    mainDrawn = 0;
                    loadDrawn = 0;
                    winWhite = 0;
                    winBlack = 0;
                }
                checkGameButton(&game, screen, queue);
                winner(&game, screen);   
                break;

            case SAVE:
                if(saveDrawn == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
                    drawSave();
                    saveDrawn = 1;
                    gameDrawn = 0;
                    mainDrawn = 0;
                    loadDrawn = 0;
                    winWhite = 0;
                    winBlack = 0;
                }
                checkSaveButton(&game, screen, queue);
                break;

            case LOAD:
                if(loadDrawn == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
                    drawLoad();
                    loadDrawn = 1;
                    mainDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                    winWhite = 0;
                    winBlack = 0;
                }
                checkLoadButton(&game, screen, queue);
                break;
            case WIN_BLACK:
                if(winBlack == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(BLACK);
                    SetWindowSize(1240, 760);
                    drawWinBlack();
                    winBlack = 1;
                    loadDrawn = 0;
                    mainDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                    winWhite = 0;
                }
                checkBlackButton(screen);
                break;
            case WIN_WHITE:
                if(winWhite == 0){
                    SetWindowSize(1240, 760);
                    ClearBackground(WHITE);
                    SetWindowSize(1240, 760);
                    drawWinWhite();
                    winWhite = 1;
                    loadDrawn = 0;
                    mainDrawn = 0;
                    gameDrawn = 0;
                    saveDrawn = 0;
                    winBlack = 0;
                }
                checkWhiteButton(screen);
                break;
        }
        EndDrawing();
    }
    CloseWindow();
    queueDestroy(queue);
}

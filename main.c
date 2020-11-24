#include "graphics.h"
#include "gameLogic.h"

int main() {
    struct gameStruct game;
    struct mainButtons board;
    ScreenFlag *screen = malloc(sizeof(ScreenFlag));
    
    InitWindow(1240, 760, "Checkers");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        Vector2 mouse = GetMousePosition();

        BeginDrawing();
        ClearBackground(WHITE);

        switch(*screen)
        {
            case MAIN:
                drawMain(&game, &board, screen);
                break;

            case GAME:
                drawGame(&game, &board, screen);
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
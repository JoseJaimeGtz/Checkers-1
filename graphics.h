#include "game.h"

typedef enum {
    MAIN,
    GAME,
    SAVE,
    LOAD
} ScreenFlag;

struct mainButtons{
    Rectangle board8x8, board10x10, board12x12, startButton;
};

typedef struct mainButtons* mainButtonsStruct;

void drawMain(gameStructRef game, mainButtonsStruct board);

void checkMainButton(mainButtonsStruct board);
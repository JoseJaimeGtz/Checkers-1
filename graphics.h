
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
void updateBoard(gameStructRef game);
void drawGame(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkGameButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

void drawMain(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkMainButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

void drawSave(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkSaveButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

void deleteSelected(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

// COLORS
#define BOARD (Color){ 166, 98, 0, 255 }
#define BLACKPIECES (Color){4, 31, 30, 255}
#define WHITEPIECES (Color){239, 241, 243, 255}
#define BLACKPIECESKING (Color){4, 31, 30, 255}
#define WHITEPIECESKING (Color){239, 241, 243, 255}
#define POSSIBLE (Color) {240, 246, 0, 255}
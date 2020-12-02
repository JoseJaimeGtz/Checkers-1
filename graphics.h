
void updateBoard(gameStructRef game);
void drawGame(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkGameButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

void drawMain(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkMainButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

void drawSave(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkSaveButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

void drawLoad(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);
void checkLoadButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

// COLORS
#define BOARD (Color){ 166, 98, 0, 255 }
#define BLACKPIECES (Color){60, 60, 60, 255}
#define WHITEPIECES (Color){239, 241, 243, 195}
#define BLACKPIECESKING (Color){1, 1, 1, 255}
#define WHITEPIECESKING (Color){255, 255, 255, 255}
#define POSSIBLE (Color) {240, 246, 0, 255}

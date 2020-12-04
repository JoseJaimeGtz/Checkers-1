/*
 * @param game receives gameStruct
 * @param board receives a pointer to a struct where positions from buttons are saved
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the main menu screen
 */
void checkMainButton(gameStructRef game, mainButtonsStruct board, ScreenFlag *screen);

/*
 * @param game receives gameStruct
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the load menu screen
 */
void checkLoadButton(gameStructRef game, ScreenFlag *screen, Queue* queue);

/*
 * @param game receives gameStruct
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the game screen
 */
void checkGameButton(gameStructRef game, ScreenFlag *screen, Queue* queue);

/*
 * @param game receives gameStruct
 * @param board receives a pointer to a struct where positions from buttons are saved
 * This function draws the main menu
 */
void drawMain(gameStructRef game, mainButtonsStruct board);

/*
 * @param game receives gameStruct
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the save menu screen
 */
void checkSaveButton(ScreenFlag *screen, Queue* queue);

/*
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the black win message
 */
void checkBlackButton(ScreenFlag *screen);

/*
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function checks if you click a button in the white win message
 */
void checkWhiteButton(ScreenFlag *screen);

/*
 * @param game receives gameStruct
 * This function draws everything that is needed for the board
 * The current background is cleared, and everything is re-drawn
 */
void updateBoard(gameStructRef game);

/*
 * @param game receives gameStruct
 * This function draws the game
 */
void drawGame(gameStructRef game);

/*
 * This function draws the black win message
 */
void drawWinBlack();

/*
 * This function draws the white win message
 */
void drawWinWhite();

/*
 * This function draws the load menu
 */
void drawLoad();

/*
 * This function draws the save menu
 */
void drawSave();

/*
  * Custom colors we used for our board
*/
#define BOARD (Color){ 166, 98, 0, 255 }
#define BLACKPIECES (Color){60, 60, 60, 255}
#define WHITEPIECES (Color){239, 241, 243, 195}
#define BLACKPIECESKING (Color){1, 1, 1, 255}
#define WHITEPIECESKING (Color){255, 255, 255, 255}
#define POSSIBLE (Color) {240, 246, 0, 255}

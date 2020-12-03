/*
 * Structures
 */

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

struct pieceStruct{
    int color;
    int type;
    Rectangle circle;
};
typedef struct pieceStruct* pieceStructRef;

struct Node_struct {
    int newX, newY, currentX, currentY, currentPlayer;
    struct Node_struct* next;
} Node ;
typedef struct Node_struct* nodeRef;

typedef struct {
    nodeRef First;
    nodeRef Last;
    int count, currentMove;
} Queue ;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow, boardCreated, mainCreated;
    int currentPlayer;
    int currentPiecex, currentPiecey;
    int currentColor;
    int totalWhitePieces;
    int totalBlackPieces;
    pieceStructRef board[13][13];
};
typedef struct gameStruct* gameStructRef;

/*
 * Functions
 */

/*
 * @param menu receives a Menu type structure
 * @param color receives the color of the piece (0 = empty space; 1 = black piece; 2 = white piece;)
 * @param type receives the type of the piece (0 = empty space; 1 = pawn; 2 = king; 3 = valid space;)
 * This function creates all pieces and empty spaces.
 */
pieceStructRef newPiece(int color, int type);

/*
 * @param game receives gameStruct
 * This function creates all the pieces and empty spaces when newPiece was called, also initialize
 * the position of the pieces, total black and white pieces, and the first turn.
 */
void createBoard(gameStructRef game);

/*
* This function creates a queue
*/
Queue* queueCreate();

/*
 * @param queue receives a pointer to a queue that already exists
 * @param currentX
 * @param currentY
 * @param newX
 * @param newY
 * @param currentPlayer
*/
void queueOffer(Queue* queue, int currentX, int currentY, int newX, int newY, int currentPlayer);

/*
 * This function removes a node from the queue, and returns a struct of the removed node
 * @param queue receives a pointer to a queue that already exists
*/
nodeRef queuePoll(Queue* queue);

/*
 * This function destroy the queue
 * @param queue receives a pointer to a queue that already exists
*/
void queueDestroy(Queue* queue);

/*
 * This function creates a new node
 * @param currentX
 * @param currentY
 * @param newX
 * @param newY
 * @param currentPlayer
*/
nodeRef newNode(int currentX, int currentY, int newX, int newY, int currentPlayer);

/*
 * This function saves the current game in a text file
 * @param game receives gameStruct
 * @param slot receives a number from 1 to 3
 * @param queue receives a pointer to a queue that already exists
*/
void saveGame(gameStructRef game, int slot, Queue* queue);

/*
 * This function loads a saved game from a text file
 * @param game receives gameStruct
 * @param slot receives a number from 1 to 3
 * @param board
 * @param screen
*/
void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

// Ir al siguiente movimiento (si es posible)
void nextMovement(gameStructRef game, Queue* queue);

// Regresar el movimiento
void previousMovement(gameStructRef game, Queue* queue);
/*
 * Structures
*/

typedef enum {
    MAIN,
    GAME,
    SAVE,
    LOAD,
    WIN_BLACK,
    WIN_WHITE
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
    struct Node_struct* prev;
} Node ;
typedef struct Node_struct* nodeRef;

typedef struct {
    nodeRef First;
    nodeRef Last;
    int count;
} Queue ;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow, boardCreated, mainCreated;
    int currentPlayer;
    int currentPiecex, currentPiecey;
    int currentColor;
    int totalWhitePieces;
    int totalBlackPieces;
    pieceStructRef board[500][500];
};
typedef struct gameStruct* gameStructRef;

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
 * @param currentX receives the current X position of the piece in the board
 * @param currentY receives the current Y position of the piece in the board
 * @param newX receives the new X position of the piece in the board
 * @param newY receives the new Y position of the piece in the board
 * @param currentPlayer receives the player that moved the piece
*/
void queueOffer(Queue* queue, int currentX, int currentY, int newX, int newY, int currentPlayer);

/*
 * This function removes the first node from the queue, and returns a struct of the removed node
 * @param queue receives a pointer to a queue that already exists
*/
nodeRef queuePoll(Queue* queue);

/*
 * This function removes the last node from the queue, and returns a struct of the removed node
 * @param queue receives a pointer to a queue that already exists
*/
nodeRef queuePollInv(Queue* queue);

/*
 * This function destroy the queue
 * @param queue receives a pointer to a queue that already exists
*/
void queueDestroy(Queue* queue);

/*
 * This function creates a new node with the given parameters
 * @param currentX receives the current X position of the piece
 * @param currentY receives the current Y position of the piece
 * @param newX receives the new X position of the piece
 * @param newY receives the new Y position of the piece
 * @param currentPlayer receives the player that moved the piece
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
 * @param board receives a pointer to a struct where positions from buttons are saved
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
*/
void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

/*
 * This function makes the game go back 1 movement
 * @param game receives gameStruct
 * @param queue receives a pointer to a queue that already exists
*/
void previousMovement(gameStructRef game, Queue* queue);
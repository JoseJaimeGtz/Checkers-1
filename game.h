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
 * Queue & file management
 */


// Crear la estructura de queue
Queue* queueCreate();

// Agregar un nodo pieceStruct a la queue
void queueOffer(Queue* queue, int currentX, int currentY, int newX, int newY, int currentPlayer);

// Remover un nodo pieceStruct de la queue
nodeRef queuePoll(Queue* queue);

// Eliminar la queue
void queueDestroy(Queue* queue);

nodeRef newNode(int currentX, int currentY, int newX, int newY, int currentPlayer);

/*
    Funciones para el manejo de archivos
*/

// Guardar el juego
void saveGame(gameStructRef game, int slot, Queue* queue);

// Cargar el juego
void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

// Ir al siguiente movimiento (si es posible)
void nextMovement(gameStructRef game, Queue* queue);

// Regresar el movimiento
void previousMovement(gameStructRef game, Queue* queue);
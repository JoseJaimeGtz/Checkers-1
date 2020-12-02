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
    int color; // 0 = nothing; 1 = black ; 2 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king ; 3 = colored
    Rectangle circle;
};

typedef struct pieceStruct* pieceStructRef;

// Nodos para el queue
struct Node_struct {
    int newX, newY, currentX, currentY, currentPlayer; // dato
    struct Node_struct* next; // apuntador al siquiente
} Node ;
typedef struct Node_struct* nodeRef;

// Estructura de la queue
typedef struct {
    nodeRef First;
    nodeRef Last;
    int count;
} Queue ;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow, boardCreated, mainCreated;
    int currentPlayer; // Turno 1 blanco, 0 negro
    int currentPiecex, currentPiecey;
    int currentColor;
    int totalWhitePieces;
    int totalBlackPieces;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
}; 
 
typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void createBoard(gameStructRef game);

pieceStructRef newPiece(gameStructRef game, int color, int type);

//
//  Queue & file management
//

/*
    Funciones para el manejo de la queue
*/

// Crear la estructura de queue
Queue* queueCreate();

// Agregar un nodo pieceStruct a la queue
void queueOffer(Queue* queue, int newX, int newY, int currentX, int currentY, int currentPlayer);

// Remover un nodo pieceStruct de la queue
nodeRef queuePoll(Queue* queue);

// Eliminar la queue
void queueDestroy(Queue* queue);

nodeRef newNode(int newX, int newY, int currentX, int currentY, int currentPlayer);

/*
    Funciones para el manejo de archivos
*/

// Guardar el juego
void saveGame(gameStructRef game, int slot, Queue* queue);

// Cargar el juego
void loadGame(gameStructRef game, int slot, mainButtonsStruct board, ScreenFlag *screen, Queue* queue);

// Ir al siguiente movimiento (si es posible)
void nextMovement();

// Regresar el movimiento
void previousMovement();
struct pieceStruct{
    int color; // 0 = nothing; 1 = black ; 2 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king ; 3 = colored
    Rectangle circle;
};

typedef struct pieceStruct* pieceStructRef;

// Nodos para el queue
struct Node_struct {
    struct pieceStruct* data; // dato
    struct Node_struct* next; // apuntador al siquiente
};
typedef struct Node_struct* nodeRef;

// Estructura de la queue
struct Queue {
    nodeRef First;
    nodeRef Last;
    int count;
};
typedef struct Queue* queueRef;

struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow, boardCreated, mainCreated;
    int currentPlayer; // Turno 1 blanco, 0 negro
    int currentPiecex, currentPiecey;
    int currentColor;
    int totalWhitePieces;
    int totalBlackPieces;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
    queueRef queue;
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
queueRef queueCreate(gameStructRef game);

// Agregar un nodo pieceStruct a la queue
void queueOffer(gameStructRef gam);

// Remover un nodo pieceStruct de la queue
pieceStructRef queuePoll(queueRef q);

// Eliminar la queue
void queueDestroy(queueRef q);

/*
    Funciones para el manejo de archivos
*/

// Guardar el juego
void saveGame(gameStructRef game, int slot);

// Cargar el juego
void loadGame(gameStructRef game);

// Ir al siguiente movimiento (si es posible)
void nextMovement();

// Regresar el movimiento
void previousMovement();
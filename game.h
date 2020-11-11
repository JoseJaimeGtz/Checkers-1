//
// Estructuras
//

struct pieceStruct{
    int color;
    int king;
    int x;
    int y;
    struct pieceStruct* next;
};
typedef struct pieceStruct* Pieces;

struct board{
    int currentPlayer;
    int whitePieces;
    int blackPieces;
    Pieces pieces;
};
typedef struct board* Board;

//
//  Funciones
//

void startGame(Board);

// Crea un nuevo nodo con valor 'value' y retorna la referencia.
Pieces newPiece(int, int, int);

// libera la memoria de todos los elementos de una lista exceptuando el primero (first)
void destroyPice(Pieces);

// Agrega un nodo 'newNode' a la lista
void addPiece(Pieces, Pieces);

// Elimina el nodo 'nodeToRemove' de la lista, regresa 1 si se eliminó, 0 si no se eliminó.
int removePiece(Pieces *, int);

void initBoard(Board, int);

void printBoard(Board);

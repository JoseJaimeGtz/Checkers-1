struct pieceStruct{
    int color; // 0 = nothing; 1 = black ; 2 = white
    int type; // 0 = nothing ; 1 = normal ; 2 = king ; 3 = colored
    Rectangle circle;
};

typedef struct pieceStruct* pieceStructRef;

// TO-DO
// guardar en la estructura la ficha seleccionada actual y el espacio amarillo actual (que se hace con el click)
// los cuales se modificarán cada vez que se haga click
// si se hace click en una posicion amarilla y que no tenga tipo (type == 0) que se dibuje la ficha en la posicion de la amarilla
// pasar toda la informacion de la ficha actual (seleccionada) a la nueva posicion (a la estructura vacia seleccionada)
struct gameStruct{
    int boardsize, screenWidth, screenHeight, currentWindow, boardCreated;
    int currentPlayer; // Turno 1 blanco, 0 negro
    int currentPiecex, currentPiecey;
    pieceStructRef board[13][13]; // 8x8 10x10 12x12
}; 
 
typedef struct gameStruct* gameStructRef;

//
//  Funciones
//

void createBoard(gameStructRef game);

pieceStructRef newPiece(gameStructRef game, int color, int type);
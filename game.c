#include <stdio.h>
#include <stdlib.h>

#include "game.h"

Pieces newPiece(int x, int y, int color)
{
    Pieces new = malloc(sizeof(struct pieceStruct));
    if(new == NULL)
        exit(EXIT_FAILURE);
    new->x = x;
    new->y = y;
    new->color = color;
    new->king = 0;
    new->next = NULL;
    return new;
}

// implementar despues
void DestroyPice(Pieces first)
{
    if(first != NULL)
    {
        DestroyPice(first->next);
        free(first);
        first = NULL;
    }

}

void addPiece(Pieces piece, Pieces newPiece)
{
    while(piece->next != NULL)
    {
        piece = piece->next;
    }
    piece->next = newPiece;
}

void startGame(Board board)
{
    int boardSize;
    printf("ADVERTENCIA: El tamaño del tablero se establece a partir de 8x8 "
           "con un maximo de 20x20 para una mejor visualización del juego.\n\n");
    printf("Determina el tamaño del tablero:");
    scanf("\n%d",&boardSize);
    while (boardSize%2 != 0 || boardSize<8 || boardSize>20){
        if (boardSize%2 != 0){
            printf("El tamaño del tablero tiene que ser numero par!\n");
        } else {
            printf("Recuerda que el tamaño minimo del tablero es 8x8 y el"
                   "maximo es de 20x20 para una mejor visualización!\n");
        }
        printf("Determina el tamaño del tablero:");
        scanf("\n%d",&boardSize);
    }
    printf("Creando tablero de tamaño %dx%d", boardSize,boardSize);
    initBoard(board, boardSize);

    // while para el tablero
}

void initBoard(Board board, int boardSize){
    board->currentPlayer = 0;
    // verificar si si se puede eliminar la primera ficha creada
    // eliminar la primera pieza creada (la siguiente linea)
    Pieces piece_ref = newPiece(0, 0, 0);

    // las posiciones de las lineas impares estan mal

    // que empiece en 1 para que todas las fichas esten en posicion par
    for (int x = 1; x <= boardSize; ++x) {
        for (int y = 1; y <= boardSize; ++y) {
            // si es la mitad del tablero -1 por la linea vacia de enmedio
            if (x <= boardSize/2-1 && y%2 == 0 && x%2!=0){
                addPiece(piece_ref, newPiece(x, y, 1));
                board->whitePieces++;
            } else if ((x != boardSize/2 || x != boardSize/2+1) && y%2 == 0){
                addPiece(piece_ref, newPiece(x, y, 0));
                board->blackPieces++;
            }
        }
    }
}

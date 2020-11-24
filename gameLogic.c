#include "gameLogic.h"
#include "game.h"

int isPossible(gameStructRef game, int currentX, int currentY)
{
    // nivel de abstracción superior
    if(game->currentPlayer == "blancas"){
        if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
            pieceDown(game, currentX, currentY, 1);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY-1 >= 1){ // verifica si se puede mover hacia adelante
                pieceUp(game, currentX, currentY, 1);
            }
        }
    } else if(game->currentPlayer == "negras") { // porque el rodri luego se confunde
        if(currentY-1 >= 1){
            pieceUp(game, currentX, currentY, 2);
        } else {
            // Significa que es king
            game->board[currentX][currentY]->type = 2;
            if(currentY+1 <= game->boardsize){ // verifica si se puede mover hacia adelante
                pieceUp(game, currentX, currentY, 2);
            }
        }
    }
    return 0;
}
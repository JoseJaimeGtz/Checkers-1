#include "game.h"

void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY);
int pieceDown(gameStructRef game, int currentX, int currentY, int op_piese);
int pieceUp(gameStructRef game, int currentX, int currentY, int op_piese);
int isPossible(gameStructRef game, int currentX, int currentY);
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void movePiece(gameStructRef, int, int, int, int);
int pieceDown(gameStructRef, int, int, int);
int pieceUp(gameStructRef, int, int, int);
int isPossible(gameStructRef, int, int);

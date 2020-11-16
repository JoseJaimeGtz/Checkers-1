#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int isPossible(gameStructRef game, int currentX, int currentY);
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY);
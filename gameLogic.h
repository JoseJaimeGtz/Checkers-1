void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY);
int pieceDown(gameStructRef game, int currentX, int currentY, int op_piese, int draw);
int pieceUp(gameStructRef game, int currentX, int currentY, int op_piese, int draw);
int isPossible(gameStructRef game, int currentX, int currentY);
void turnPieces(gameStructRef game, int x, int y);
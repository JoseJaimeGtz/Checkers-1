void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY, int currentPlayer);
void eatPiece(gameStructRef game, int newX, int newY, int currentX, int currentY, int op_piese);
void pieceDown(gameStructRef game, int currentX, int currentY, int op_piese, int draw);
void pieceUp(gameStructRef game, int currentX, int currentY, int op_piese, int draw);
void isPossible(gameStructRef game, int currentX, int currentY);
void turnPieces(gameStructRef game, int x, int y);
void deleteAll(gameStructRef game);
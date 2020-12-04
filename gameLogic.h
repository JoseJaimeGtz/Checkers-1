/*
 * @param game receives gameStruct
 * @param currentX receives the current position x of the piece selected
 * @param currentY receives the current position y of the piece selected
 * @param newX receives the position of the new position of x of the yellow square selected
 * @param newY receives the position of the new position of y of the yellow square selected
 * @param currentPlayer receives the current player (0 = black; 1 = white;)
 * This function moves the piece selected to the next valid position and call eatPiece function
 * to verify if in the move you eat a piece.
 * Also, this function calls updateBoard for update the board.
 * This function is called by checkGameButton function.
 */
void movePiece(gameStructRef game, int currentX, int currentY, int newX, int newY, int currentPlayer);

/*
 * @param game receives gameStruct
 * @param currentX receives the current position x of the piece selected
 * @param currentY receives the current position y of the piece selected
 * @param newX receives the position of the new position of x of the yellow square selected
 * @param newY receives the position of the new position of y of the yellow square selected
 * @param op_piece receives the opponent piece (1 = black; 2 = white;)
 * This function check if in the turn you eat an opponent piece and decrease opponent pieces.
 * Also, this function calls winner function all the time.
 */
void eatPiece(gameStructRef game, int newX, int newY, int currentX, int currentY, int op_piece);

/*
 * @param game receives gameStruct
 * @param currentX receives the current position x of the piece selected
 * @param currentY receives the current position y of the piece selected
 * @param op_piece receives the opponent piece (1 = black; 2 = white;)
 * This function checks if the piece selected in the next position (left and right in +y) is a valid move
 * and draw a yellow square, if not, check if there is a opponent piece and if the next two positions
 * (left and right in +y) is an empty space and draw a yellow square.
 * This function is called by isPossible function.
 */
void pieceDown(gameStructRef game, int currentX, int currentY, int op_piece);

/*
 * @param game receives gameStruct
 * @param currentX receives the current position x of the piece selected
 * @param currentY receives the current position y of the piece selected
 * @param op_piece receives the opponent piece (1 = black; 2 = white;)
 * This function checks if the piece selected in the next position (left and right in -y) is a valid move
 * and draw a yellow square, if not, check if there is a opponent piece and if the next two positions
 * (left and right in -y) is an empty space and draw a yellow square.
 * This function is called by isPossible function.
 */
void pieceUp(gameStructRef game, int currentX, int currentY, int op_piece);

/*
 * @param game receives gameStruct
 * @param currentX receives the current position x of the piece selected
 * @param currentY receives the current position y of the piece selected
 * This function checks the current payer and verify if the piece selected is a pawn or is a king
 * if the piece selected is a pawn, call pieceDown or pieceUp function (depending of the currentPlayer)
 * if the piece selected is a king, call pieceDown and pieceUp functions.
 * This functions is called by turnPieces function.
 */
void isPossible(gameStructRef game, int currentX, int currentY);

/*
 * @param game receives gameStruct
 * @param screen receives a pointer to a struct where we select the screen that is being displayed
 * This function compares if one player wins and shows a new window with the name of the winner player.
 * This function is called by eatPiece function.
 */
void winner(gameStructRef game, ScreenFlag *screen);

/*
 * @param game receives gameStruct
 * @param x receives position x of the piece selected
 * @param y receives position y of the piece selected
 * This function checks the current payer and the piece selected, if it's true, call isPossible function.
 * Also, this function calls deleteAll function all the time.
 * This function is called by checkGameButton function.
 */
void turnPieces(gameStructRef game, int x, int y);

/*
 * @param game receives gameStruct
 * This function makes all positions change to their original type, 0.
 * This function is called by turnPieces function.
 */
void deleteAll(gameStructRef game);

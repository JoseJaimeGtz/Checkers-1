#include "checkersLibrary.h"

void movePiece(gameStructRef game, int newX, int newY, int currentX, int currentY, int currentPlayer)
{
    if(game->currentPlayer == 1 || currentPlayer == 1){
        game->board[newX][newY]->color = game->board[currentX][currentY]->color;
        game->board[newX][newY]->type = game->board[currentX][currentY]->type;
        DrawCircle(340+(80*(newX-1)), 80+(80*(newY-1)), 30, WHITEPIECES);
        if(newY == game->boardsize){
            game->board[newX][newY]->type = 2;
        }
        game->board[currentX][currentY]->color = 0;
        game->board[currentX][currentY]->type = 0;
        DrawCircle(340+(80*(currentX-1)), 80+(80*(currentY-1)), 30, BOARD);
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, WHITE);
        DrawText("negras", ((game->screenWidth)-200), 100, 20, WHITE);
        game->currentPlayer = 0;
        eatPiece(game, newX, newY, currentX, currentY, 0);
    } else if(game->currentPlayer == 0 || currentPlayer == 0){
        game->board[newX][newY]->color = game->board[currentX][currentY]->color;
        game->board[newX][newY]->type = game->board[currentX][currentY]->type;
        DrawCircle(340+(80*(newX-1)), 80+(80*(newY-1)), 30, BLACKPIECES);
        if(newY == 1){
            game->board[newX][newY]->type = 2;
        }
        game->board[currentX][currentY]->color = 0;
        game->board[currentX][currentY]->type = 0;
        DrawCircle(340+(80*(currentX-1)), 80+(80*(currentY-1)), 30, BOARD);
        DrawRectangle((game->screenWidth)-250, 40, 200, 120, RAYWHITE);
        DrawRectangleLines((game->screenWidth)-250, 40, 200, 120, BLACK);
        DrawText("Turno de:", ((game->screenWidth)-200), 60, 20, BLACK);
        DrawText("blancas", ((game->screenWidth)-200), 100, 20, BLACK);
        game->currentPlayer = 1;
        eatPiece(game, newX, newY, currentX, currentY, 1);
    }
    updateBoard(game);
}

void eatPiece(gameStructRef game, int newX, int newY, int currentX, int currentY, int op_piece){
    int eatPiece = 0;
    if(currentY - newY == 2 || currentY - newY == -2){
        if(currentY - newY == 2){
            if(currentX - newX == 2){
                game->board[currentX-1][currentY-1]->color = 0;
                game->board[currentX-1][currentY-1]->type = 0;
                eatPiece = 1;
            } else {
                game->board[currentX+1][currentY-1]->color = 0;
                game->board[currentX+1][currentY-1]->type = 0;
                eatPiece = 1;
            }
        } else {
            if(currentX - newX == 2){
                game->board[currentX-1][currentY+1]->color = 0;
                game->board[currentX-1][currentY+1]->type = 0;
                eatPiece = 1;
            } else {
                game->board[currentX+1][currentY+1]->color = 0;
                game->board[currentX+1][currentY+1]->type = 0;
                eatPiece = 1;
            }
        }
    }
    if(op_piece == 0 && eatPiece == 1){
        game->totalBlackPieces--;
    } else if(op_piece == 1 && eatPiece == 1) {
        game->totalWhitePieces--;
    }
}

void pieceDown(gameStructRef game, int currentX, int currentY, int op_piece){
    if(currentX+1 <= game->boardsize){
        if (game->board[currentX+1][currentY+1]->color == 0){
            int posx = game->board[currentX][currentY]->circle.x+80;
            int posy = game->board[currentX][currentY]->circle.y+80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            DrawRectangle(posx, posy, w, h, POSSIBLE);
            game->board[currentX+1][currentY+1]->type = 3;
        } else if (game->board[currentX+1][currentY+1]->color == op_piece){
            if(currentY+2 <= game->boardsize && currentX+2 <= game->boardsize) {
                if(game->board[currentX+2][currentY+2]->color == 0){
                    int posx = game->board[currentX][currentY]->circle.x+160;
                    int posy = game->board[currentX][currentY]->circle.y+160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    DrawRectangle(posx, posy, w, h, POSSIBLE);
                    game->board[currentX+2][currentY+2]->type = 3;
                }
            }
        }
    }
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY+1]->color == 0){
            int posx = game->board[currentX][currentY]->circle.x-80;
            int posy = game->board[currentX][currentY]->circle.y+80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            DrawRectangle(posx, posy, w, h, POSSIBLE);
            game->board[currentX-1][currentY+1]->type = 3;
        }  else if (game->board[currentX-1][currentY+1]->color == op_piece) {
            if(currentY+2 <= game->boardsize && currentX-2 >= 1){
                if (game->board[currentX-2][currentY+2]->color == 0){
                    int posx = game->board[currentX][currentY]->circle.x-160;
                    int posy = game->board[currentX][currentY]->circle.y+160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    DrawRectangle(posx, posy, w, h, POSSIBLE);
                    game->board[currentX-2][currentY+2]->type = 3;
                }
            }
        }
    }
}

void pieceUp(gameStructRef game, int currentX, int currentY, int op_piece) {
    if(currentX+1 <= game->boardsize){
        if (game->board[currentX+1][currentY-1]->color == 0){
            int posx = game->board[currentX][currentY]->circle.x+80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            DrawRectangle(posx, posy, w, h, POSSIBLE);
            game->board[currentX+1][currentY-1]->type = 3;
        } else if (game->board[currentX+1][currentY-1]->color == op_piece){
            if(currentY-2 >= 1 && currentX+2 <= game->boardsize) {
                if(game->board[currentX+2][currentY-2]->color == 0){
                    int posx = game->board[currentX][currentY]->circle.x+160;
                    int posy = game->board[currentX][currentY]->circle.y-160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    DrawRectangle(posx, posy, w, h, POSSIBLE);
                    game->board[currentX+2][currentY-2]->type = 3;
                }
            }
        }
    }
    if(currentX-1 >= 1){
        if (game->board[currentX-1][currentY-1]->color == 0){
            int posx = game->board[currentX][currentY]->circle.x-80;
            int posy = game->board[currentX][currentY]->circle.y-80;
            int w = game->board[currentX][currentY]->circle.width;
            int h = game->board[currentX][currentY]->circle.height;
            DrawRectangle(posx, posy, w, h, POSSIBLE);
            game->board[currentX-1][currentY-1]->type = 3;
        }  else if (game->board[currentX-1][currentY-1]->color == op_piece) {
            if(currentY-2 >= 1 && currentX-2 >= 1){
                if (game->board[currentX-2][currentY-2]->color == 0){
                    int posx = game->board[currentX][currentY]->circle.x-160;
                    int posy = game->board[currentX][currentY]->circle.y-160;
                    int w = game->board[currentX][currentY]->circle.width;
                    int h = game->board[currentX][currentY]->circle.height;
                    DrawRectangle(posx, posy, w, h, POSSIBLE);
                    game->board[currentX-2][currentY-2]->type = 3;
                }
            }
        }
    }
}

void isPossible(gameStructRef game, int currentX, int currentY)
{
    if(game->currentPlayer){
        if(currentY+1 <= game->boardsize && game->board[currentX][currentY]->type == 1){
            pieceDown(game, currentX, currentY, 1);
        } else {
            if(currentY+1 <= game->boardsize && game->board[currentX][currentY]->type == 2){
                pieceDown(game, currentX, currentY, 1);
            }
            if(currentY-1 >= 1 && game->board[currentX][currentY]->type == 2){
                pieceUp(game, currentX, currentY, 1);
            }
        }
    } else {
        if(currentY-1 >= 1 && game->board[currentX][currentY]->type == 1){
            pieceUp(game, currentX, currentY, 2);
        } else {
            if(currentY-1 >= 1 && game->board[currentX][currentY]->type == 2){
                pieceUp(game, currentX, currentY, 2);
            }
            if(currentY+1 <= game->boardsize && game->board[currentX][currentY]->type == 2){
                pieceDown(game, currentX, currentY, 2);
            }
        }
    }
}

void winner(gameStructRef game, ScreenFlag *screen){
    if(game->totalWhitePieces == 0) *screen = WIN_WHITE;
    if(game->totalBlackPieces == 0) *screen = WIN_BLACK;
}

void turnPieces(gameStructRef game, int x, int y){
    deleteAll(game);
    if(game->currentPlayer){
        if(game->board[x][y]->color == 2){
            isPossible(game, x, y);
        }
    } else {
        if(game->board[x][y]->color == 1){
            isPossible(game, x, y);
        }
    }
}

void deleteAll(gameStructRef game)
{
    for(int y = 1; y <= game->boardsize; y++){
        for(int x = 1; x <= game->boardsize; x++){
            if((y%2!=0 && x%2==0) || (y%2==0 && x%2!=0)){
                if(game->board[x][y]->type == 3){
                    game->board[x][y]->type = 0;
                }
            }
        }
    }
}

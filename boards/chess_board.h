#include "../pieces/pieces.h"
#include "board.h"

class ChessBoard : public Board {
public:
  ChessBoard() : Board(Position({8, 8})) {
    board[0][2] = new Knight(BLACK);
    board[0][5] = new Knight(BLACK);
    board[7][2] = new Knight(WHITE);
    board[7][5] = new Knight(WHITE);
  }
};

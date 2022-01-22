#include "../pieces/pieces.h"
#include "board.h"

class ChessBoard : public Board {
  static const int DIM = 8;

public:
  ChessBoard() : Board(Position({DIM, DIM})) {
    for (int x = 0; x < DIM; x++) {
      board[1][x] = new Pawn(BLACK);
      board[6][x] = new Pawn(WHITE);
    }
    board[0][0] = new Rook(BLACK);
    board[0][7] = new Rook(BLACK);
    board[7][0] = new Rook(WHITE);
    board[7][7] = new Rook(WHITE);
    board[0][1] = new Bishop(BLACK);
    board[0][6] = new Bishop(BLACK);
    board[7][1] = new Bishop(WHITE);
    board[7][6] = new Bishop(WHITE);
    board[0][2] = new Knight(BLACK);
    board[0][5] = new Knight(BLACK);
    board[7][2] = new Knight(WHITE);
    board[7][5] = new Knight(WHITE);
    board[0][3] = new Queen(BLACK);
    board[7][3] = new Queen(WHITE);
    board[0][4] = new King(BLACK);
    board[7][4] = new King(WHITE);
  }
};

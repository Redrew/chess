#pragma once
#include "piece.h"

class Pawn : public Piece {
private:
  int enPassantTurn = 0;

public:
  Pawn(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return PAWN; }
  char getChar() { return 'P'; }
  int getValue() { return 1; }
  void doubleStep(int turn) { enPassantTurn = turn + 1; }
  bool canEnPassant(int turn) { return turn == enPassantTurn; }
};

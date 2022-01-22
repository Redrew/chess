#pragma once
#include "piece.h"

class Rook : public Piece {
public:
  Rook(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return ROOK; }
  char getChar() { return 'R'; }
  int getValue() { return 5; }
};

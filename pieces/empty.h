#pragma once
#include "piece.h"

class Empty : public Piece {
public:
  Empty() : Piece(NOCOLOUR) {}
  PieceTypes getType() { return EMPTY; }
  char getChar() { return ' '; }
  int getValue() { return 0; }
};

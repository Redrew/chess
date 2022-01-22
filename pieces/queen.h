#pragma once
#include "piece.h"

class Queen : public Piece {
public:
  Queen(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return QUEEN; }
  char getChar() { return 'Q'; }
  int getValue() { return 9; }
};

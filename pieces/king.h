#pragma once
#include "piece.h"

class King : public Piece {
public:
  King(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return KING; }
  char getChar() { return 'K'; }
  int getValue() { return 0; }
};

#pragma once
#include "piece.h"

class Knight : public Piece {
public:
  Knight(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return KNIGHT; }
  char getChar() { return 'H'; }
  int getValue() { return 3; }
};

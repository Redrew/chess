#pragma once
#include "piece.h"

class Bishop : public Piece {
public:
  Bishop(Colour colour) : Piece(colour) {}
  PieceTypes getType() { return BISHOP; }
  char getChar() { return 'B'; }
  int getValue() { return 3; }
};

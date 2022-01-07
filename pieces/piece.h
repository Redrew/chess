#pragma once
#include <string>

#include "../types.h"

class Piece {
private:
  Colour colour;

public:
  Piece(Colour colour) : colour(colour) {}
  virtual PieceTypes getType() = 0;
  virtual int getValue() = 0;
  virtual char getChar() = 0;
  Colour getColour() { return colour; }
};

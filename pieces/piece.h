#pragma once
#include <string>

#include "../types.h"

enum PieceTypes { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

enum Colour { WHITE, BLACK };

class Piece {
public:
  std::string name;
  PieceTypes type;
  int value;
  Colour colour;
  Piece(std::string name, PieceTypes type, int value, Colour colour)
      : name(name), type(type), value(value), colour(colour) {}
};

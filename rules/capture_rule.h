#pragma once
#include "../pieces/piece.h"
#include "rule.h"

class CaptureRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    Colour colour = board.getPieceAt(source).getColour();
    Colour targetColour = board.getPieceAt(target).getColour();
    return colour != targetColour;
  }
};

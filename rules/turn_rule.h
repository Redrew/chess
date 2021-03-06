#pragma once
#include "../pieces/piece.h"
#include "rule.h"

class TurnRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    Colour colour = board.getPieceAt(source).getColour();
    return colour == board.turn;
  }
};

#pragma once
#include "rule.h"

class PieceRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    return board.occupied(source);
  }
};

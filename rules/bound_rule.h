#pragma once
#include "rule.h"

class BoundRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    return target.in(board.dimension);
  }
};

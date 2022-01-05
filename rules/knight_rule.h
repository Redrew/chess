#pragma once
#include "rule.h"

class KnightRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    if (board.getPieceAt(source).type != KNIGHT) {
      return true;
    }
    Position delta = target - source;
    return delta.l2() == 5;
  }
};

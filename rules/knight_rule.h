#pragma once
#include "piece_specific_rule.h"

class KnightRule : public PieceSpecificRule {
public:
  KnightRule() : PieceSpecificRule(KNIGHT){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    Position delta = target - source;
    return delta.l2() == 5;
  }
};

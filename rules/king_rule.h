#pragma once
#include "path_rule.h"
#include "piece_specific_rule.h"

class KingRule : public PieceSpecificRule {
private:
  PathRule pathRule = PathRule();

public:
  KingRule() : PieceSpecificRule(KING){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    Position delta = target - source;
    int maxSide = delta.abs().max();
    return (maxSide == 1) && pathRule.checkMove(source, target, board);
  }
};

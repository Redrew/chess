#pragma once
#include "path_rule.h"
#include "piece_specific_rule.h"

class RookRule : public PieceSpecificRule {
private:
  PathRule pathRule = PathRule();

public:
  RookRule() : PieceSpecificRule(ROOK){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    Position delta = target - source;
    int maxSide = delta.abs().max();
    bool alongAxis = delta.l2() == maxSide * maxSide;
    return alongAxis && pathRule.checkMove(source, target, board);
  }
};

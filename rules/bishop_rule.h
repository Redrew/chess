#pragma once
#include "path_rule.h"
#include "piece_specific_rule.h"

class BishopRule : public PieceSpecificRule {
private:
  PathRule pathRule = PathRule();

public:
  BishopRule() : PieceSpecificRule(BISHOP){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    Position absDelta = (target - source).abs();
    bool isDiagonal = absDelta.x == absDelta.y;
    return isDiagonal && pathRule.checkMove(source, target, board);
  }
};

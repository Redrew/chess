#pragma once
#include "path_rule.h"
#include "piece_specific_rule.h"

class QueenRule : public PieceSpecificRule {
private:
  PathRule pathRule = PathRule();

public:
  QueenRule() : PieceSpecificRule(QUEEN){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    return pathRule.checkMove(source, target, board);
  }
};

#pragma once
#include "../pieces/piece.h"
#include "../types.h"
#include "rule.h"

class PieceSpecificRule : public Rule {
private:
  PieceTypes specificType;

public:
  PieceSpecificRule(PieceTypes specificType) : specificType(specificType) {}
  bool checkMove(Position source, Position target, Board &board) {
    if (board.getPieceAt(source).getType() != specificType) {
      return true;
    }
    return checkPieceMove(source, target, board);
  }
  virtual bool checkPieceMove(Position source, Position target,
                              Board &board) = 0;
};

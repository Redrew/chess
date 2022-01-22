#pragma once
#include "path_rule.h"
#include "piece_specific_rule.h"

class PawnRule : public PieceSpecificRule {
private:
  PathRule pathRule = PathRule();
  bool checkCapture(Position &delta) {
    Position absDelta = delta.abs();
    return (absDelta.y == 1 && absDelta.x == 1);
  }
  bool checkNonCapture(Colour colour, Position &source, Position &target,
                       Board &board) {
    Position absDelta = (target - source).abs();
    int notMoved = (colour == BLACK && source.y == 1) ||
                   (colour == WHITE && source.y == 6);
    if (!pathRule.checkMove(source, target, board)) {
      return false;
    }
    return (absDelta.x == 0 && absDelta.y == 1) ||
           (notMoved && isDoubleStep(source, target));
  }

public:
  PawnRule() : PieceSpecificRule(PAWN){};
  bool checkPieceMove(Position source, Position target, Board &board) {
    Position delta = target - source;
    Colour colour = board.getPieceAt(source).getColour();
    bool isCapture = board.isOccupiedAt(target);
    bool up = delta.y < 0;
    if ((colour == BLACK && up) || (colour == WHITE && !up)) {
      return false;
    }
    if (isCapture) {
      return checkCapture(delta);
    } else {
      return checkNonCapture(colour, source, target, board);
    }
    return true;
  }
  bool isDoubleStep(Position source, Position target) {
    Position delta = target - source;
    return delta.x == 0 && delta.abs().y == 2;
  }
  bool isEnPassant(Position source, Position target, Board &board) {
    return false;
  }
};

#pragma once
#include "rule.h"

class PathRule : public Rule {
private:
  bool isStraight(Position &delta) {
    int maxSide = delta.abs().max();
    Position unitDelta = delta / maxSide;
    return delta == unitDelta * maxSide;
  }

public:
  bool checkMove(Position source, Position target, Board &board) {
    Position delta = target - source;
    if (!isStraight(delta)) {
      return false;
    }
    int maxSide = delta.abs().max();
    Position unitDelta = delta / maxSide;
    for (Position position = source + unitDelta; position != target;
         position = position + unitDelta) {
      if (board.isOccupiedAt(position)) {
        return false;
      }
    }
    return true;
  }
};

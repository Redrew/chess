#pragma once
#include "rule.h"

class OccupiedRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    return board.isOccupiedAt(source);
  }
};

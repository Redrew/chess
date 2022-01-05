#pragma once
#include "rule.h"

class MoveRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    return source != target;
  }
};

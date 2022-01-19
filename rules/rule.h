#pragma once

#include <vector>

#include "../boards/board.h"
#include "../types.h"

class Rule {
public:
  virtual bool checkMove(Position source, Position target, Board &board) = 0;
  bool checkSelection(Position source, Board &board) {
    return checkMove(source, Position(0, 0), board);
  }
};

class RuleSet : public Rule {
private:
  std::vector<Rule *> rules;

public:
  RuleSet(std::vector<Rule *> rules) : rules(rules) {}
  bool checkMove(Position source, Position target, Board &board) {
    for (Rule *rule : rules) {
      if (!rule->checkMove(source, target, board)) {
        return false;
      }
    }
    return true;
  }
  bool checkSelection(Position source, Board &board) {
    return checkMove(source, Position(0, 0), board);
  }
};

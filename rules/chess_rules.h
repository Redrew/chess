#include "bound_rule.h"
#include "capture_rule.h"
#include "knight_rule.h"
#include "move_rule.h"
#include "occupied_rule.h"
#include "rule.h"
#include "turn_rule.h"

class ChessRules : public Rule {
public:
  RuleSet rules =
      RuleSet({new TurnRule(), new MoveRule(), new OccupiedRule(),
               new BoundRule(), new CaptureRule(), new KnightRule()});
  bool checkMove(Position source, Position target, Board &board) {
    return rules.checkMove(source, target, board);
  }
};

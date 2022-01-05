#include "bound_rule.h"
#include "colour_rule.h"
#include "knight_rule.h"
#include "move_rule.h"
#include "piece_rule.h"
#include "rule.h"

class ChessRules : public Rule {
public:
  RuleSet rules = RuleSet({new MoveRule(), new PieceRule(), new BoundRule(),
                           new ColourRule(), new KnightRule()});
  bool checkMove(Position source, Position target, Board &board) {
    return rules.checkMove(source, target, board);
  }
};

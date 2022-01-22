#include "bishop_rule.h"
#include "bound_rule.h"
#include "capture_rule.h"
#include "king_rule.h"
#include "knight_rule.h"
#include "move_rule.h"
#include "occupied_rule.h"
#include "pawn_rule.h"
#include "queen_rule.h"
#include "rook_rule.h"
#include "rule.h"
#include "turn_rule.h"

class SelectionRules : public RuleSet {
public:
  SelectionRules()
      : RuleSet({new BoundRule(), new TurnRule(), new OccupiedRule()}) {}
};

class ChessRules : public RuleSet {
public:
  ChessRules()
      : RuleSet({new SelectionRules, new MoveRule(), new CaptureRule(),
                 new PawnRule(), new KnightRule(), new BishopRule(),
                 new RookRule(), new QueenRule(), new KingRule()}) {}
};

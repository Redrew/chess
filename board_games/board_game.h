#include "../boards/board.h"
#include "../rules/rule.h"

class BoardGame {
private:
  Board board;
  Colour player;
  Rule *rule;

public:
  bool canMove(Position position) {
    return board.isOccupiedAt(position) &&
           board.getPieceAt(position).colour == player;
  }
  std::vector<Position> possibleMoves(Position position) {
    for (int x = 0; x < board.dimension[0]; x++) {
      for (int y = 0; y < board.dimension[1]; y++) {
      }
    }
  }
  virtual bool move(Position source, Position target) = 0;
};

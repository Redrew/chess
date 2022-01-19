#pragma once
#include <sstream>

#include "../boards/chess_board.h"
#include "../pieces/empty.h"
#include "../rules/chess_rules.h"
#include "controller.h"

class ChessController : public Controller {
private:
  ChessBoard board;
  ChessRules rules;
  SelectionRules selectionRules;
  Position selectedPosition = {0, 0};
  bool selected = false;

public:
  ChessController(Interface *interface) : Controller(interface){};
  void run() {
    interface->displayBoard(board);
    interface->run();
  }
  void handleClick(Position position) {
    if (selected) {
      attemptMove(selectedPosition, position);
      selected = false;
      interface->displaySubtext("Deselected\n");
    } else if (canSelect(position)) {
      interface->displaySubtext("Selected\n");
      selectedPosition = position;
      selected = true;
    }
    interface->updateDisplay(board);
  };
  bool canSelect(Position &position) {
    return selectionRules.checkSelection(position, board);
  }
  bool attemptMove(Position &source, Position &target) {
    if (rules.checkMove(source, target, board)) {
      move(source, target);
      return true;
    }
    return false;
  }
  void move(Position &source, Position &target) {
    board.movePiece(source, target);
    board.nextTurn();
  }
};

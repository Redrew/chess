#pragma once
#include "../boards/chess_board.h"
#include "controller.h"

class ChessController : public Controller {
private:
  ChessBoard board = ChessBoard();

public:
  ChessController(Interface *interface) : Controller(interface){};
  void run() {
    interface->updateDisplay(board);
    interface->run();
  }
  void handleClick(Position position) { interface->updateDisplay(board); };
};

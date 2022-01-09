#pragma once
#include <vector>

#include "../boards/board.h"
#include "../controller/controller.h"
#include "../types.h"

class Controller;

class Interface {
protected:
  Controller *controller;

public:
  virtual void run() = 0;
  virtual void updateDisplay(Board &board) = 0;
  virtual void highlight(std::vector<Position> &positions) = 0;
  void setController(Controller *controller) { this->controller = controller; }
};

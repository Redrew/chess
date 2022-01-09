#pragma once
#include "../interfaces/interface.h"
#include "../types.h"

class Interface;

class Controller {
protected:
  Interface *interface;

public:
  Controller(Interface *interface) : interface(interface) {
    interface->setController(this);
  }
  virtual void run() = 0;
  virtual void handleClick(Position position) = 0;
};

#pragma once
#include <ncurses.h>
#include <vector>

#include "../types.h"
#include "interface.h"

class TerminalInterface : public Interface {
private:
  WINDOW *win;
  MEVENT event;

public:
  TerminalInterface() {
    win = initscr();
    clear();
    noecho();
    cbreak();
    keypad(win, true);
  }
  ~TerminalInterface() { endwin(); }
  void run() {
    int c;
    while (true) {
      c = wgetch(win);
      switch (c) {
      case KEY_MOUSE:
        if ((getmouse(&event) == OK) && (event.bstate & BUTTON1_PRESSED)) {
          refresh();
        }
        printw("%d %d \n", event.x, event.y);
        refresh();
        break;
      }
    }
  }
  void updateDisplay(Board &board) {
    for (std::vector<Piece *> row : board.getPieces()) {
      for (Piece *piece : row) {
        printw("%c ", piece->getChar());
      }
      addch('\n');
    }
    refresh();
  }
  void highlight(std::vector<Position> &positions) {}
};

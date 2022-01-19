#pragma once
#include <ncurses.h>
#include <string>
#include <vector>

#include "../types.h"
#include "interface.h"

class TerminalInterface : public Interface {
private:
  MEVENT event;
  WINDOW *boardWindow;
  Position boardWindowStart;
  Position boardSize;
  WINDOW *subtextWindow;
  const int SUBTEXT_HEIGHT = 3;

public:
  TerminalInterface() {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, true);
    mousemask(ALL_MOUSE_EVENTS, nullptr);
  }
  ~TerminalInterface() {
    delwin(boardWindow);
    endwin();
  }
  void displayBoard(Board &board) {
    boardSize = getWindowSize(board);
    boardWindowStart = (Position(COLS, LINES) - boardSize) / 2;
    refresh();
    boardWindow = newwin(boardSize.y, boardSize.x, boardWindowStart.y,
                         boardWindowStart.x);
    subtextWindow =
        newwin(SUBTEXT_HEIGHT, boardSize.x, boardWindowStart.y + boardSize.y,
               boardWindowStart.x);
    updateDisplay(board);
  }
  void run() {
    int c;
    while (true) {
      c = wgetch(stdscr);
      switch (c) {
      case KEY_MOUSE:
        if ((getmouse(&event) == OK) && !(event.bstate & BUTTON1_RELEASED) &&
            !(event.bstate & BUTTON2_RELEASED)) {
          Position clickPosition =
              Position(event.x, event.y) - boardWindowStart - Position(1, 1);
          if (isPiecePosition(clickPosition)) {
            Position piecePosition = getPiecePosition(clickPosition);
            controller->handleClick(piecePosition);
          }
        }
        break;
      }
    }
  }
  void updateDisplay(Board &board) {
    werase(boardWindow);
    int columns = board.dimension.x;
    waddch(boardWindow, '\n');
    for (std::vector<Piece *> row : board.getPieces()) {
      waddch(boardWindow, ' ');
      for (int i = 0; i < columns; i++) {
        waddch(boardWindow, row[i]->getChar());
        if (i != columns - 1) {
          waddch(boardWindow, '|');
        }
      }
      waddch(boardWindow, '\n');
    }
    box(boardWindow, 0, 0);
    wrefresh(boardWindow);
  }
  void displaySubtext(std::string text) {
    werase(subtextWindow);
    wprintw(subtextWindow, text.c_str());
    wrefresh(subtextWindow);
  }
  void highlight(std::vector<Position> &positions) {}

private:
  bool isPiecePosition(Position &position) {
    Position piecePosition = getPiecePosition(position);
    return (position.x % 2 == 0) && piecePosition.in(boardSize);
  }
  Position getPiecePosition(Position &position) {
    return position / Position(2, 1);
  }
  Position getWindowSize(Board &board) {
    Position boardSize = board.dimension;
    return Position(boardSize.x * 2 + 1, boardSize.y + 2);
  }
};

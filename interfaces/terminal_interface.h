#pragma once
#include <ncurses.h>
#include <string>
#include <vector>

#include "../types.h"
#include "interface.h"

#define BACKGROUND_COLOUR COLOR_BLUE
#define HIGHLIGHT_COLOUR COLOR_CYAN
#define EMPTY_PAIR 1
#define WHITE_PAIR 2
#define WHITE_HIGHLIGHT_PAIR 3
#define BLACK_PAIR 4
#define BLACK_HIGHLIGHT_PAIR 5

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
    start_color();
    init_pair(EMPTY_PAIR, COLOR_BLACK, BACKGROUND_COLOUR);
    init_pair(WHITE_PAIR, COLOR_WHITE, BACKGROUND_COLOUR);
    init_pair(BLACK_PAIR, COLOR_BLACK, BACKGROUND_COLOUR);
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
        printColouredSquare(boardWindow, *row[i]);
        if (i != columns - 1) {
          printColouredChar(boardWindow, '|', EMPTY_PAIR);
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
  void printColouredSquare(WINDOW *window, Piece &piece) {
    int colour_pair;
    switch (piece.getColour()) {
    case NOCOLOUR:
      colour_pair = EMPTY_PAIR;
      break;
    case WHITE:
      colour_pair = WHITE_PAIR;
      break;
    case BLACK:
      colour_pair = BLACK_PAIR;
      break;
    }
    printColouredChar(window, piece.getChar(), colour_pair);
  }
  void printColouredChar(WINDOW *window, char c, int colour_pair) {
    wattron(window, COLOR_PAIR(colour_pair));
    waddch(window, c);
    wattroff(window, COLOR_PAIR(colour_pair));
  }
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

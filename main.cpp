#include <iostream>

#include "boards/boards.h"
#include "pieces/pieces.h"
#include "rules/chess_rules.h"
#include "types.h"


int main() {
  ChessBoard board = ChessBoard();
  ChessRules chess_rules = ChessRules();
  while (true) {
    int x, y;
    cout << "enter source\n";
    cin >> x >> y;
    Position source = {x, y};
    cout << "enter target\n";
    cin >> x >> y;
    Position target = {x, y};
    cout << chess_rules.checkMove(source, target, board) << "\n";
  }
}

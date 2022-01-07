#include <iostream>

#include "boards/boards.h"
#include "pieces/pieces.h"
#include "rules/chess_rules.h"
#include "interfaces/interfaces.h"
#include "types.h"

using namespace std;

int main() {
  ChessBoard board = ChessBoard();
  ChessRules chess_rules = ChessRules();
  while (true) {
    int x, y;
    cout << "enter source" << endl;
    cin >> x >> y;
    Position source = {x, y};
    cout << "enter target" << endl;
    cin >> x >> y;
    Position target = {x, y};
    cout << chess_rules.checkMove(source, target, board) << "\n";
  }
}

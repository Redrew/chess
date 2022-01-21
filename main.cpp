#include "controller/chess_controller.h"
#include "interfaces/interfaces.h"

using namespace std;

int main() { ChessController(new TerminalInterface()).run(); }

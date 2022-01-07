#pragma once
#include <map>
#include <stdexcept>
#include <vector>

enum PieceTypes { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY };

enum Colour { WHITE, BLACK, NOCOLOUR };

const std::map<PieceTypes, char> PIECE_TO_CHAR = {
    {KING, 'K'},   {QUEEN, 'Q'}, {ROOK, 'R'}, {BISHOP, 'B'},
    {KNIGHT, 'H'}, {PAWN, 'P'},  {EMPTY, ' '}};
const char EMPTY_SQUARE = '-';

class Position {
public:
  int x, y;
  Position(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator==(const Position &other) {
    return x == other.x && y == other.y;
  }
  bool operator!=(const Position &other) { return !(operator==(other)); }
  Position operator+(const Position &other) {
    return Position(x + other.x, y + other.y);
  }
  Position operator-(const Position &other) {
    return Position(x - other.x, y - other.y);
  }
  int operator[](int i) {
    if (i == 0) {
      return x;
    } else if (i == 1) {
      return y;
    } else {
      throw std::out_of_range("only supports index range [0, 1]");
    }
  }
  bool lessThan(Position other) { return x < other.x && y < other.y; }
  bool in(Position other) { return x >= 0 && y >= 0 && lessThan(other); }
  int l2() { return x * x + y * y; }
};

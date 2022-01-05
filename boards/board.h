#pragma once

#include <vector>

#include "../pieces/piece.h"
#include "../types.h"

using namespace std;

class Board {
public:
  Piece *EMPTY = nullptr;
  Position dimension;
  vector<vector<Piece *>> board;
  Board(Position dimension) : dimension(dimension) {
    for (int h = 0; h < dimension[0]; h++) {
      vector<Piece *> row;
      for (int w = 0; w < dimension[1]; w++) {
        row.push_back(EMPTY);
      }
      board.push_back(row);
    }
  }
  Piece &getPieceAt(Position position) {
    return *board[position[0]][position[1]];
  }
  bool occupied(Position position) {
    return board[position[0]][position[1]] != EMPTY;
  }
};

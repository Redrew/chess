#pragma once

#include <vector>

#include "../pieces/empty.h"
#include "../pieces/piece.h"
#include "../types.h"

class Board {
protected:
  std::vector<std::vector<Piece *>> board;

public:
  Position dimension;
  Colour turn = WHITE;
  Board(Position dimension) : dimension(dimension) {
    for (int h = 0; h < dimension[0]; h++) {
      std::vector<Piece *> row;
      for (int w = 0; w < dimension[1]; w++) {
        row.push_back(new Empty());
      }
      board.push_back(row);
    }
  }
  Piece &getPieceAt(Position position) {
    return *board[position[0]][position[1]];
  }
  bool occupied(Position position) {
    return getPieceAt(position).getType() != EMPTY;
  }
  std::vector<std::vector<Piece *>> getPieces() { return board; }
};

#pragma once

#include <vector>

#include "../pieces/empty.h"
#include "../pieces/piece.h"
#include "../types.h"

class Board {
protected:
  std::vector<std::vector<Piece *>> board;

public:
  Empty *const EMPTY_PIECE = new Empty();
  Position dimension;
  Colour turn = WHITE;
  Board(Position dimension) : dimension(dimension) {
    for (int h = 0; h < dimension[0]; h++) {
      std::vector<Piece *> row;
      for (int w = 0; w < dimension[1]; w++) {
        row.push_back(EMPTY_PIECE);
      }
      board.push_back(row);
    }
  }
  Piece &getPieceAt(Position &position) {
    return *board[position[0]][position[1]];
  }
  void movePiece(Position &source, Position &target) {
    Piece *sourcePiece = &getPieceAt(source);
    Piece *targetPiece = &getPieceAt(target);
    if (targetPiece != EMPTY_PIECE) {
      free(targetPiece);
    }
    placePieceAt(target, sourcePiece);
    placePieceAt(source, EMPTY_PIECE);
  }
  void placePieceAt(Position &position, Piece *piece) {
    board[position[0]][position[1]] = piece;
  }
  bool isOccupiedAt(Position &position) {
    return getPieceAt(position).getType() != EMPTY;
  }
  void nextTurn() {
    if (turn == WHITE) {
      turn = BLACK;
    } else {
      turn = WHITE;
    }
  }
  std::vector<std::vector<Piece *>> getPieces() { return board; }
};

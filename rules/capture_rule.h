#pragma once
#include "../pieces/piece.h"
#include "rule.h"

class CaptureRule : public Rule {
public:
  bool checkMove(Position source, Position target, Board &board) {
    Colour colour = board.getPieceAt(source).colour;
    bool targetOccupied = board.occupied(target);
    if (targetOccupied) {
      Piece targetPiece = board.getPieceAt(target);
      if (targetPiece.colour == colour) {
        return false;
      }
    }
    return true;
  }
};

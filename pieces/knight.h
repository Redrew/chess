#include "piece.h"

class Knight : public Piece {
public:
  Knight(Colour colour) : Piece("Knight", KNIGHT, 3, colour) {}
};

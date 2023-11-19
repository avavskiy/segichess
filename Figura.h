#ifndef FIGURA_H
#define FIGURA_H

#include "Piece.h"

class Figura {
public:
    King king;
    Bishop bishop;
    Gold gold;
    Lance lance;
    Rook rook;
    Pawn pawn;
    Horse horse;
    Silver silver;

    Figura();
};

#endif // FIGURA_H

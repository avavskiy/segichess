#include "Piece.h"

Piece::Piece(const std::string& n) : name(n) {}

King::King() : Piece("GEN") {}
Bishop::Bishop() : Piece("BSP") {}
Gold::Gold() : Piece("GOD") {}
Lance::Lance() : Piece("LNC") {}
Rook::Rook() : Piece("ROK") {}
Silver::Silver() : Piece("SLV") {}
Horse::Horse() : Piece("HRS") {}
Pawn::Pawn() : Piece("PWN") {}

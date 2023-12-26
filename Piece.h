#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
public:
    std::string name;
    Piece(const std::string& n);
};
/* Принципиального отличия наследников от родителя нет. Никакого
 * уникального поведения. Все эти классы могут быть представлены просто
 * экземплярами Piece с конкретными названиями. Такое наследование нам не
 * нужно. */
class King : public Piece {
public:
    King();
};

class Bishop : public Piece {
public:
    Bishop();
};

class Gold : public Piece {
public:
    Gold();
};

class Lance : public Piece {
public:
    Lance();
};

class Rook : public Piece {
public:
    Rook();
};

class Silver : public Piece {
public:
    Silver();
};

class Horse : public Piece {
public:
    Horse();
};

class Pawn : public Piece {
public:
    Pawn();
};

#endif // PIECE_H

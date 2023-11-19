#include "Doska.h"
#include "Figura.h"
#include <iostream>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

std::string buff;
bool flag_buff;
std::string doska[10][10];
bool doska_b[10][10];
int sum_hod;

void doska_print() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    char num = 'a';
    std::cout << "|Выход 'Ctrl+Z'|" << std::endl;
    std::cout << "\t\t\t   Консольные шахматы-сёги" << std::endl
              << "\t\t\t   Пример хода:e2 e4" << std::endl;
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << "\t\t\t" << 9 - i;
        for (int j = 0; j < 9; j++) {
            std::cout << doska[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "\t\t\t";
    for (int i = 0; i < 9; i++) {
        std::cout << "    " << num;
        ++num;
    }
    if (sum_hod % 2 == 0 & sum_hod > 0 | sum_hod == 1) {
        std::cout << std::endl << "Ход черных: ";
    } else {
        std::cout << std::endl << "Ход  белых: ";
    }
}

void doska_default() {
    Figura f;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            doska[i][j] = "|___|";
            doska_b[i][j] = 0;
        }
    }

    for (int i = 0; i < 9; i++) {
        doska[2][i] = "|" + std::string(ANSI_COLOR_RED) + f.pawn.name + ANSI_COLOR_RESET + "|";
        doska_b[2][i] = 1;
        doska[6][i] = "|" + f.pawn.name + ANSI_COLOR_RESET + "|";
        doska_b[6][i] = 1;
    }

    doska[0][0] = doska[0][8] = "|" + std::string(ANSI_COLOR_RED) + f.lance.name + ANSI_COLOR_RESET + "|";
    doska_b[0][0] = doska_b[0][8] = 1;
    doska[8][0] = doska[8][8] = "|" + f.lance.name + ANSI_COLOR_RESET + "|";
    doska_b[8][0] = doska_b[8][8] = 1;

    doska[0][1] = doska[0][7] = "|" + std::string(ANSI_COLOR_RED) + f.horse.name + ANSI_COLOR_RESET + "|";
    doska_b[0][1] = doska_b[0][7] = 1;
    doska[8][1] = doska[8][7] = "|" + f.horse.name + ANSI_COLOR_RESET + "|";
    doska_b[8][1] = doska_b[8][7] = 1;

    doska[0][2] = doska[0][6] = "|" + std::string(ANSI_COLOR_RED) + f.silver.name + ANSI_COLOR_RESET + "|";
    doska_b[0][2] = doska_b[0][6] = 1;
    doska[8][2] = doska[8][6] = "|" + f.silver.name + ANSI_COLOR_RESET + "|";
    doska_b[8][2] = doska_b[8][6] = 1;

    doska[0][3] = doska[0][5] = "|" + std::string(ANSI_COLOR_RED) + f.gold.name + ANSI_COLOR_RESET + "|";
    doska_b[0][3] = doska_b[0][5] = 1;
    doska[8][3] = doska[8][5] = "|" + f.gold.name + ANSI_COLOR_RESET + "|";
    doska_b[8][3] = doska_b[8][5] = 1;

    doska[8][4] = "|" + f.king.name + ANSI_COLOR_RESET + "|";
    doska_b[8][4] = 1;

    doska[1][7] = "|" + std::string(ANSI_COLOR_RED) + f.bishop.name + ANSI_COLOR_RESET + "|";
    doska_b[1][7] = 1;

    doska[7][1] = "|" + f.bishop.name + ANSI_COLOR_RESET + "|";
    doska_b[7][1] = 1;

    doska[1][1] = "|" + std::string(ANSI_COLOR_RED) + f.rook.name + ANSI_COLOR_RESET + "|";
    doska_b[1][1] = 1;

    doska[7][7] = "|" + f.rook.name + ANSI_COLOR_RESET + "|";
    doska_b[7][7] = 1;

    doska[0][4] = "|" + std::string(ANSI_COLOR_RED) + f.king.name + ANSI_COLOR_RESET + "|";
    doska_b[0][4] = 1;
    doska_print();
}

void doska_hod(int x, int y) {
    if (doska_b[9 - y][x - 'a'] == 1) {
        if (flag_buff) {
            doska[9 - y][x - 'a'] = "|___|";
            doska[9 - y][x - 'a'] = buff;
            doska_b[9 - y][x - 'a'] = 1;
            buff = "";
            flag_buff = false;
        } else {
            buff = doska[9 - y][x - 'a'];
            doska[9 - y][x - 'a'] = "|___|";
            doska_b[9 - y][x - 'a'] = 0;
            flag_buff = true;
        }
    } else {
        doska[9 - y][x - 'a'] = buff;
        doska_b[9 - y][x - 'a'] = 1;
        buff = "";
        flag_buff = false;
    }
    doska_print();
    ++sum_hod;
}

#include<iostream>
#include <string>
#include <limits>
#include "Doska.h"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    setlocale(0, "Russian");
    doska_default();
    char stb = 0;
    int str = 0;

    while (true) {
        if (std::cin >> stb >> str) {
            if ((isalpha(stb) && isdigit(str)) || (isalpha(stb) && stb >= 'a' && stb <= 'i' && str >= 1 && str <= 9)) {
                doska_hod(stb, str);
            } else {
                std::cout << "Ошибка ввода!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Ошибка ввода!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
    
    return 0;
}
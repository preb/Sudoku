#include <iostream>
#include "Sudoku.h"

int main() {
    Sudoku s;
    std::cin >> s;
    if (s.solve())
        std::cout << s;
    else
        std::cout << "Could not solve Sudoku.\n";
    return 0;
}

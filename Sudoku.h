#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>

class Sudoku {
private:
    int grid[9][9];
    bool alreadyInRow(int, int);
    bool alreadyInColumn(int, int);
    bool alreadyInBox(int, int, int);
    bool viable(int, int, int);
    bool findNextEmptyCell(int&, int&);
public:
    bool solve();
    friend std::istream& operator>>(std::istream&, Sudoku&);
    friend std::ostream& operator<<(std::ostream&, const Sudoku&);
};
#endif

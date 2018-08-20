#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>

class Sudoku {
private:
    int row_size, col_size, box_size;
    int **grid;
    bool alreadyInRow(int, int) const;
    bool alreadyInCol(int, int) const;
    bool alreadyInBox(int, int, int) const;
    bool viable(int, int, int) const;
    bool findNextEmptyCell(int&, int&) const;
public:
    Sudoku(int, int, int);
    ~Sudoku();
    bool solve();
    friend std::istream& operator>>(std::istream&, Sudoku&);
    friend std::ostream& operator<<(std::ostream&, const Sudoku&);
};
#endif

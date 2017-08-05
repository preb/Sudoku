#include <iostream>

// Is used for grid size. Size will be NxN
#define SIZE 9

class Sudoku {
private:
    int grid[SIZE][SIZE];
    bool alreadyInRow(int, int);
    bool alreadyInColumn(int, int);
    bool alreadyInBox(int, int, int);
    bool viable(int, int, int);
public:
    friend std::istream& operator>>(std::istream&, Sudoku&);
    friend std::ostream& operator<<(std::ostream&, const Sudoku&);
};

bool Sudoku::alreadyInRow(int number, int row) {
    for (int column {0}; column < SIZE; ++column)
        if (grid[row][column] == number)
            return true;
    return false;
}

bool Sudoku::alreadyInColumn(int number, int column) {
    for (int row {0}; row < SIZE; ++row)
        if (grid[row][column] == number)
            return true;
    return false;
}

bool Sudoku::alreadyInBox(int number, int boxRowStart, int boxColumnStart) {
    for (int row {0}; row < 3; ++row)
        for (int column {0}; column < 3; ++column)
            if (grid[row + boxRowStart][column + boxColumnStart] == number)
                return true;
    return false;
}

bool Sudoku::viable(int number, int row, int column) {
    return !alreadyInRow(number, row) &&
           !alreadyInColumn(number, column) &&
           !alreadyInBox(number, row - row % 3, column - column % 3);
}

std::istream& operator>>(std::istream &in, Sudoku &sudoku) {
    for (int row {0}; row < SIZE; ++row)
        for (int column {0}; column < SIZE; ++column)
            in >> sudoku.grid[row][column];
    return in;
}

std::ostream& operator<<(std::ostream &out, const Sudoku &sudoku) {
    for (int row {0}; row < SIZE; ++row)
        for (int column {0}; column < SIZE; ++column)
            out << sudoku.grid[row][column];
    return out;
}

int main() {
    Sudoku s;
    return 0;
}

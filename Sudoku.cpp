#include "Sudoku.h"

// Check if a row already contains a certain number.
bool Sudoku::alreadyInRow(int number, int row) {
    for (int column {0}; column < 9; ++column)
        if (grid[row][column] == number)
            return true;
    return false;
}

// Check if a column already contains a certain number.
bool Sudoku::alreadyInColumn(int number, int column) {
    for (int row {0}; row < 9; ++row)
        if (grid[row][column] == number)
            return true;
    return false;
}

// Check if a 3x3 box inside our 9x9 grid already contains a certain number.
bool Sudoku::alreadyInBox(int number, int boxRowStart, int boxColumnStart) {
    for (int row {0}; row < 3; ++row)
        for (int column {0}; column < 3; ++column)
            if (grid[row + boxRowStart][column + boxColumnStart] == number)
                return true;
    return false;
}

// Check if a number can be placed at position grid[row][column].
bool Sudoku::viable(int number, int row, int column) {
    return !alreadyInRow(number, row) &&
           !alreadyInColumn(number, column) &&
           !alreadyInBox(number, row - row % 3, column - column % 3);
}

// Find next empty cell. If there are no empty cells we solved
// the Sudoku and return false. The next empty cell will be saved for our
// caller because row and column parameters are references.
bool Sudoku::findNextEmptyCell(int &row, int &column) {
    for (row = 0; row < 9; ++row)
        for (column = 0; column < 9; ++column)
            if (grid[row][column] == 0)
                return true;
    return false;
}

bool Sudoku::solve() {
    int row, column;
    
    // If there are no empty cells we solved the sudoku.
    // If we can find an empty cell the positon will be
    // saved in the row and column variables.
    if (!findNextEmptyCell(row, column))
        return true;

    for (int number {1}; number <= 9; ++number) {
        // Place a number from 1 to 9 into the empty cell
        // if it is viable.
        if (viable(number, row, column)) {
                grid[row][column] = number;
            // Check next empty cell. If it returns true it means all
            // other empty cells have been filled and we solved the Sudoku.
            if (solve())
                return true;
            // If it returns false it means that there must be a mistake in
            // the current cell or a previous cell. So we need to empty the
            // current cell again and try with a higher number.
            grid[row][column] = 0;
        }
    }
    // If we try all numbers from 1 to 9 for the current empty cell and none
    // lead to a solved sudoku, we need to go back and try different numbers
    // for previous empty cells.
    return false;
}

std::istream& operator>>(std::istream &in, Sudoku &sudoku) {
    for (int row {0}; row < 9; ++row)
        for (int column {0}; column < 9; ++column)
            in >> sudoku.grid[row][column];
    return in;
}

std::ostream& operator<<(std::ostream &out, const Sudoku &sudoku) {
    for (int row {0}; row < 9; ++row) {
        for (int column {0}; column < 9; ++column)
            out << sudoku.grid[row][column] << ' ';
        out << '\n';
    }
    return out;
}

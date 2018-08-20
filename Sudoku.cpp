#include <stdexcept>
#include "Sudoku.hpp"

// Check if a row already contains a certain number.
bool Sudoku::alreadyInRow(int num, int row) const {
    for (int col = 0; col < 9; ++col)
        if (grid[row][col] == num) return true;
    return false;
}

// Check if a column already contains a certain number.
bool Sudoku::alreadyInCol(int num, int col) const {
    for (int row = 0; row < 9; ++row)
        if (grid[row][col] == num) return true;
    return false;
}

// Check if a 3x3 box inside our 9x9 grid already contains a certain number.
bool Sudoku::alreadyInBox(int num, int rowStart, int colStart) const {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col)
            if (grid[rowStart + row][colStart + col] == num) return true;
    }
    return false;
}

// Check if a number can be placed at position grid[row][col].
bool Sudoku::viable(int num, int row, int col) const {
    return !alreadyInRow(num, row) &&
           !alreadyInCol(num, col) &&
           !alreadyInBox(num, row - row % 3, col - col % 3);
}

// Find next empty cell. If there are no empty cells we solved
// the Sudoku and return false. The next empty cell will be saved for our
// caller because row and column parameters are references.
bool Sudoku::findNextEmptyCell(int &row, int &col) const {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col)
            if (grid[row][col] == 0) return true;
    }
    return false;
}

bool Sudoku::solve() {
    int row = 0, col = 0;
    
    // If there are no empty cells we solved the sudoku.
    // If we can find an empty cell the positon will be
    // saved in the row and column variables.
    if (!findNextEmptyCell(row, col))
        return true;

    for (int num = 1; num <= 9; ++num) {
        // Place a number from 1 to 9 into the empty cell
        // if it is viable.
        if (viable(num, row, col)) {
            grid[row][col] = num;
            // Check next empty cell. If it returns true it means all
            // other empty cells have been filled and we solved the Sudoku.
            if (solve()) return true;
            // If it returns false it means that there must be a mistake in
            // the current cell or a previous cell. So we need to empty the
            // current cell again and try with a higher number.
            grid[row][col] = 0;
        }
    }
    // If we try all numbers from 1 to 9 for the current empty cell and none
    // lead to a solved sudoku, we need to backtrack.
    return false;
}

std::istream& operator>>(std::istream &in, Sudoku &sudoku) {
    for (int row {0}; row < 9; ++row) {
        for (int col {0}; col < 9; ++col) {
            int num;
            std::cin >> num;
            if (std::cin.fail() or num < 0 or num > 9)
                throw std::runtime_error("Could not read Sudoku puzzle.");
            sudoku.grid[row][col] = num;
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream &out, const Sudoku &sudoku) {
    for (int row {0}; row < 9; ++row) {
        for (int col {0}; col < 9; ++col)
            out << sudoku.grid[row][col] << ' ';
        out << '\n';
    }
    return out;
}


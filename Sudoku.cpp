#include <cmath>
#include <stdexcept>
#include "Sudoku.hpp"

// Check if a row already contains a certain number.
bool Sudoku::alreadyInRow(int num, int row) const {
    for (int col = 0; col < grid_size; ++col)
        if (grid[row][col] == num) return true;
    return false;
}

// Check if a column already contains a certain number.
bool Sudoku::alreadyInCol(int num, int col) const {
    for (int row = 0; row < grid_size; ++row)
        if (grid[row][col] == num) return true;
    return false;
}

// Check if a 3x3 box inside our 9x9 grid already contains a certain number.
bool Sudoku::alreadyInBox(int num, int rowStart, int colStart) const {
    for (int row = 0; row < box_size; ++row) {
        for (int col = 0; col < box_size; ++col)
            if (grid[rowStart + row][colStart + col] == num) return true;
    }
    return false;
}

// Check if a number can be placed at position grid[row][col].
bool Sudoku::viable(int num, int row, int col) const {
    return !alreadyInRow(num, row) &&
           !alreadyInCol(num, col) &&
           !alreadyInBox(num, row - row % box_size, col - col % box_size);
}

// Find next empty cell. If there are no empty cells we solved
// the Sudoku and return false. The next empty cell will be saved for our
// caller because row and column parameters are references.
bool Sudoku::findNextEmptyCell(int &row, int &col) const {
    for (row = 0; row < grid_size; ++row) {
        for (col = 0; col < grid_size; ++col)
            if (grid[row][col] == 0) return true;
    }
    return false;
}

Sudoku::Sudoku(int size) : grid_size {size} {
    box_size = std::sqrt(grid_size);
    if (box_size * box_size != grid_size)
        throw std::runtime_error("Invalid Sudoku size.");

    grid = new int*[grid_size];
    for (int row = 0; row < grid_size; ++row) {
        grid[row] = new int[grid_size];
        for (int col = 0; col < grid_size; ++col)
            grid[row][col] = 0;
    }
}

Sudoku::~Sudoku() {
    for (int row = 0; row < grid_size; ++row)
        delete[] grid[row];
    delete[] grid;
}

bool Sudoku::solve() {
    int row = 0, col = 0;
    
    // If there are no empty cells we solved the sudoku.
    // If we can find an empty cell the positon will be
    // saved in the row and column variables.
    if (!findNextEmptyCell(row, col))
        return true;

    for (int num = 1; num <= grid_size; ++num) {
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
    int num;
    for (int row = 0; row < sudoku.grid_size; ++row) {
        for (int col = 0; col < sudoku.grid_size; ++col) {
            std::cin >> num;
            if (std::cin.fail() or num < 0 or num > sudoku.grid_size)
                throw std::runtime_error("Could not read Sudoku puzzle.");
            sudoku.grid[row][col] = num;
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream &out, const Sudoku &sudoku) {
    for (int row = 0; row < sudoku.grid_size; ++row) {
        for (int col = 0; col < sudoku.grid_size; ++col)
            out << sudoku.grid[row][col] << ' ';
        out << '\n';
    }
    return out;
}


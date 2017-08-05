#include <iostream>

// Is used for grid size. Size will be NxN
#define SIZE 9

class Sudoku {
private:
    int grid[SIZE][SIZE];
public:
    void solve() {};
    friend std::istream& operator>>(std::istream&, Sudoku&);
    friend std::ostream& operator<<(std::ostream&, const Sudoku&);
};

std::istream& operator>>(std::istream &in, Sudoku &s) {
    for (int i {0}; i < SIZE; ++i)
        for (int j {0}; j < SIZE; ++j)
            in >> s.grid[i][j];
    return in;
}

std::ostream& operator<<(std::ostream &out, const Sudoku &s) {
    for (int i {0}; i < SIZE; ++i)
        for (int j {0}; j < SIZE; ++j)
            out << s.grid[i][j];
    return out;
}

int main() {
    Sudoku s;
    std::cin >> s;
    std::cout << s;
    return 0;
}

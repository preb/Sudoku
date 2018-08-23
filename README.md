## Simple Sudoku solver

The class constructor takes as parameter the size of the Sudoku puzzle. 
For a 9x9 puzzle size would be 9.

It then takes a string of numbers seperated by whitespace. Empty cells are denoted by the number 0.

Returns true if it could solve the Sudoku, false otherwise.

Usage:

```c++
#include <iostream>
#include "Sudoku.hpp"

int main() {
    int size;
    std::cin >> size;

    Sudoku s(size);
    std::cin >> s;

    if (s.solve())
        std::cout << s << std::endl;
    else
        std::cout << "Could not solve Sudoku!" << std::endl;
}
```

Input could look like this:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```


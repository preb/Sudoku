## Simple Sudoku solver

Takes a string of numbers seperated by whitespace. Empty cells are
denoted by the number 0.
Throws `std::runtime_error` if it cannot read the Sudoku grid.

Outputs solved Sudoku or error message if not solvable.

Input should look like this:

```
5 3 0 0 7 0 0 0 0<br>
6 0 0 1 9 5 0 0 0<br>
0 9 8 0 0 0 0 6 0<br>
8 0 0 0 6 0 0 0 3<br>
4 0 0 8 0 3 0 0 1<br>
7 0 0 0 2 0 0 0 6<br>
0 6 0 0 0 0 2 8 0<br>
0 0 0 4 1 9 0 0 5<br>
0 0 0 0 8 0 0 7 9<br>
```


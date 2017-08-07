# Simple Sudoku solver

Takes in a string of numbers with empty cells of the Sudoku grid denoted as 0.

Outputs solved Sudoku, or error message if not solvable, to stdout.

#### This might look like this

stdin:

530070000600195000098000060800060003400803001700020006060000280000419005000080079

std::out:

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 


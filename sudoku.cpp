/*
*   Backtracking method for
*   solving sudoku, how backtracking works?
*   https://en.wikipedia.org/wiki/Sudoku_solving_algorithms
*/

#include<iostream>
#include"functions.hpp"

int main()
{

    GRID::grid sudoku;
    char answer = 'n';

    std::cout << "Hai un sudoku da risolvere [s|n] : ";
    std::cin >> answer;

    if (answer == 's')
    {
        sudoku.importGrid();

        // controlli //
        sudoku.backtracking();

        // immetere valori //

        // mostrare la soluzione //
        sudoku.printGrid();

    }
    return 0;
}
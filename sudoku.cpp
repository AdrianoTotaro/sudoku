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
    (answer == 's') ? sudoku.importGrid() : sudoku.importFromFile("sudoku.txt");
    
    std::cout << sudoku;

    sudoku.callBacktracking();

    std::cout << sudoku;

    return 0;
}

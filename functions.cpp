#include<iostream>
#include"functions.hpp"

GRID::grid::grid(){

    int i, j;

    //magari aggiungere un sudoku default da file //

    for (i = 0; i < 9; i++)
        for ( j = 0; j < 9; j++)
            cellValue[i][j] = 0;
}

void GRID::grid::importGrid(){

    std::string sudokuMap;
    int i, j, k = 0;

    std::cout << "Inserisci il sudoku da risolvere [0 se la casella e` vuota] : " << std::endl;
    std::cin >> sudokuMap;

    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            cellValue[i][j] = sudokuMap[k];
            k++;
        }
    }
    


}
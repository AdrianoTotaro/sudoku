#include<iostream>
#include"functions.hpp"

GRID::grid::grid(){

    int i, j;

    //magari aggiungere un sudoku default da file //

    for (i = 0; i < 9; i++)
        for ( j = 0; j < 9; j++)
            cellValue[i][j].value = 0;
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
            cellValue[i][j].value = sudokuMap[k];
            k++;

            if(cellValue[i][j].value != 0)
                cellValue[i][j].userValue = 1;
        }
    }
    


}

int GRID::grid::backtracking()
{
    int i, j, k;
    int breakpoint[2];
    cell *cellPointer;
    bool atLeastOneValid;

    for(i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            cellPointer = &cellValue[i][j];

            if(cellPointer->value == 0)
            {
                atLeastOneValid = true;

                for(k = 1; k <= 9; k++)
                {
                    cellPointer->value = k;

                    if (orizzControll(cellPointer) && squareControll(cellPointer) && verticalControll(cellPointer))
                        break;
                    else if(k == 9)
                        atLeastOneValid = false;
                    
                }
            }

        }
        
    }
}
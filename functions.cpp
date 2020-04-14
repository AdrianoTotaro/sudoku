#include<iostream>
#include<fstream>
#include"functions.hpp"


//=========Inizializza tutte le celle a 0============//
GRID::grid::grid(){

    int i, j;

    //magari aggiungere un sudoku default da file //

    for (i = 0; i < 9; i++)
        for ( j = 0; j < 9; j++)
            cellValue[i][j].value = 0;
}


//=================Fa inserire il sudoku all'utente=============//
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

//============Importa il sudoku da un file==================//
void GRID::grid::importFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    int i, j, k = 0, q;

    for(i = 0; i < 9; i++)
    {
        getline(file, line);

        

    }
}


void GRID::grid::backtracking()
{
    int i, j, k;
    int breakpoint[2];
    cell *cellPointer, *prevCellPointer;
    bool atLeastOneValid;

    for(i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            cellPointer = &cellValue[i][j];

            // cerca un numero valido aumentando sempre di uno e facendo controlli //

            if(cellPointer->userValue == 0)
            {
                while (cellPointer->value <= 9)
                {
                    atLeastOneValid = false;
                    if(controlls(i, j) && cellPointer->value != 0)
                    {
                        atLeastOneValid = true;
                        break;
                    }

                    cellPointer->value ++;
                }

                // se non trova nessun numero valido cancella ogni numero dalla casella e torna indietro  aumentando di 1//
                // probabilmente posso togliere il controllo dato che se trova un numero valido esegue il break          //
                if(atLeastOneValid == false)
                {
                    cellPointer->value = 0;
                    prevCellPointer->value++;
                    backtracking();
                }
                
                prevCellPointer = cellPointer;
            }

            

        }
        
    }
}

bool GRID::grid::orizzControll(int x, int y)
{
    int i = x, j;
    bool validValue = true;

    for(j = 1; j<9; j++)
    {
        if(j != y)
        {
            if(cellValue[x][j].value == cellValue[x][y].value)
            {
                validValue = false;
                break;
            }
        }
    }

    return validValue;

}

bool GRID::grid::verticalControll(int x, int y)
{
    int i = x, j;
    bool validValue = true;

    for(j = 1; j<9; j++)
    {
        if(j != x)
        {
            if(cellValue[j][y].value == cellValue[x][y].value)
            {
                validValue = false;
                break;
            }
        }
    }

    return validValue;

}

bool GRID::grid::squareControll(int x, int y)
{
    int xCentral, yCentral;
    int i, j;
    bool validValue = true;

    if(x >= 0 && x<=2)
        xCentral = 2;
    else if(x>=3 && x<=5)
        xCentral = 4;
    else if(x>=6 && x<=8)
        xCentral = 7;

    if(y >= 0 && y<=2)
        yCentral = 2;
    else if(y>=3 && y<=5)
        yCentral = 4;
    else if(y>=6 && y<=8)
        yCentral = 7;

    for(i = xCentral-1; i<=xCentral+1; i++)
    {
        for(j = yCentral-1; j<=yCentral+1; j++)
        {
            if(i != x && j!=y)
            {
                if(cellValue[i][j].value == cellValue[x][y].value)
                {
                    validValue = false;
                    break;
                }
            }
        }
    }

    return validValue;
}

bool GRID::grid::controlls(int x, int j)
{
    return (verticalControll(x, j) && orizzControll(x, j) && squareControll(x, j)) ? true:false;
}


void GRID::grid::printGrid()
{
    int i, j;

    std::cout << std::endl;
    std::cout << std::endl;
    
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            std::cout << cellValue[i][j].value;
        }
        std::cout << std::endl;        
    }    
}
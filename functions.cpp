#include<iostream>
#include<fstream>
#include"functions.hpp"
#include<vector>
#include<list>
#include<exception>

//=========Inizializza tutte le celle a 0============//
GRID::grid::grid(){

    int i, j;

    for (i = 0; i < 9; i++)
        for ( j = 0; j < 9; j++)
            cellValue[i][j]= 0;
}

GRID::Coordinate::Coordinate()
{
    coord.first = 0;
    coord.second = 0;
}

GRID::Coordinate::Coordinate(int x, int y)
{
    coord.first = x;
    coord.second = y;
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
            GRID::Coordinate coord(j, i);
            
            cellValue[i][j] = sudokuMap[k] - '0';
            k++;
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
        for(j = 0; j < 9; j++)
            cellValue[i][j] = line[j] - '0';
    }
    file.close();
}

void GRID::grid::callBacktracking()
{
    backtracking(GRID::Coordinate (0,0));
}

/* 
    return true se deve contrinuare a fare backtracking
    false se ha completato  */
bool GRID::grid::backtracking(GRID::Coordinate coord)
{
    std::vector<int> possValues = valoriPossibili(coord);
    bool continueBacktracking = possValues.size() <= 0;
    int originalValue = returnValue(coord);

    if(originalValue <= 0)      // se uguale a 0 risolve senno va avanti
    {
        for(const int value:possValues)
        {
            cambiaValore(coord , value);
            continueBacktracking = backtracking(++coord);

            if(continueBacktracking)
                cambiaValore(coord, originalValue);
            else
                break;
        }

        if(returnValue(coord) >= 1)
            continueBacktracking = false;
        
        return continueBacktracking;
    }
    else if(coord.fineGriglia())
        return continueBacktracking;
    else
        return backtracking(++coord);
}

/**
 * CONTROLLO ORIZZONTALE
 * */

bool GRID::grid::orizzControll(int x, int y)
{
    int i = x, j;
    bool validValue = true;

    for(j = 0; j<9; j++)
    {
        if(j != y)
        {
            if(cellValue[x][j] == cellValue[x][y])
            {
                validValue = false;
                break;
            }
        }
    }

    return validValue;
}

/**
 * CONTROLLO VERTICALE
 */
bool GRID::grid::verticalControll(int x, int y)
{
    int i = x, j;
    bool validValue = true;

    for(j = 0; j<9; j++)
    {
        if(j != x)
        {
            if(cellValue[j][y] == cellValue[x][y])
            {
                validValue = false;
                break;
            }
        }
    }

    return validValue;
}

/**
 * CONTROLLO NEL QUADRATO
 */
bool GRID::grid::squareControll(int x, int y)
{
    int xCentral, yCentral;
    int i, j;
    bool validValue = true;

    if(x >= 0 && x<=2)
        xCentral = 1;
    else if(x>=3 && x<=5)
        xCentral = 4;
    else if(x>=6 && x<=8)
        xCentral = 7;

    if(y >= 0 && y<=2)
        yCentral = 1;
    else if(y>=3 && y<=5)
        yCentral = 4;
    else if(y>=6 && y<=8)
        yCentral = 7;

    for(i = xCentral-1; i<=xCentral+1 && validValue == true; i++)
    {
        for(j = yCentral-1; j<=yCentral+1 && validValue == true; j++)
        {
	
            if(i != x || j!=y)
            {
                if(cellValue[i][j] == cellValue[x][y])
                {
                    validValue = false;
                }
            }
        }
    }

    return validValue;
}

inline bool GRID::grid::controlls(int x, int y, int testValue)
{
    bool result = false;
    int value = cellValue[x][y];

    cellValue[x][y] = testValue;
    (verticalControll(x, y) && orizzControll(x,y) && squareControll(x,y)) ? result = true :result = false;
    cellValue[x][y]= value;

    return result;
}

std::vector<int> GRID::grid::valoriPossibili(Coordinate coord)
{
    std::list<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> result;
    
    for(auto &temp:arr)
    {

        if(controlls(coord.x(), coord.y(), temp))
        {
            result.push_back(temp);
        }
    }

    /* for(const auto &x:result)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl; */

    return result;
}

GRID::Coordinate GRID::Coordinate::operator++()
{
    int x = coord.first;
    int y = coord.second;
     
    if(x == 8)  {  x = 0;  y++; }
    else if(x == 8 && y == 8)   { std::cout << "ci e` stato un problema" << std::endl;    throw 1; }
    else
        x++;
        
    return GRID::Coordinate(x, y);
}


inline int GRID::Coordinate::x() {return coord.first;}
inline int GRID::Coordinate::y() {return coord.second;}
inline bool GRID::Coordinate::fineGriglia() {return (coord.first == 8 && coord.second == 8);}
std::ostream& GRID::operator<<(std::ostream& os, const Coordinate& coor)
{
    return os << "x : " << coor.coord.first << " y : " << coor.coord.second << std::endl;
}


inline int GRID::grid::returnValue(Coordinate coord)  { return cellValue[coord.x()][coord.y()]; }
inline void GRID::grid::cambiaValore(Coordinate coord, int newValue) { cellValue[coord.x()][coord.y()] = newValue; }

int& GRID::grid::operator[](GRID::Coordinate coord) {return cellValue[coord.x()][coord.y()];}
std::ostream& GRID::operator<<(std::ostream& os, grid& sudoku)
{
    int i, j;

    os << std::endl << std::endl;
    for ( i = 0; i < 9; i++) {
        for ( j = 0; j < 9; j++) { GRID::Coordinate coord(i, j);  os << sudoku.returnValue(coord) << " "; }
        os << std::endl;        
    }

    return os;
}

// operator non inline //
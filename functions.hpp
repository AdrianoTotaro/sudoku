#ifndef G_FUNC
#define G_FUNC

#include<vector>
#include<ostream>
namespace GRID
{
    class Coordinate
    {
        private:
            std::pair<int, int> coord;


        public:
            Coordinate casellaSuccessiva();
            Coordinate(int x, int y);
            Coordinate();
            bool fineGriglia();
            int x();
            int y();
            friend std::ostream& operator<<(std::ostream&, const Coordinate&);
            Coordinate operator++();
    };

    std::ostream& operator<<(std::ostream&, const Coordinate&);


    class grid{
        
        private:
            int cellValue[9][9];

            bool orizzControll(int x, int y);
            bool squareControll(int x, int y);
            bool verticalControll(int x, int y);
            bool controlls(int x, int y, int);
            std::vector<int> valoriPossibili(Coordinate);

        public:

            grid(); // set all cell value to 0 //
            int& operator[](Coordinate);
            void importGrid();
            void importFromFile(std::string);
            bool backtracking(Coordinate);
            int returnValue(Coordinate);
            void cambiaValore(Coordinate, int);
            void callBacktracking();
            friend std::ostream& operator<<(std::ostream&, grid&);
    };

    std::ostream& operator<<(std::ostream& os, grid& sudoku);
    /* {
        int i, j;
        os << std::endl;os << std::endl;
        
        for ( i = 0; i < 9; i++) { for ( j = 0; j < 9; j++) { GRID::Coordinate coord(i, j); os << sudoku.returnValue(coord) << " "; } os << std::endl; }

        return os;
    } */

    

    
}

#endif
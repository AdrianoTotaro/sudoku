#ifndef G_FUNC
#define G_FUNC

namespace GRID
{   
    typedef struct 
    {
        int value;
        int userValue = 0;
    
    }cell;

    class grid{

        cell cellValue[9][9];

        bool orizzControll(int x, int y);
        bool squareControll(int x, int y);
        bool verticalControll(int x, int y);
        bool controlls(int x, int y);

        public:

            grid(); // set all cell value to 0 //
            void importGrid();
            void importFromFile(std::string);
            void backtracking();
            void printGrid();
    };
}

#endif
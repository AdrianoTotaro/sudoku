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

        bool orizzControll(cell *);
        bool squareControll(cell *);
        bool verticalControll(cell *);

        public:

            grid(); // set all cell value to 0 //
            void importGrid();
            int backtracking();



    };
}

#endif
#include <iostream>
#include "position.h"
#include "cell.h"
#include "pathfinder.h"
//Richie Breslin Rodney Breslin
// CSC 2110
//Final Project using A* Algorithm
int main()
{

    int exampleMap1[5][6] = {{1, 1, 1, 1, 1, 1},
                             {0, 0, 0, 0, 0, 1},
                             {1, 1, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 1},
                             {1, 1, 1, 1, 2, 1}};

    int exampleMap2[5][6] = {{1, 1, 1, 0, 1, 1},
                             {1, 0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 1, 0},
                             {0, 1, 1, 0, 1, 2},
                             {1, 1, 1, 1, 1, 1}};

    int exampleMap3[5][6] = {{1, 1, 1, 0, 1, 1},
                             {1, 1, 1, 1, 1, 1},
                             {1, 0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1, 1},
                             {1, 0, 1, 2, 1, 1}};

    int exampleMap4[5][6] = {{1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1},
                             {1, 1, 0, 0, 0, 1},
                             {1, 0, 0, 0, 0, 1},
                             {1, 0, 0, 2, 0, 1}};

    const int MAP_WIDTH = 5;
    const int MAP_HEIGHT = 6;

    //examplemap1
    cell *p_ExMap = new cell[MAP_WIDTH * MAP_HEIGHT];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            //Change this to map you want to search
            p_ExMap[j * MAP_WIDTH + i].setCellType(exampleMap1[i][j]);
    cout << endl;
    pathfinder path(p_ExMap, 2, 0);
    path.search();
    path.display();
    cout << endl;
    cout << "End of program (main)" << endl;
}

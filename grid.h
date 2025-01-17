#pragma once
#include <vector>
#include <raylib.h>


class Grid
{

public:
    Grid();
    void Print();
    void Initialize();
    void Draw();
   int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;


};

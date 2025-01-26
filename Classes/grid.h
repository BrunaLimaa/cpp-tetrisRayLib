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
   bool isCellOutside(int row, int column);
   bool isCellEmpty(int row, int column);

private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;


};

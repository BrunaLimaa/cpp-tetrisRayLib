<<<<<<< HEAD
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
=======
#pragma once
#include <vector>
#include <raylib.h>


class Grid
{

public:
    Grid();
    void Print();
    void Initialize();
   int grid[20][10];

private:
    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;

};
>>>>>>> c4d91287b449b163e687a6c0f196d3220778cb3c

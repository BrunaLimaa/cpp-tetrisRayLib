<<<<<<< HEAD
#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid(){

    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = getCellColors();
}

void Grid::Initialize(){

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
        
    }

}

void Grid::Print(){

     for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

}

void Grid::Draw(){


     for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column*cellSize+1, row*cellSize+1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }


=======
#include "grid.h"
#include <iostream>

Grid::Grid(){

    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
}

void Grid::Initialize(){

    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
        
    }

}

void Grid::Print(){

     for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

>>>>>>> c4d91287b449b163e687a6c0f196d3220778cb3c
}
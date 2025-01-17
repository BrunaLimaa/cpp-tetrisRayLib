#include "raylib.h"
#include "grid.h"

int main()
{

    Color cyantemp = {0,255,255,255};
    
    InitWindow(300,600,"TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    grid.grid[0][0]=1;
    grid.grid[2][0]=4;
    grid.grid[4][0]=7;




    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(cyantemp);

        grid.Draw();


        EndDrawing();
    }
    
    CloseWindow();

}
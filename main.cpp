#include "raylib.h"
#include "grid.h"

int main()
{
<<<<<<< HEAD

    Color cyantemp = {0,255,255,255};
    
    InitWindow(300,600,"TETRIS");
=======
    InitWindow(400,600,"TETRIS");
>>>>>>> c4d91287b449b163e687a6c0f196d3220778cb3c
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

<<<<<<< HEAD
    grid.grid[0][0]=1;
    grid.grid[2][0]=4;
    grid.grid[4][0]=7;



=======
>>>>>>> c4d91287b449b163e687a6c0f196d3220778cb3c

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
<<<<<<< HEAD
        ClearBackground(cyantemp);

        grid.Draw();


=======
        ClearBackground(PINK);
>>>>>>> c4d91287b449b163e687a6c0f196d3220778cb3c
        EndDrawing();
    }
    
    CloseWindow();

}
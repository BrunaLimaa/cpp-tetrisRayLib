#include "raylib.h"
#include "grid.h"

int main()
{
    InitWindow(400,600,"TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();


    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(PINK);
        EndDrawing();
    }
    
    CloseWindow();

}
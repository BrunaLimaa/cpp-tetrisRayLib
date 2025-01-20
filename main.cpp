#include "raylib.h"
#include "Classes\grid.h"
#include "blocks.cpp"

int main()
{
    //useless comment

    Color cyantemp = {0,255,255,255};
    
    InitWindow(300,600,"TETRIS");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    TBlock block = TBlock();
    //block.Move(4, 3);



    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(cyantemp);

        grid.Draw();
        block.Draw();


        EndDrawing();
    }
    
    CloseWindow();

}
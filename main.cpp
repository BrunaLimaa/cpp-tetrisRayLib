#include "raylib.h"
#include "Classes\game.h"

int main()
{
    //useless comment

    Color cyantemp = {0,255,255,255};
    
    InitWindow(300,600,"TETRIS");
    SetTargetFPS(60);

    Game game = Game();
    

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(cyantemp);

        game.Draw();
        game.handleInput();

        EndDrawing();
    }
    
    CloseWindow();

}
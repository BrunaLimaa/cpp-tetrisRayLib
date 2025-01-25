#include "raylib.h"
#include "Classes\game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}


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
        if (EventTriggered(0.3))
        {
             game.MoveBlockDown();
        }

        EndDrawing();
    }
    
    CloseWindow();

}
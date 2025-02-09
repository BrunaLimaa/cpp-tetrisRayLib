#include "raylib.h"
#include "Classes\game.h"
#include "Classes\colors.h"
#include <iostream>

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

    Color cyantemp = {60,38,188,255};
    
    InitWindow(500,620,"TETRIS");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/Debrosee-ALPnL.ttf", 64, 0, 0);
    Font font2 = LoadFontEx("Font/Midnight Letters Font - itch.io.url", 64, 0, 0);

    Game game = Game();
    

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(cyantemp);
        DrawTextEx(font, "SCORE", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {360, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {310, 450}, 38, 2, WHITE);
        };
        
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, blue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font2, scoreText, {310 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
        
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, blue);
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
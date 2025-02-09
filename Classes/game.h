#pragma once
#include "Classes\grid.h"
#include "blocks.cpp"

class Game
{
private:
    bool isBlockOutside();
    std::vector<Block>  blocks;
    Block currentBlock;
    Block nextBlock;
    void rotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void updateScore(int linesCleared, int moveDownPoints);
  
    

public:
    Game();
    void Draw();
    void handleInput();
    void MoveBlockDown();
    std::vector<Block> getAllBlocks();
    Grid grid;
    void MoveBlockLeft();
    void MoveBlockRight();
    Block getRandomBlock();   
    bool gameOver;
    int score;
};

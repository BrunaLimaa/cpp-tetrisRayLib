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
    std::vector<Block> getAllBlocks();
    Grid grid;
    void MoveBlockLeft();
    void MoveBlockRight();
    Block getRandomBlock(); 
    Sound rotateSound;
    Sound clearSound;
  
    

public:
    Game();
    ~Game();
    void Draw();
    void handleInput();
    void MoveBlockDown();  
    bool gameOver;
    int score;
    Music music;
   
};

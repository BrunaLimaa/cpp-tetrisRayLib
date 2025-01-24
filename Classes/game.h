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
    void MoveBlockLeft();
    void MoveBlockRight();
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();

public:
    Game();
    void Draw();
    void handleInput();
    void MoveBlockDown();
};

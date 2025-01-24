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

public:
    Game();
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void Draw();

    void handleInput();

    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
};

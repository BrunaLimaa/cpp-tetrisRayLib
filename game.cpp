#include "Classes\game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();

}

Block Game::getRandomBlock(){

if (blocks.empty()){

    blocks = getAllBlocks();

}
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
    
}

std::vector<Block> Game::getAllBlocks(){

    return {LBlock(), JBlock(), IBlock(),OBlock(), ZBlock(), SBlock(), TBlock()};
}

void Game::Draw(){

    grid.Draw();
    currentBlock.Draw();

}
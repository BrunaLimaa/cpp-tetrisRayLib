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


void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    { 
    case KEY_LEFT:
    MoveBlockLeft();        
        break;
    case KEY_DOWN:
    MoveBlockDown();
        break;
    case KEY_RIGHT:
    MoveBlockRight();
        break;
    case KEY_UP:
        rotateBlock();
        break;
    
    }

}

void  Game::MoveBlockLeft(){
    currentBlock.Move(0, -1);
    if (isBlockOutside())
    {
        currentBlock.Move(0, 1);
    }
    
}

void Game::MoveBlockRight(){
    currentBlock.Move(0, 1);
    if (isBlockOutside())
    {
        currentBlock.Move(0,-1);
    }

}

void Game::MoveBlockDown(){
    currentBlock.Move(1,0);
    if (isBlockOutside())
    {
        currentBlock.Move(-1,0);
    }
}

bool Game::isBlockOutside()
    {
       std::vector<Position> tiles = currentBlock.getCellPositions();
       for(Position item: tiles){
             if (grid.isCellOutside(item.row, item.column))
             {
                  return true;
             }
       }
        return false;
    };


void Game::rotateBlock()
{
    currentBlock.rotate();

}
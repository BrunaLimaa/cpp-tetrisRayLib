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

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
    
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles){
        if(grid.isCellEmpty(item.row, item.column) == false){
            return false;
        } 
    }
    return true;
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
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, 1);
    }
    
}

void Game::MoveBlockRight(){
    currentBlock.Move(0, 1);
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0,-1);
    }

}

void Game::MoveBlockDown(){
    currentBlock.Move(1,0);
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(-1,0);
        LockBlock();
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
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.undoRotation();
    }
    

}
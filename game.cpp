#include "Classes\game.h"
#include <random>



Game::Game(){

  
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
    score = 0;

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

    if(BlockFits() == false) {
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    int rowsCleared = grid.clearFullRows();
    updateScore(rowsCleared, 0);
    
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

    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    { 
    case KEY_LEFT:
    MoveBlockLeft();        
        break;
    case KEY_DOWN:
    MoveBlockDown();
    updateScore(0, 1);
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

    if (!gameOver)
    {
       currentBlock.Move(0, -1);
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0, 1);
    }
    }
     
}

void Game::MoveBlockRight(){

     if (!gameOver){
    currentBlock.Move(0, 1);
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(0,-1);
    }
     }

}

void Game::MoveBlockDown(){

     if (!gameOver){
    currentBlock.Move(1,0);
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.Move(-1,0);
        LockBlock();
    }
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
     if (!gameOver){
    currentBlock.rotate();
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.undoRotation();
    }
     }
}
void Game::Reset()
{
    grid.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
    score += 100;
        break;
    
    case 2:
    score += 300;
        break;

    case 3: 
    score += 500;
        break;   
        
    default:
        break;
    }
    
    score += moveDownPoints;

}
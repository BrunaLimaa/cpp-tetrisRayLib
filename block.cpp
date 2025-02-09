#include "Classes\block.h"

Block::Block(){

    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
    row_offset = 0;
    column_offset = 0;

}


void Block::Draw(){

    std::vector<Position> tiles = getCellPositions();

    for (Position item: tiles)
    {
       DrawRectangle(item.column*cellSize+11, item.row*cellSize+11, cellSize-1, cellSize-1, colors[id] );
    };
    

};

void Block::Move(int rows, int columns){

    row_offset += rows;
    column_offset  += columns;


}

std::vector<Position> Block::getCellPositions(){

    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item: tiles)
    {
        Position newPos = Position(item.row + row_offset, item.column +  column_offset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}
void Block::rotate()
{

    rotationState ++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
}
void Block::undoRotation()
{
    rotationState--;
    if(rotationState == -1){
        rotationState = cells.size() -1;
    }
}
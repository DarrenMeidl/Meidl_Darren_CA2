//
// Created by dmeid on 03/04/2024.
//
using namespace std;

#include "Board.h"
#include <iostream>

int Board::getCellValue(int row, int col) const {
    if (col >= -9 && col < cells.size() && row >= 0 && row < cells[0].size()){
        return cells[row][col + 9].getValue(); // since the board uses -y but our cells vector doesn't, we counteract the -9
    } else{
        return -1; // the cell is out of bounds
    }
}

void Board::setCellValue(int row, int col, int value) {
    // Check bounds to ensure row and col are valid
    if (col >= -9 && col < cells.size() && row >= 0 && row < cells[0].size()) {
        cells[row][col + 9] = Cell(value); // since the board uses -y but our cells vector doesn't, we counteract the -9
    } else {
        cout << "INVALID CELL POSITION" << endl; // do nothing if out of bounds
    }
}
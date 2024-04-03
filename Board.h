//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_BOARD_H
#define MEIDL_DARREN_CA2_BOARD_H
#include "Cell.h"
#include <vector>

using namespace std;

class Board {
private:
    vector<vector<Cell>> cells; // vector of cells
public:
    // Constructor which allows us to set the dimensions of the board - Each row (x) has a corresponding column/vector (y)
    Board(int rows, int cols) : cells(rows, vector<Cell>(cols)) {}
    int getCellValue(int row, int col) const; // get a value of a cell at any position in the board
    void setCellValue(int row, int col, int value); // set a value of a cell at any position in the board
    Board getCopy() const; // returns a copy of the board
};


#endif //MEIDL_DARREN_CA2_BOARD_H

//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_BOARD_H
#define MEIDL_DARREN_CA2_BOARD_H
#include "Cell.h"
#include "Bug.h"
#include <vector>

using namespace std;

class Board {
private:
    vector<vector<Cell>> cells; // vector of cells
    vector<Bug*> bugsVector; // vector of pointer Bugs, so it can point at all derived objects (Hopper, Crawler)
public:
    // Constructor which allows us to set the dimensions of the board - Each row (x) has a corresponding column/vector (y)
    Board(int rows, int cols) : cells(rows, vector<Cell>(cols)) {}
    // Getters & Setters (Cells)
    int getCellValue(int row, int col) const; // get a value of a cell at any position in the board
    void setCellValue(int row, int col, int value); // set a value of a cell at any position in the board

    Board getCopy() const; // returns a copy of the board
    void FreeMemoryAllocated();
    // Main Feautres - might need this: vector<Bug*> const &v
    void fillInBugs();
    void printAllBugs() const;
    void findBugByID() const;
    void tapBoard();
    void displayLifeHistory() const;
    int Exit() const;
    void DisplayAllCells() const;
};


#endif //MEIDL_DARREN_CA2_BOARD_H

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
public:
    vector<vector<Cell*>> cells; // vector of cells
    vector<Bug*> bugsVector; // vector of pointer Bugs, so it can point at all derived objects (Hopper, Crawler)
private:
    int boardHeight; // save height
    int boardWidth; // save width
public:
    // Constructor which allows us to set the dimensions of the board - Each row (x) has a corresponding list columns (y)
    Board(int rows, int cols) : cells(rows, vector<Cell*>(cols)), boardHeight(cols), boardWidth(rows) {}
    // Getters & Setters (Cells)
    int getCellValue(int row, int col) const; // get a value of a cell at any position in the board
    void setCellValue(int row, int col, int value); // set a value of a cell at any position in the board
    void fillInCells(); // fills in cells into the cells vector

    Board getCopy() const; // returns a copy of the board
    void FreeMemoryAllocated();

    // Main Features - might need this: vector<Bug*> const &v
    void fillInBugs();
    void printAllBugs() const;
    void findBugByID() const;
    void tapBoard();
    void displayLifeHistory() const;
    void Exit() const;
    void displayAllCells() const;
    void runSimulation();
    // Other
    void displayAllCellsLiving() const;
    bool oneBugRemains() const;
    void ExitToSimulationFile(ofstream &file) const;
    void delay(int seconds);
};


#endif //MEIDL_DARREN_CA2_BOARD_H

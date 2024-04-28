//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_BOARD_H
#define MEIDL_DARREN_CA2_BOARD_H
#include "Cell.h"
#include "Bug.h"
#include "SuperBug.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Board {
public:
    vector<vector<Cell*>> cells; // vector of cells
    vector<Bug*> bugsVector; // vector of pointer Bugs, so it can point at all derived objects (Hopper, Crawler)
    sf::RenderWindow& window; // Reference to SFML window for drawing
    SuperBug* player;
private:
    int boardHeight; // save height
    int boardWidth; // save width
public:
    // Constructor which allows us to set the dimensions of the board - Each row (x) has a corresponding list columns (y)
    Board(int rows, int cols, sf::RenderWindow& window) : cells(rows, vector<Cell*>(cols)), boardHeight(cols), boardWidth(rows), window(window) {}
    // Main Features
    void fillInBugs();
    void printAllBugs() const;
    void findBugByID() const;
    void tapBoard();
    void displayLifeHistory() const;
    void Exit() const;
    void displayAllCells() const;
    void RunSimulation();
    void drawAll() const;
    void HandleSuperBugInput();
    // Other
    void fillInCells(); // fills in cells into the cells vector
    void FreeMemoryAllocated();
    bool oneBugRemains() const;
    void ExitToSimulationFile(string &file) const;
};


#endif //MEIDL_DARREN_CA2_BOARD_H

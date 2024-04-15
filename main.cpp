// CA2 by Darren Meidl GD2b
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bug.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Crawler.h"
#include "Hopper.h"
#include <ostream>
#include "Board.h"

using namespace std;

void RunSimulation(Board &board);

int main() {
    Board board(10, 10); // Create a new board
    RunSimulation(board);
    board.Exit();
    board.FreeMemoryAllocated();

    return 0;
}

void RunSimulation(Board &board){
    string outFile("../bugs_life_simulation.out");

    board.fillInBugs();
    board.fillInCells();
    // Simulation runs until one bug remains
    while (!board.oneBugRemains()){
        board.tapBoard();
        board.displayLifeHistory();
        board.ExitToSimulationFile(outFile);
        board.delay(1); // pause for a second
    }
}
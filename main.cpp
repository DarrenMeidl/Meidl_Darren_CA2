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

int main() {
    Board board(10, 10); // Create a new board
    // Call the board's functions
    board.fillInBugs();
    board.fillInCells();
    board.tapBoard();
    board.tapBoard();
    board.tapBoard();
    board.tapBoard();
    board.displayLifeHistory();
    board.displayAllCells();
    board.FreeMemoryAllocated();

    return 0;
}


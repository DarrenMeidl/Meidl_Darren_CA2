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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bug's Life Project");
    Board board(10, 10, window); // Create a new board
    bool running = true;
    while (running){
        window.clear();
        int input;
        cout << "**********************" << endl;
        cout << "* BUG'S LIFE PROJECT *" << endl;
        cout << "**********************" << endl;
        cout << "1. Initialise the Bug Board" << endl;
        cout << "2. Display All Bugs" << endl;
        cout << "3. Find a Bug" << endl;
        cout << "4. Tap the Bug Board" << endl;
        cout << "5. Display Life History of all Bugs" << endl;
        cout << "6. Exit" << endl;
        cout << "7. Display all Cells" << endl;
        cout << "8. Run Simulation" << endl;
        cout << "9. Quit" << endl;
        cout << "----------------------" << endl;
        cout << "Enter menu option: " << endl;
        cin >> input;
        switch(input){
            case 1:
                cout << "Initialising the Bug Board.." << endl;
                board.fillInBugs();
                board.fillInCells();
                cout << "Bugs filled in!" << endl;
                break;
            case 2:
                cout << "Printing all bugs.." << endl;
                board.printAllBugs();
                break;
            case 3:
                cout << "Finding bug.." << endl;
                board.findBugByID();
                break;
            case 4:
                cout << "Tapping board.." << endl;
                board.tapBoard();
                board.drawAll();
                break;
            case 5:
                cout << "Displaying life history.." << endl;
                board.displayLifeHistory();
                break;
            case 6:
                cout << "Exiting to file.." << endl;
                board.Exit();
                break;
            case 7:
                cout << "Displaying all cells.." << endl;
                board.displayAllCells();
                break;
            case 8:
                cout << "Running simulation.." << endl;
                RunSimulation(board);
                break;
            case 9:
                cout << "Goodbye :(" << endl;
                running = false;
                break;
        }
        window.display();
    }
    board.FreeMemoryAllocated();

    return 0;
}
// Feature 9
void RunSimulation(Board &board){
    string outFile("../bugs_life_simulation.out");
    // Simulation runs until one bug remains
    while (!board.oneBugRemains()){
        board.tapBoard();
        board.displayLifeHistory();
        board.ExitToSimulationFile(outFile); // pass in the output file to the funciton
        board.drawAll();
        board.delay(1); // pause for a second
    }
    if (board.oneBugRemains()){
        cout << "---ONE BUG STANDING---" << endl;
        board.displayLifeHistory();
        board.drawAll();
    }
}
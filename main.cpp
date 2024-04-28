// CA2 by Darren Meidl GD2b
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <ostream>

#include "Board.h"
#include "Bug.h"

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Bug's Life Project");
    Board board(10, 10, window); // Create a new board
    bool running = true;

    while (running){
        window.clear();
        int input;
        cout << "**********************" << endl;
        cout << "* BUG'S LIFE PROJECT *" << endl;
        cout << "**********************" << endl;
        cout << "1. Initialise the Bug Board (load data from file)" << endl;
        cout << "2. Display All Bugs" << endl;
        cout << "3. Find a Bug (given an id)" << endl;
        cout << "4. Tap the Bug Board (causes move all, then fight/eat)" << endl;
        cout << "5. Display Life History of all Bugs (path taken)" << endl;
        cout << "6. Display all Cells listing their Bugs" << endl;
        cout << "7. Run Simulation (generates a Tap every second)" << endl;
        cout << "8. Exit (write Life History of all Bugs to file)" << endl;
        cout << "----------------------" << endl;
        cout << "Enter menu option: " << endl;
        cin >> input;
        switch(input){
            case 1:
                cout << "Initialising the Bug Board.." << endl;
                board.fillInBugs();
                board.fillInCells();
                board.drawAll();
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
                cout << "Displaying all cells.." << endl;
                board.displayAllCells();
                break;
            case 7:
                cout << "Running simulation.." << endl;
                board.RunSimulation();
                cout << "Simulation over." << endl;
                break;
            case 8:
                cout << "Exiting to file.." << endl;
                board.Exit();
                cout << "Goodbye :(" << endl;
                running = false;
                if (window.isOpen())
                    window.close(); // Close window if it is still open
                break;
        }
    }
    board.FreeMemoryAllocated(); // delete all pointers
    return 0;
}
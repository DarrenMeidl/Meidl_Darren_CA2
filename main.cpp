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
                cout << "Exiting to file.." << endl;
                board.Exit();
                break;
            case 7:
                cout << "Displaying all cells.." << endl;
                board.displayAllCells();
                break;
            case 8:
                cout << "Running simulation.." << endl;
                board.RunSimulation();
                window.close();
                cout << "Simulation over." << endl;
                break;
            case 9:
                cout << "Goodbye :(" << endl;
                running = false;
                if (window.isOpen())
                    window.close(); // Close window if it is still open
                break;
        }
    }
    board.FreeMemoryAllocated();

    return 0;
}
/*
// Feature 9
void RunSimulation(Board &board, sf::RenderWindow &window){
    string outFile("../bugs_life_simulation.out");
    sf::Clock clock; // Create a clock to track time
    float elapsedTime = 0; // Variable to track elapsed time
    // Simulation runs until one bug remains
    while (!board.oneBugRemains() && window.isOpen()){
        board.HandleSuperBugInput(); // handle player input

        elapsedTime += clock.restart().asSeconds(); // increment time
        if (elapsedTime >= 1.0f) { // Check if a second has passed
            elapsedTime = 0; // reset elapsed time
            board.tapBoard(); // move bugs
            board.displayLifeHistory();
            board.ExitToSimulationFile(outFile); // pass in the output file to the function
        }
        // Clear the window and draw updated bug positions
        board.drawAll();
    }
    cout << "---ONE BUG STANDING---" << endl;
    board.displayLifeHistory();
    board.drawAll(); // draw updated bug positions
}*/
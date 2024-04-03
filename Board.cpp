//
// Created by dmeid on 03/04/2024.
//
using namespace std;

#include "Board.h"
#include "Cell.h"
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

#include <vector>
#include <string>

#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>

Board Board::getCopy() const{
    return *this; // return only a copy of the board
}
void Board::FreeMemoryAllocated() {
    // Free the memory allocated for the bug objects
    for (Bug* bug : bugsVector) {
        delete bug;
    }
}
// Getters & Setters (Cells)
int Board::getCellValue(int row, int col) const {
    // Check bounds to ensure row and col are valid before getting cell
    if (col >= -9 && col < cells.size() && row >= 0 && row < cells[0].size()){
        return cells[row][col + 9].getValue(); // since the board uses -y but our cells vector doesn't, we counteract the -9
    } else{
        return -1; // the cell is out of bounds
    }
}
void Board::setCellValue(int row, int col, int value) {
    // Check bounds to ensure row and col are valid before setting cell
    if (col >= -9 && col < cells.size() && row >= 0 && row < cells[0].size()) {
        cells[row][col + 9].setValue(value); // since the board uses -y but our cells vector doesn't, we counteract the -9
    } else {
        cout << "INVALID CELL POSITION" << endl; // do nothing if out of bounds
    }
}

void Board::fillInBugs() {
    ifstream file("../bugs.txt"); // open file to read from it
    if (!file.is_open()){
        cout << "CAN'T OPEN FILE" << endl;
        return; // if it can't open the file then end the function early
    }

    string line;
    while (getline(file, line)){ // read a line from the file

        char letter;
        int id, x, y, direction, size, hopLength; // x & y to be added as a pair
        stringstream ss(line);
        ss >> letter;

        // If it's a crawler type, create a Crawler object and add it to the bugs vector
        if (letter == 'C') {
            ss.ignore(1); // Ignore the semicolon
            ss >> id;
            ss.ignore(1);
            ss >> x;
            ss.ignore(1);
            ss >> y;
            ss.ignore(1);
            ss >> direction;
            ss.ignore(1);
            ss >> size;
            Bug* crawler = new Crawler(id, x, y*-1, direction, size); // create a pointer of type bug pointing at the new Hopper object
            bugsVector.push_back(crawler); // Add the address of the object to the vector
        }
            // If it's a hopper type, create a Crawler object and add it to the bugs vector
        else if (letter == 'H'){
            ss.ignore(1); // Ignore the semicolon
            ss >> id;
            ss.ignore(1);
            ss >> x;
            ss.ignore(1);
            ss >> y;
            ss.ignore(1);
            ss >> direction;
            ss.ignore(1);
            ss >> size;
            ss.ignore(1);
            ss >> hopLength;
            Bug* hopper = new Hopper(id, x, y*-1, direction, size, hopLength); // create a pointer of type bug pointing at the new Hopper object
            bugsVector.push_back(hopper); // Add the address of the object to the vector
        }

    }
}

void Board::printAllBugs() const {
    // print the bug objects from the vector of bugs
    for (const Bug* bug : bugsVector){
        bug->printBug();
    }
}

void Board::findBugByID() const {
    bool foundBug = false;
    int userInput; // get user to input an id integer
    cout << "Enter a bug's ID: ";
    cin >> userInput;
    for (const Bug* bug : bugsVector){ // run through all the bugs in the vector
        if (bug->getID() == userInput){ // if the bug has the same id
            bug->printBug(); // print it
            foundBug = true; // we found the bug
        }
    }
    if (!foundBug) // if we didn't find the bug
        cout << "bug " << userInput << " not found" << endl;
}

void Board::tapBoard() {
    for (Bug* bug : bugsVector){ // run through all the bugs in the vector
        cout << "***BEFORE MOVE***" << endl;
        bug->printBug();
        bug->move(); // move this bug
        cout << "***AFTER MOVE***" << endl;
        bug->printBug();
        cout << "" << endl;
    }
}

void Board::displayLifeHistory() const {
    list<pair<int, int>>::iterator iter; // iterator for the path list
    for (Bug* bug : bugsVector) { // run through all the bugs in the vector
        cout << bug->getID() << " " << bug->getName() << " Path: "; // print id & name
        // iterate through this bug's list called 'path'
        for (const auto& pair : bug->getPath()){
            cout << "(" << pair.first << ", " << pair.second << "), "; // print each int from the pair seperately
        }
        cout << (bug->getAlive() ? "Alive!" : "Eaten.") << endl;
    }
}

void Board::Exit() const {
    ofstream file("../bugs_life_history_date_time.out"); // open file
    if (!file.is_open()){ // check if it can be opened
        cout << "CAN'T OPEN FILE" << endl;
        return;
    }

    list<pair<int, int>>::iterator iter; // iterator for the path list
    for (Bug* bug : bugsVector) { // run through all the bugs in the vector
        file << bug->getID() << " " << bug->getName() << " Path: "; // print id & name
        // iterate through this bug's list called 'path'
        for (const auto& pair : bug->getPath()){
            file << "(" << pair.first << ", " << pair.second << "), "; // print each int from the pair seperately
        }
        file << (bug->getAlive() ? "Alive!" : "Eaten.") << endl;
    }
}

void Board::displayAllCells() const {

    int x;
    int y;
    for (x = 0; x <= boardWidth; x++){ // for each x position - increment 0,1,2,3,4 etc.
        for (y = 0; y >= boardHeight; y--){ // for each y position - increment 0,-1,-2,-3,-4 etc.
            bool isEmpty = true;
            cout << "(" << x << "," << y << "): ";
            for (const Bug* bug : bugsVector) { // for each bug
                //if this bug's position.first == x & .second == y
                if (bug->getPair().first == x && bug->getPair().second == y){
                    isEmpty = false; // we found at least 1 bug
                    cout << bug->getName() << " " << bug->getID() << " "; // print name & id
                }
            }
            if (isEmpty){ // by the end of the for loop, if it's still empty
                cout << "empty" << endl; // print empty
            } else{ // otherwise
                cout << endl; // end the current line
            }
        }
    }
}
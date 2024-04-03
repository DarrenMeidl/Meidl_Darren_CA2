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
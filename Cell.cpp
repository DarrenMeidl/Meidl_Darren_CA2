//
// Created by dmeid on 03/04/2024.
//

#include "Cell.h"

int Cell::getValue() const {
    return value;
}
void Cell::setValue(int value) {
    this->value = value;
}
void Cell::printPosition() const {
    cout << "(" << position.first << ", " << position.second << ")";
}
void Cell::incrementValue(int amount) {
    this->value += amount;
    state = "";
}
pair<int, int> Cell::getPosition() const{
    return position;
}
void Cell::setPosition(int x, int y) {
    position.first = x;
    position.second = y;
}
string Cell::getState() const{
    return state;
}
void Cell::setState(string s) {
    state = s;
}
// addBugById(Bug* b)
    // add Bug* b to list passed in as a parameter

// removeBugById(Bug* b)
    // bool foundBug = false;
    // for each Bug* bugInList in the bugsCellList
        // if Bug* b id == Bug* bugInList id
            // foundBug = true;
            // remove Bug* bugInList
            // return
    // if (!foundBug)
        // print error: Bug not in this cell

// checkForConflicts()
    // if size of bugsCellList is 2 or more
        // execute "Fight" code
        // set Bug* largest to first bug in the bugsCellList
        // for each Bug* current bugInList in the bugsCellList
            // if (current.getSize() > largest.getSize())
                // largest bug equals the current bug

        // "mark all other bugs as dead"
        // for each Bug* b bugInList in the bugsCellList
            // check if b is the largestBug, if it is we ignore it
                // b.setAlive(false);
                // largestBug size = largestBug size + b size

        // clear entire bugsCellList
        // add largest bug to bugsCellList

    // else
        // print: Only 1 bug on this cell
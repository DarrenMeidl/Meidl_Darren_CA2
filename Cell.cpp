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
    // if Bug* b alive == true
        // add Bug* b to list passed in as a parameter
    // else
        // print error: "Dead bugs can't be added"

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
        // "Find the largest bug"
        // set Bug* largest to first bug in the bugsCellList
        // create vector<Bug*> largestBugs
        // add largest to vector
        // for each Bug* current in the bugsCellList
            // if (current.getSize() > largest.getSize())
                // largest bug equals the current bug
                // remove all bugs from vector
                // add largest to vector
            // if (current.getSize() == largest.getSize())
                // add largest to vector

        // if largestBugs vector isn't empty
            // Bug* winner = random bug from vector

        // "mark all other bugs as dead, increase winner bug's size"
        // for each Bug* b in the bugsCellList
            // check if b == winner, if it is we ignore it         // either compare size or do operator overloading
                // b.setAlive(false);
                // winner size = winner size + b size

        // clear entire bugsCellList
        // add winner bug to bugsCellList

    // else
        // print: Only 1 bug on this cell
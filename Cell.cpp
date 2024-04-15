//
// Created by dmeid on 03/04/2024.
//

#include "Cell.h"
#include <vector>
#include <random>

using namespace std;
random_device cell_rd; // Create random number generator called cell_rd
mt19937 cell_gen(cell_rd()); // Seed the generator with a random device

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

void Cell::addBug(Bug* b){
    // if Bug* b is alive
    if (b->getAlive() == true){
        bugsCellList.push_back(b); // add Bug* b to list passed in as a parameter
    }
    else{
        cout << "Dead bugs can't be added" << endl; // print error
    }
}
void Cell::removeBug(Bug* b){
    bool foundBug = false;
    // if the bug we passed in is the same as the bug's id in this list
    for (Bug* bugInList : bugsCellList){
        if (b->getID() == bugInList->getID()){
            foundBug = true;
            bugsCellList.remove(bugInList); // remove the bug in the list
        }
    }
    if (!foundBug){ // if we never found a matching bug id
        cout << "Bug not in this cell" << endl; // print error
    }
}
void Cell::Fight(){
    cout << "Fighting on cell: (" << position.first << ", " << position.second << ")" << endl;

    if (bugsCellList.size() >= 2){
        // "Find largest bug(s)"
        Bug* largest = bugsCellList.front();
        vector<Bug*> largestBugs;

        // Debug print: List all bugs in the cell
        cout << "Bugs in the cell: ";
        for (Bug* b : bugsCellList) {
            cout << b->getID() << " ";
        }
        cout << endl;

        // Run through all bugs in the cell
        for (Bug* current : bugsCellList){
            if (current->getSize() > largest->getSize()){
                largest = current;
                largestBugs.clear();
                largestBugs.push_back(largest);
            }
            else if (current->getSize() == largest->getSize()){
                largestBugs.push_back(current);
            }
        }

        // Debug print: List largest bugs
        cout << "Largest bugs: ";
        for (Bug* b : largestBugs) {
            cout << b->getID() << " ";
        }
        cout << endl;

        Bug* winner = largest;

        if (largestBugs.size() >= 2){
            int randomIndex = rand() % largestBugs.size();
            winner = largestBugs[randomIndex];
        }

        for (Bug* b : bugsCellList){
            if (b->getID() != winner->getID()){
                b->setAlive(false);
                winner->setSize(winner->getSize() + b->getSize());
                if (winner->getSize() > 20) // Cap winner's size to 20 if it exceeds it
                    winner->setSize(20);
            }
        }

        cout << "Winner: " << winner->getID() << " with size " << winner->getSize() << endl;

        largestBugs.clear();
        //bugsCellList.clear();
        //bugsCellList.push_back(winner);
    }
}


/*void Cell::Fight(){
    if (bugsCellList.size() >= 2){
        // "Find largest bug(s)"
        Bug* largest = bugsCellList.front(); // set largest bug to first bug in the bugsCellList
        vector<Bug*> largestBugs; // largest bugs vector - so we can easily access elements
        // Run through all bugs in the cell
        for (Bug* current : bugsCellList){
            if (current->getSize() > largest->getSize()){ // if the current bug is bigger
                largest = current;
                largestBugs.clear();
                largestBugs.push_back(largest); // add new largest bug
            }
            else if (current->getSize() == largest->getSize()){ // if it's the same size
                largestBugs.push_back(current); // add the bug without removing existing bugs
            }
        }
        Bug* winner = largest; // set winner to largest bug
        // "Decide random winner if 2 or more bugs have same size"
        if (largestBugs.size() >= 2){ // if the largest bugs vector has 1 or more bugs
            int randomIndex = rand() % bugsCellList.size(); // always in bounds by ensuring number is between 0 and -1 of vector
            winner = largestBugs[randomIndex]; // decide a random winner
        } else{
            cout << "No largest bugs in vector" << endl;
        }
        // "mark all other bugs as dead, increase winner bug's size"
        for (Bug* b : bugsCellList){
            if (b->getID() != winner->getID()){ // either compare id or do operator overloading
                b->setAlive(false); // this bug is dead
                winner->setSize(winner->getSize() + b->getSize()); // add the dead bug's size to the winner's
                if (winner->getSize() > 20){ // ensures bug size can't exceed 20
                    winner->setSize(20);
                }
            }
        }

        largestBugs.clear();
        bugsCellList.clear();
        bugsCellList.push_back(winner);
    }
}*/
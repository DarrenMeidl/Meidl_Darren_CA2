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

using namespace std;

void printAllBugs(vector<Bug*> const v); // we don't want to change anything when printing
void findBugByID(vector<Bug*> const v); // we don't want to change anything when looking for id
void tapBoard(vector<Bug*> const &v); // pass by reference

int main() {
    vector<Bug*> bugsVector; // vector of pointer Bugs, so it can point at all derived objects (Hopper, Crawler)
    ifstream file("../bugs.txt"); // open file to read from it
    if (!file.is_open()){
        cout << "CAN'T OPEN FILE" << endl;
        return 69;
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
            ss.ignore(1); // Ignore the semicolon
            ss >> x;
            ss.ignore(1); // Ignore the semicolon
            ss >> y;
            ss.ignore(1); // Ignore the semicolon
            ss >> direction;
            ss.ignore(1); // Ignore the semicolon
            ss >> size;
            Bug* crawler = new Crawler(id, x, y*-1, direction, size);
            bugsVector.push_back(crawler); // Add the address of the object to the vector
        }
        // If it's a hopper type, create a Crawler object and add it to the bugs vector
        else if (letter == 'H'){
            ss.ignore(1); // Ignore the semicolon
            ss >> id;
            ss.ignore(1); // Ignore the semicolon
            ss >> x;
            ss.ignore(1); // Ignore the semicolon
            ss >> y;
            ss.ignore(1); // Ignore the semicolon
            ss >> direction;
            ss.ignore(1); // Ignore the semicolon
            ss >> size;
            ss.ignore(1); // Ignore the semicolon
            ss >> hopLength;
            Bug* hopper = new Hopper(id, x, y*-1, direction, size, hopLength);
            bugsVector.push_back(hopper); // Add the address of the object to the vector
        }

    }

    printAllBugs(bugsVector);
    findBugByID(bugsVector);
    tapBoard(bugsVector);
    printAllBugs(bugsVector);

    // Free the memory allocated for the bug objects
    for (Bug* bug : bugsVector) {
        delete bug;
    }

    return 0;
}
void printAllBugs(vector<Bug*> const v){
    // print the bug objects from the vector of bugs
    for (Bug* bug : v){
        bug->printBug();
    }
}

void findBugByID(vector<Bug*> const v){
    bool foundBug = false;
    int userInput; // get user to input an id integer
    cout << "Enter a bug's ID: ";
    cin >> userInput;
    for (Bug* bug : v){ // run through all the bugs in the vector
        if (bug->getID() == userInput){ // if the bug has the same id
            bug->printBug(); // print it
            foundBug = true; // we found the bug
        }
    }
    if (!foundBug) // if we didn't find the bug
        cout << "bug " << userInput << " not found" << endl;
}

void tapBoard(vector<Bug*> const &v){
    for (Bug* bug : v){ // run through all the bugs in the vector
        cout << "***BEFORE MOVE***" << endl;
        bug->printBug();
        bug->move(); // move this bug
        cout << "***AFTER MOVE***" << endl;
        bug->printBug();
        cout << "" << endl;
    }
}
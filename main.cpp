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

// Declaring functions
void printAllBugs(vector<Bug*> const &v);
void findBugByID(vector<Bug*> const &v);
void tapBoard(vector<Bug*> const &v);
void displayLifeHistory(vector<Bug*> const &v);


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
    tapBoard(bugsVector);
    tapBoard(bugsVector);
    tapBoard(bugsVector);
    displayLifeHistory(bugsVector);

    // Free the memory allocated for the bug objects
    for (Bug* bug : bugsVector) {
        delete bug;
    }

    return 0;
}

// Custom functions
void printAllBugs(vector<Bug*> const &v){
    // print the bug objects from the vector of bugs
    for (Bug* bug : v){
        bug->printBug();
    }
}

void findBugByID(vector<Bug*> const &v){
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

void displayLifeHistory(vector<Bug*> const &v){
    list<pair<int, int>>::iterator iter; // iterator for the path list
    for (Bug* bug : v) { // run through all the bugs in the vector
        if (Crawler* crawler = dynamic_cast<Crawler*>(bug)) { // if the downcasted pointer bug is safely of type Crawler
            cout << bug->getID() << " Crawler Path: ";
        }
        else if (Hopper* hopper = dynamic_cast<Hopper*>(bug)) { // if the downcasted pointer bug is safely of type Hopper
            cout << bug->getID() << " Hopper Path: ";
        }
        // iterate through this bug's list called 'path'
        for (const auto& pair : bug->getPath()){
            cout << "(" << pair.first << ", " << pair.second << "), "; // print each int from the pair seperately
        }
        cout << (bug->getAlive() ? "Alive!" : "Eaten.") << endl;
    }
}
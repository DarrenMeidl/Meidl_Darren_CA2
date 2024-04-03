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

// Declaring functions
void fillInBugs(vector<Bug*> &v);
void printAllBugs(vector<Bug*> const &v);
void findBugByID(vector<Bug*> const &v);
void tapBoard(vector<Bug*> &v);
void displayLifeHistory(vector<Bug*> const &v);
int Exit(vector<Bug*> const &v);
void DisplayAllCells(vector<Bug*> const &v);

int main() {


    fillInBugs(bugsVector);
    printAllBugs(bugsVector);
    tapBoard(bugsVector);
    tapBoard(bugsVector);
    tapBoard(bugsVector);
    displayLifeHistory(bugsVector);
    Exit(bugsVector);

    Board board(10, 10);
    //DisplayAllCells(bugsVector);

    // Free the memory allocated for the bug objects
    for (Bug* bug : bugsVector) {
        delete bug;
    }

    return 0;
}

void fillInBugs(vector<Bug*> &bugsVector){
    ifstream file("../bugs.txt"); // open file to read from it
    if (!file.is_open()){
        cout << "CAN'T OPEN FILE" << endl;
        return;
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

void tapBoard(vector<Bug*> &v){
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
        cout << bug->getID() << " " << bug->getName() << " Path: "; // print id & name
        // iterate through this bug's list called 'path'
        for (const auto& pair : bug->getPath()){
            cout << "(" << pair.first << ", " << pair.second << "), "; // print each int from the pair seperately
        }
        cout << (bug->getAlive() ? "Alive!" : "Eaten.") << endl;
    }
}

int Exit(vector<Bug*> const &v){
    ofstream file("../bugs_life_history_date_time.out"); // open file
    if (!file.is_open()){ // check if it can be opened
        cout << "CAN'T OPEN FILE" << endl;
        return -1;
    }

    list<pair<int, int>>::iterator iter; // iterator for the path list
    for (Bug* bug : v) { // run through all the bugs in the vector
        file << bug->getID() << " " << bug->getName() << " Path: "; // print id & name
        // iterate through this bug's list called 'path'
        for (const auto& pair : bug->getPath()){
            file << "(" << pair.first << ", " << pair.second << "), "; // print each int from the pair seperately
        }
        file << (bug->getAlive() ? "Alive!" : "Eaten.") << endl;
    }
    return 1;
}
// OLD FUNCTION BEFORE BOARD & CELL CLASS
/*void DisplayAllCells(vector<Bug*> const &v){
    int x;
    int y;
    for (x = 0; x <= 9; x++){ // for each x position - increment 0,1,2,3,4 etc.
        for (y = 0; y >= -9; y--){ // for each y position - increment 0,-1,-2,-3,-4 etc.
            bool isEmpty = true;
            cout << "(" << x << "," << y << "): ";
            for (Bug* bug : v) { // for each bug
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
}*/

void DisplayAllCells(vector<Bug*> const &v){


    /*int x;
    int y;
    for (x = 0; x <= 9; x++){ // for each x position - increment 0,1,2,3,4 etc.
        for (y = 0; y >= -9; y--){ // for each y position - increment 0,-1,-2,-3,-4 etc.
            bool isEmpty = true;
            cout << "(" << x << "," << y << "): ";
            for (Bug* bug : v) { // for each bug
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
    }*/
}


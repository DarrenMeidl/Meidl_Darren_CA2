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

int main() {
    vector<Bug*> bugsVector; // vector of pointer Bugs, so it can point at all derived objects (Hopper, Crawler)
    ifstream file("bugs.txt"); // open file to read from it
    if (!file.is_open()){
        cout << "CAN'T OPEN FILE" << endl;
        return 69;
    }

    string line;
    while (getline(file, line)){ // read a line from the file

        char letter;
        int id, x, y, direction, size, hopLength; // x & y to be added as a pair
        stringstream ss(line);
        ss >> letter >> id >> x >> y >> direction >> size >> hopLength; // get ints from line

        // If it's a crawler type, create a Crawler object and add it to the bugs vector
        if (letter == 'C') {
            Bug* crawler = new Crawler(id, x, y, direction, size);
            bugsVector.push_back(crawler); // Add the address of the object to the vector
        }
        // If it's a hopper type, create a Crawler object and add it to the bugs vector
        else if (letter == 'H'){
            Bug* hopper = new Hopper(id, x, y, direction, size, hopLength);
            bugsVector.push_back(hopper); // Add the address of the object to the vector
        }

    }
    // print the vector

    // Free the memory allocated for the bug objects
    for (Bug* bug : bugsVector) {
        delete bug;
    }

    return 0;
}

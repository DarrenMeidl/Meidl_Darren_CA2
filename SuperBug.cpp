//
// Created by dmeid on 24/04/2024.
//

#include "SuperBug.h"

void SuperBug::move() {

}

void SuperBug::handleInput(sf::Event& event) {

}

void SuperBug::printBug() const {
    string dir; // set the dir string based on direction value
    if (direction == 1)
        dir = "North";
    else if (direction == 2)
        dir = "East";
    else if (direction == 3)
        dir = "South";
    else if (direction == 4)
        dir = "West";
    // Print the values
    cout << id << " " << name << " " << "(" << position.first << ", " << position.second << ") "
         << size << " " << dir << " " << (alive ? "Alive" : "Dead") << endl;
}
string SuperBug::getName() const {
    return name;
}
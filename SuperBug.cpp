//
// Created by dmeid on 24/04/2024.
//

#include "SuperBug.h"

void SuperBug::move() {
    if (alive){ // don't move if we are dead
        // Move the SuperBug based on arrow key input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            position.second++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            position.second--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            position.first--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            position.first++;
        }
        // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
        path.emplace_back(position.first, position.second);
    }
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
//
// Created by dmeid on 24/04/2024.
//

#include "SuperBug.h"

SuperBug::SuperBug(int id, int x, int y, int direction, int size, sf::RenderWindow& window)
        : Bug(id, x, y, direction, size), window(window) {}

void SuperBug::move() {

}

void SuperBug::handleInput(sf::Event& event) {

}
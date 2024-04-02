//
// Created by dmeid on 02/04/2024.
//
#include <iostream>
#include <utility>
#include <list>
#ifndef MEIDL_DARREN_CA2_BUG_H
#define MEIDL_DARREN_CA2_BUG_H


class Bug {
protected: // all variables below declared as protected (only this class & derived classes can access these)
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
public:
    // Set all default values to 0 if no arguments provided
    Bug(int id = 0, const std::pair<int, int>& position = std::make_pair(0, 0), int direction = 0, int size = 0, bool alive = false)
            : id(id), position(position), direction(direction), size(size), alive(alive) {} // implement these variables
    virtual void move() = 0; // ensures this Bug class is an abstract base class by having 1 pure virtual function
    bool isWayBlocked();
};


#endif //MEIDL_DARREN_CA2_BUG_H

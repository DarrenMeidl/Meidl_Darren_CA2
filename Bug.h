//
// Created by dmeid on 02/04/2024.
//
#include <iostream>
#include <utility>
#include <list>
#ifndef MEIDL_DARREN_CA2_BUG_H
#define MEIDL_DARREN_CA2_BUG_H


class Bug {
protected: // variables declared as protected (only this class & derived classes can access these)
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
public:
    // Constructor takes in an x & y ints but implements them as a pair
    Bug(int id, int x, int y, int direction, int size)
            : id(id), position(std::make_pair(x, y)), direction(direction), size(size), alive(true) {} // implement these variables, (alive is true by default)
    virtual void move() = 0; // ensures this Bug class is an abstract base class by having 1 pure virtual function
    bool isWayBlocked();
    virtual void printBug() const;
};


#endif //MEIDL_DARREN_CA2_BUG_H

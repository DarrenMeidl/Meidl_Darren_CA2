//
// Created by dmeid on 02/04/2024.
//
#include <iostream>
#include <utility>
#include <list>
#include <string>
#ifndef MEIDL_DARREN_CA2_BUG_H
#define MEIDL_DARREN_CA2_BUG_H

using namespace std;

class Bug {
protected: // variables declared as protected (only this class & derived classes can access these)
    int id;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
public:
    // Constructor takes in an x & y ints but implements them as a pair
    Bug(int id, int x, int y, int direction, int size)
            : id(id), position(make_pair(x, y*-1)), direction(direction), size(size), alive(true) {} // implement these variables, (alive is true by default)
    virtual void move() = 0; // ensures this Bug class is an abstract base class by having 1 pure virtual function
    bool isWayBlocked();
    virtual void printBug() const = 0;
    int getID() const; // used for find by id function
    list<pair<int, int>> getPath() const;
    int getAlive() const; // used in display life history function
    pair<int, int> getPair() const;
    virtual string getName() const = 0;
    int getSize() const;
    void setAlive(bool a);
    void setSize(int size);
};


#endif //MEIDL_DARREN_CA2_BUG_H

//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_CELL_H
#define MEIDL_DARREN_CA2_CELL_H
#include <iostream>
#include <string>
#include <list>
#include "Bug.h"

using namespace std;

class Cell {
public:
    list<Bug*> bugsCellList; // list of Bug* objects called bugsCellList
    int value; // value to determine if this cell is empty, used by 1 or more bugs or out of bounds
    pair<int, int> position;
    string state;
public:
    Cell( int x = 0, int y = 0, int value = 0) : position(make_pair(x, y*-1)), state("empty"), value(value) {} // by default all cells are empty & start at 0,0
    int getValue() const;
    void setValue(int value);
    void printPosition() const;
    void incrementValue(int amount);
    string getState() const;
    void setState(string s);
    // check for conflicts
    void Fight();
};


#endif //MEIDL_DARREN_CA2_CELL_H

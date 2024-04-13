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
private:
    int value; // value to determine if this cell is empty, used by 1 or more bugs or out of bounds
    pair<int, int> position;
    string state;
    list<Bug*> bugsCellList; // list of Bug* objects called bugsCellList
public:
    Cell( int x = 0, int y = 0, int value = 0) : position(make_pair(x, y*-1)), state("empty"), value(value) {} // by default all cells are empty & start at 0,0
    int getValue() const;
    void setValue(int value);
    void printPosition() const;
    void incrementValue(int amount);
    pair<int, int> getPosition() const;
    void setPosition(int x, int y);
    string getState() const;
    void setState(string s);
    // add bug to list
    void addBug(Bug* bug);
    // remove bug from list
    void removeBug(Bug* bug);
    // check for conflicts
    void checkForConflicts();
};


#endif //MEIDL_DARREN_CA2_CELL_H

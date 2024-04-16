//
// Created by dmeid on 16/04/2024.
//

#ifndef MEIDL_DARREN_CA2_FLYER_H
#define MEIDL_DARREN_CA2_FLYER_H


#include "Bug.h" // ensures this derived class properly inherits base class
#include <string>
using namespace std;

class Flyer : public Bug {
private:
    int hopLength;
    string name;
public: // allows the function to be accessible from outside the class hierarchy
    // inherited constructor from base class
    Flyer(int id, int x, int y, int direction, int size, int hopLength)
            : Bug(id, x, y, direction, size), hopLength(hopLength), name("Flyer"){}
    void move() override; // Override the pure virtual function from the base class
    virtual void printBug() const override; // Override the pure virtual function from the base class
    virtual string getName() const override;
};


#endif //MEIDL_DARREN_CA2_FLYER_H

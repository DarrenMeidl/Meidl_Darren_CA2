//
// Created by dmeid on 02/04/2024.
//

#ifndef MEIDL_DARREN_CA2_HOPPER_H
#define MEIDL_DARREN_CA2_HOPPER_H
#include "Bug.h" // ensures this derived class properly inherits base class
#include <string>
using namespace std;

class Hopper : public Bug {
private:
    int hopLength;
    string name;
public: // allows the function to be accessible from outside the class hierarchy
    // inherited constructor from base class
    Hopper(int id, int x, int y, int direction, int size, int hopLength)
            : Bug(id, x, y, direction, size), hopLength(hopLength), name("Hopper"){}
    void move() override; // Override the pure virtual function from the base class
    virtual void printBug() const override; // Override the pure virtual function from the base class
    virtual string getName() const override;
};


#endif //MEIDL_DARREN_CA2_HOPPER_H

//
// Created by dmeid on 02/04/2024.
//

#ifndef MEIDL_DARREN_CA2_HOPPER_H
#define MEIDL_DARREN_CA2_HOPPER_H
#include "Bug.h" // ensures this derived class properly inherits base class

class Hopper : public Bug {
private:
    int hopLength;
public: // allows the function to be accessible from outside the class hierarchy
    // inherited constructor from base class
    Hopper(int id, int x, int y, int direction, int size, int hopLength)
            : Bug(id, x, y, direction, size), hopLength(hopLength) {}
    void move() override; // Override the pure virtual function from the base class
};


#endif //MEIDL_DARREN_CA2_HOPPER_H

//
// Created by dmeid on 02/04/2024.
//

#ifndef MEIDL_DARREN_CA2_CRAWLER_H
#define MEIDL_DARREN_CA2_CRAWLER_H
#include "Bug.h" // ensures this derived class properly inherits base class
#include <string>
using namespace std;

class Crawler : public Bug {
private:
    string name;
public: // allows the function to be accessible from outside the class hierarchy
    // inherited constructor from base class
    Crawler(int id, int x, int y, int direction, int size)
            : Bug(id, x, y, direction, size), name("Crawler"){}
    void move() override; // Override the pure virtual function from the base class
    virtual void printBug() const override; // Override the pure virtual function from the base class
    virtual string getName() const override;
};


#endif //MEIDL_DARREN_CA2_CRAWLER_H

//
// Created by dmeid on 24/04/2024.
//

#ifndef MEIDL_DARREN_CA2_SUPERBUG_H
#define MEIDL_DARREN_CA2_SUPERBUG_H
#include "Bug.h" // ensures this derived class properly inherits base class
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class SuperBug : public Bug {
private:
    string name;
public:
    SuperBug(int id, int x, int y, int direction, int size)
    : Bug(id, x, y, direction, size), name("Super") {}
    void move() override; // Override the pure virtual function from the base class
    void handleInput(sf::Event& event);
    virtual void printBug() const override; // Override the pure virtual function from the base class
    virtual string getName() const override;
};


#endif //MEIDL_DARREN_CA2_SUPERBUG_H

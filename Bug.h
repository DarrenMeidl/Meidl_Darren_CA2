//
// Created by dmeid on 02/04/2024.
//
#include <iostream>
#include <utility>
#include <list>
#ifndef MEIDL_DARREN_CA2_BUG_H
#define MEIDL_DARREN_CA2_BUG_H


class Bug {
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
public:
    virtual void move();
    bool isWayBlocked();
};


#endif //MEIDL_DARREN_CA2_BUG_H

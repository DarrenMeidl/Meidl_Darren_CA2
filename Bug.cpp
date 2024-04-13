//
// Created by dmeid on 02/04/2024.
//

#include "Bug.h"
// Constructor already implemented in header file
using namespace std;

bool Bug::isWayBlocked(){
    // Get current bug position
    int x = position.first;
    int y = position.second;
    // Check if bug is beside edge of the board (0,0 is top left)
    // 1 = up, 2 = right, 3 = down, 4 = left
    if (x == 0 && direction == 4){ // if we're on the very left column and facing left
        return true; // we are blocked
    }
    else if (x == 9 && direction == 2){
        return true;
    }
    else if (y == 0 && direction == 1){
        return true;
    }
    else if (y == -9 && direction == 3){
        return true;
    }
    // otherwise, we're not blocked so return false
    return false;
}

int Bug::getID() const {
    return id;
}

list<pair<int, int>> Bug::getPath() const{
    return path;
}

int Bug::getAlive() const {
    return alive;
}
pair<int, int> Bug::getPair() const{
    return position;
}
int Bug::getSize() const {
    return size;
}
void Bug::setAlive(bool a) {
    this->alive = a;
}
void Bug::setSize(int size){
    this->size = size;
}
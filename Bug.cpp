//
// Created by dmeid on 02/04/2024.
//

#include "Bug.h"
// Constructor already implemented in header file

bool Bug::isWayBlocked(){
    // Get current bug position
    int x = position.first;
    int y = position.second;
    // Check if bug is beside edge of the board (0,0 is top left)
    // 1 = up, 2 = right, 3 = down, 4 = left
    if (x == 0 && direction == 4){ // if we're on the very left column and facing left
        return true; // we are blocked
    }
    if (x == 9 && direction == 2){
        return true;
    }
    return false;
}
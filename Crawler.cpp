//
// Created by dmeid on 02/04/2024.
//

#include "Crawler.h"
void Crawler::move() {
    // Move +1 unit in the direction facing
    // 1 = up, 2 = right, 3 = down, 4 = lef
    if (direction == 1){ // if facing north
        position.second++; // increment the y integer in the pair by 1 i.e. move +1 upwards while keeping x the same
    }
    else if (direction == 2){ // right
        position.first++;
    }
    else if (direction == 3){ // down
        position.second--;
    }
    else if (direction == 4){ // left
        position.first--;
    }
}
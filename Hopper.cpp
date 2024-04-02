//
// Created by dmeid on 02/04/2024.
//
#include <random>
#include "Hopper.h"
using namespace std;

random_device hopper_rd; // Create random number generator called hopper_rd
mt19937 hopper_gen(hopper_rd()); // Seed the generator with a random device

void Hopper::move() {
    int tries = 0;
    const int max = 100; // max tries to find a valid move direction
    int hopCount = hopLength;

    // while we are blocked at the edge of the board before we've started moving
    while (isWayBlocked() && tries < max){
        std::uniform_int_distribution<> dis(1, 4); // declare random integer between 1-4
        direction = dis(hopper_gen); //set direction to that random integer
        tries++; // increment attempts
    }
    // if we're still blocked after 100 attempts before we've started moving, then save our position & end the function early
    if (isWayBlocked()){
        std::cout << "Hopper " << id << " couldn't find a valid direction before moving, staying put." << std::endl;
        // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
        path.emplace_back(position.first, position.second);
        return;
    }
    // While we're not blocked and have hops left (hopLength ranges 2-4 units)
    while (!isWayBlocked() && hopCount >= 1){
        // Begin moving +1 unit in the direction facing
        // 1 = up, 2 = right, 3 = down, 4 = left
        if (direction == 1){ // if facing north
            position.second += 1; // increment the y integer in the pair by 1 e.g. move +1 upwards while keeping x the same
        }
        else if (direction == 2){ // move right
            position.first += 1;
        }
        else if (direction == 3){ // move down
            position.second -= 1;
        }
        else if (direction == 4){ // move left
            position.first -= 1;
        }
        // decrease the hopCount
        hopCount--;
    }
    // if we've hit an edge again during our movement
    // then the loop ends early & we stay put
    // print message to show hopcount vs length, if there were no interruptions then hopcount should be 0
    std::cout << "Hopper " << id << " ended movement with HOPCOUNT: " << hopCount << " and HOPLENGTH" << hopLength << std::endl;
    // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
    path.emplace_back(position.first, position.second);
}

void Hopper::printBug() const {
    cout << "Type: Hopper" << endl;
    Bug::printBug(); // call bug base class print function
    cout << "Hop Length: " << hopLength << endl;
    cout << "" << endl;
}
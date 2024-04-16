//
// Created by dmeid on 16/04/2024.
//

#include <random>
#include "Flyer.h"

using namespace std;

random_device hopper_rd; // Create random number generator called hopper_rd
mt19937 hopper_gen(hopper_rd()); // Seed the generator with a random device

bool Flyer::isWayBlocked(){
    // Get current bug position
    int x = position.first;
    int y = position.second;
    // Check if bug is beside edge of the board (0,0 is top left)
    // 1 = north west, 2 = north east, 3 = south east, 4 = south west
    if (x == 0 && (direction == 4 || direction == 1)){ // if we're on the very left column and facing norht or south left
        return true; // we are blocked
    }
    else if (x == 9 && (direction == 2 || direction == 3)){
        return true;
    }
    else if (y == 0 && (direction == 1 || direction == 2)){
        return true;
    }
    else if (y == -9 && (direction == 3 || direction == 4)){
        return true;
    }
    // otherwise, we're not blocked so return false
    return false;
}

void Flyer::move() {
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
        std::cout << "Flyer " << id << " couldn't find a valid direction before moving, staying put." << std::endl;
        // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
        path.emplace_back(position.first, position.second);
        return;
    }
    // While we're not blocked and have hops left (hopLength ranges 2-4 units)
    while (!isWayBlocked() && hopCount >= 1){
        // Begin moving +1 unit in the direction facing
        // 1 = north west, 2 = north east, 3 = south east, 4 = south west
        if (direction == 1){ // if facing north west
            position.first--;
            position.second++;
        }
        else if (direction == 2){ // move up right
            position.first++;
            position.second++;
        }
        else if (direction == 3){ // move down right
            position.first++;
            position.second--;
        }
        else if (direction == 4){ // move down left
            position.first--;
            position.second--;
        }
        // decrease the hopCount
        hopCount--;
    }
    // Print message based on if we had hops left or not
    if (hopCount == 0) // if we didn't
        cout << "Flyer " << id << " was not interrupted." << endl;
    else // if we did have hops left
        cout << "Flyer " << id << " hit a wall and fell over!" << endl;
    // if we've hit an edge again during our movement
    // then the loop ends early & we stay put
    // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
    path.emplace_back(position.first, position.second);
}

void Flyer::printBug() const {
    string dir; // set the dir string based on direction value
    if (direction == 1)
        dir = "NorthWest";
    else if (direction == 2)
        dir = "NorthEast";
    else if (direction == 3)
        dir = "SouthEast";
    else if (direction == 4)
        dir = "SouthWest";
    // Print the values
    cout << id << " " << name << " " << "(" << position.first << ", " << position.second << ") "
         << size << " " << dir << " " << hopLength << " " << (alive ? "Alive" : "Dead") << endl;
}

string Flyer::getName() const {
    return name;
}


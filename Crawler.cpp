//
// Created by dmeid on 02/04/2024.
//
#include <random>
#include "Crawler.h"
using namespace std;

random_device crawler_rd; // Create random number generator called crawler_rd
mt19937 crawler_gen(crawler_rd()); // Seed the generator with a random device


void Crawler::move() {
    int tries = 0;
    const int max = 100; // max tries to find a valid move direction
    // while we are blocked at the edge of the board
    while (isWayBlocked() && tries < max){
        std::uniform_int_distribution<> dis(1, 4); // declare random integer between 1-4
        direction = dis(crawler_gen); //set direction to that random integer
        tries++; // increment attempts
    }
    // If we're not blocked
    if (!isWayBlocked()){
        // Move +1 unit in the direction facing
        // 1 = up, 2 = right, 3 = down, 4 = left
        if (direction == 1){ // if facing north
            position.second++; // increment the y integer in the pair by 1 i.e. move +1 upwards while keeping x the same
        }
        else if (direction == 2){ // move right
            position.first++;
        }
        else if (direction == 3){ // move down
            position.second--;
        }
        else if (direction == 4){ // move left
            position.first--;
        }
    } else{ // print an error if the crawler can't move after 100 tries
        std::cout << "Crawler " << id << " couldn't find a valid direction, staying put." << std::endl;
    }
    // if crawler couldn't find a way to move, then it simply stays in the same position
    // add current position as a pair to the path list (emplace_back is cleaner looking than "push_back(std::make_pair...."
    path.emplace_back(position.first, position.second);
}
void Crawler::printBug() const {
    string dir; // set the dir string based on direction value
    if (direction == 1)
        dir = "North";
    else if (direction == 2)
        dir = "East";
    else if (direction == 3)
        dir = "South";
    else if (direction == 4)
        dir = "West";
    // Print the values
    cout << id << " " << name << " " << "(" << position.first << ", " << position.second << ") "
         << size << " " << dir << " " << (alive ? "Alive" : "Dead") << endl;
}
string Crawler::getName() {
    return name;
}
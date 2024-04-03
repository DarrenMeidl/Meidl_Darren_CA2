//
// Created by dmeid on 03/04/2024.
//

#include "Cell.h"

int Cell::getValue() const {
    return value;
}
void Cell::setValue(int value) {
    this->value = value;
}
void Cell::printPosition() const {
    cout << "(" << position.first << ", " << position.second << ")";
}
void Cell::incrementValue(int amount) {
    this->value += amount;
    state = "";
}
pair<int, int> Cell::getPosition() const{
    return position;
}
void Cell::setPosition(int x, int y) {
    position.first = x;
    position.second = y;
}
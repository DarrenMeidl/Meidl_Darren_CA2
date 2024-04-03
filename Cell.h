//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_CELL_H
#define MEIDL_DARREN_CA2_CELL_H


class Cell {
private:
    int value; // value to determine if this cell is empty, used by 1 or more bugs or out of bounds
public:
    Cell(int val = 0) : value(val) {} // by default all cells are empty
    int getValue() const;
    void setValue(int value);
};


#endif //MEIDL_DARREN_CA2_CELL_H

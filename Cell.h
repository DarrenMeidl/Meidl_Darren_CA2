//
// Created by dmeid on 03/04/2024.
//

#ifndef MEIDL_DARREN_CA2_CELL_H
#define MEIDL_DARREN_CA2_CELL_H


class Cell {
private:
    int value;
public:
    Cell(int val = 0) : value(val) {} // by default all cells are empty
    int getValue() const;
    void setValue(int v);
};


#endif //MEIDL_DARREN_CA2_CELL_H

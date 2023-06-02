#pragma once

#include "Sort.hpp"

#include <iostream>

class RadixSort : public Sort {
private:
    Point getMaxElement(LinkedList<Point> &vec);
    int calculateNumBits(float angle);
    int digit(float angle, int pos);
    void quicksortB(LinkedList<Point> &vec, const int &left, const int &right, const int &position);

public:
    void sort(LinkedList<Point> &vector) override;
};

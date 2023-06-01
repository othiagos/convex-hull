#pragma once

#include "Point.hpp"
#include "Sort.hpp"

class InsertionSort : public Sort {
  public:
    void sort(LinkedList<Point> &vector) override;
};

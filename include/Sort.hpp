#pragma once

#include "LinkedList.hpp"
#include "Point.hpp"

class Sort {
  public:
    virtual ~Sort();
    virtual void sort(LinkedList<Point> &vector) = 0;
};

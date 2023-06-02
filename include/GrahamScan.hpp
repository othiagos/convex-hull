#pragma once

#include "ArrayStack.hpp"
#include "LinkedList.hpp"
#include "Point.hpp"
#include "Sort.hpp"
#include <iostream>

class GrahamScan {
private:
    Point p0;
    Sort *sort;

    Point nextToTop(ArrayStack<Point> *S);

public:
    GrahamScan(Sort *sort);
    ~GrahamScan();
    LinkedList<Point> *convex_hull(LinkedList<Point> *points);
};

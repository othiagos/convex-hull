#pragma once

#include "LinkedList.hpp"
#include "Point.hpp"
#include "Sort.hpp"
#include <iostream>

class GrahamScan {
private:
    Sort *sort;

    Point nextToTop(LinkedList<Point> &s);

public:
    GrahamScan(Sort *sort);
    ~GrahamScan();
    void convex_hull(LinkedList<Point> points, LinkedList<Point> &result);
};

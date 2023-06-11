#include "GrahamScan.hpp"

GrahamScan::GrahamScan(Sort *sort) {
    this->sort = sort;
}

GrahamScan::~GrahamScan() {
    delete sort;
}

Point GrahamScan::nextToTop(LinkedList<Point> &s) {
    Point p = s[s.size() - 1];
    s.pop_back();
    Point res = s[s.size() - 1];
    s.push_back(p);
    return res;
}

void GrahamScan::convex_hull(LinkedList<Point> points, LinkedList<Point> &result) {
    int ymin = points[0].get_y(), min = 0;
    for (int i = 1; i < points.size(); i++) {
        int y = points[i].get_y();

        if ((y < ymin) || (ymin == y && points[i].get_x() < points[min].get_x())) {
            ymin = points[i].get_y(), min = i;
        }
    }

    Point temp = points[0];
    points[0] = points[min];
    points[min] = temp;

    sort->sort(points);

    int m = 1;
    for (int i = 1; i < points.size(); i++) {
        while (i < points.size() - 1 && Point::orientation(points[0], points[i], points[i + 1]) == 0) {
            i++;
        }

        points[m] = points[i];
        m++;
    }

    if (m < 3) {
        result = {};
        return;
    }

    LinkedList<Point> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);
    stack.push_back(points[2]);

    for (int i = 3; i < m; i++) {
        while (stack.size() > 1 && Point::orientation(nextToTop(stack), stack[stack.size() - 1], points[i]) != 2) {
            stack.pop_back();
        }
        stack.push_back(points[i]);
    }

    while (!(stack.size() == 0)) {
        Point p = stack.pop_back();
        result.push_front(p);
    }
}

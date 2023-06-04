#include "GrahamScan.hpp"

GrahamScan::GrahamScan(Sort *sort) {
    this->sort = sort;
}

GrahamScan::~GrahamScan() {
    delete sort;
}

Point GrahamScan::nextToTop(ArrayStack<Point> *S) {
    Point p = S->top();
    S->pop();
    Point res = S->top();
    S->push(p);
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

    if (m < 3) return;

    ArrayStack<Point> stack;
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (stack.get_size() > 1 && Point::orientation(nextToTop(&stack), stack.top(), points[i]) != 2) {
            stack.pop();
        }
        stack.push(points[i]);
    }

    while (!stack.is_empty()) {
        Point p = stack.pop();
        result.push_front(p);
    }
}

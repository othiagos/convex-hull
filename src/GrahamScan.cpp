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

LinkedList<Point> *GrahamScan::convex_hull(LinkedList<Point> *points) {
    int ymin = points->get_item(0).get_y(), min = 0;
    for (int i = 1; i < points->get_size(); i++) {
        int y = points->get_item(i).get_y();

        if ((y < ymin) || (ymin == y && points->get_item(i).get_x() < points->get_item(min).get_x())) {
            ymin = points->get_item(i).get_y(), min = i;
        }
    }

    Point temp = points->get_item(0);
    points->set_item(points->get_item(min), 0);
    points->set_item(temp, min);

    p0 = points->get_item(0);
    sort->sort(*points);

    int m = 1;
    for (int i = 1; i < points->get_size(); i++) {
        while (i < points->get_size() - 1 && Point::orientation(p0, points->get_item(i), points->get_item(i + 1)) == 0) {
            i++;
        }

        points->set_item(points->get_item(i), m);
        m++;
    }

    if (m < 3)
        return {};

    ArrayStack<Point> stack;
    stack.push(points->get_item(0));
    stack.push(points->get_item(1));
    stack.push(points->get_item(2));

    for (int i = 3; i < m; i++) {
        while (stack.get_size() > 1 && Point::orientation(nextToTop(&stack), stack.top(), points->get_item(i)) != 2) {
            stack.pop();
        }
        stack.push(points->get_item(i));
    }

    LinkedList<Point> *result = new LinkedList<Point>();
    while (!stack.is_empty()) {
        Point p = stack.pop();
        result->push_back(p);
    }
    return result;
}

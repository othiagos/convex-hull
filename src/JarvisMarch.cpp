#include "JarvisMarch.hpp"

LinkedList<Point> *JarvisMarch::convex_hull(const LinkedList<Point> *points) const {
    LinkedList<Point> *hull = new LinkedList<Point>;

    int leftmost_point = 0;
    for (int i = 1; i < points->get_size(); i++) {
        if (points->get_item(i).get_x() < points->get_item(leftmost_point).get_x()) {
            leftmost_point = i;
        }
    }

    int p = leftmost_point, q = 0;
    do {
        hull->push_back(points->get_item(p));

        q = (p + 1) % points->get_size();
        for (int i = 0; i < points->get_size(); i++) {
            if (Point::orientation(points->get_item(p), points->get_item(i), points->get_item(q)) == 2) {
                q = i;
            }
        }

        p = q;

    } while (p != leftmost_point);

    return hull;
}
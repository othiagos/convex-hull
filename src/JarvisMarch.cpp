#include "JarvisMarch.hpp"

void JarvisMarch::convex_hull(LinkedList<Point> &points, LinkedList<Point> &hull) {

    int leftmost_point = 0;
    for (int i = 1; i < points.size(); i++) {
        if (points[i].get_x() < points[leftmost_point].get_x()) {
            leftmost_point = i;
        }
    }

    int p = leftmost_point, q = 0;
    do {
        hull.push_back(points[p]);

        q = (p + 1) % points.size();
        for (int i = 0; i < points.size(); i++) {
            if (Point::orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;

    } while (p != leftmost_point);
}
#include "GrahamScan.hpp"
#include "MergeSort.hpp"
#include "InsertionSort.hpp"
#include "Point.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {

    Point *vec = new Point[]{{27, 11}, {6, 8}, {6, 82}, {19, 82}, {33, 96},
                             {45, 13}, {38, 82}, {6, 22}, {68, 79}, {66, 68}};
    LinkedList<Point> *points = new LinkedList<Point>();
    int n = 10;

    for (int i = 0; i < n; i++) {
        points->push_back(vec[i]);
    }

    GrahamScan gs(new InsertionSort());

    LinkedList<Point> *result = gs.convexHull(*points);

    for (int i = 0; i < result->get_size(); i++) {
        std::cout << '(' << result->get_item(i).get_x() << ',' << result->get_item(i).get_y() << ')' << ' ';
    }
    std::cout << std::endl;

    return 0;
}

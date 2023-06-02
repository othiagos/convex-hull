#include "GrahamScan.hpp"
#include "JarvisMarch.hpp"
#include "MergeSort.hpp"
#include "InsertionSort.hpp"
#include "RadixSort.hpp"
#include "Point.hpp"

#include <iostream>

int main(int argc, char const *argv[]) {

    Point vec[10] {{27, 11}, {6, 8}, {6, 82}, {19, 82}, {33, 96},
                             {45, 13}, {38, 82}, {6, 22}, {68, 79}, {66, 68}};
    LinkedList<Point> points;
    int n = 10;

    for (int i = 0; i < n; i++) {
        points.push_back(vec[i]);
    }

    GrahamScan gs(new RadixSort());
    JarvisMarch jm;

    LinkedList<Point> *result1 = jm.convex_hull(&points);

    LinkedList<Point> *result2 = gs.convex_hull(&points);

    for (int i = 0; i < result1->get_size(); i++) {
        std::cout << '(' << result1->get_item(i).get_x() << ',' << result1->get_item(i).get_y() << ')' << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < result2->get_size(); i++) {
        std::cout << '(' << result2->get_item(i).get_x() << ',' << result2->get_item(i).get_y() << ')' << ' ';
    }
    std::cout << std::endl;

    delete result1;
    delete result2;

    return 0;
}

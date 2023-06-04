#include "GrahamScan.hpp"
#include "InsertionSort.hpp"
#include "JarvisMarch.hpp"
#include "MergeSort.hpp"
#include "Point.hpp"
#include "RadixSort.hpp"
#include "LinkedList.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <unistd.h>

void test(LinkedList<Point> list) {
    list.pop_back();
}

int main(int argc, char **argv) {

    LinkedList<Point> list,  *result = nullptr;
    std::ifstream file;
    Point p;
    std::string line;
    std::istringstream number;
    GrahamScan gs(new MergeSort);
    JarvisMarch jm;
    clock_t t;
    
    int c;
    while ((c = getopt(argc, argv, "f:")) != -1) {
        switch (c) {
        case 'f':
            file.open(optarg);

            if (!file.is_open())
                return -1;

            // list = new LinkedList<Point>;
            while (getline(file, line)) {
                number = std::istringstream(line);

                number >> line;
                p.set_x(std::stoi(line));
                number >> line;
                p.set_y(std::stoi(line));
                list.push_back(p);
            }
            file.close();

            test(list);

            t = clock();
            // result = gs.convex_hull(list);
            t = clock() - t;

            std::cout << "FECHO CONVEXO:" << std::endl;
            for (int i = 0; i < result->get_size(); i++) {
                std::cout << result->get_item(i).get_x() << ' ' << result->get_item(i).get_y() << std::endl;
            }

            // delete list;
            break;

        default:
            break;
        }
    }

    return 0;
}

#include "GrahamScan.hpp"
#include "InsertionSort.hpp"
#include "JarvisMarch.hpp"
#include "LinkedList.hpp"
#include "MergeSort.hpp"
#include "Point.hpp"
#include "RadixSort.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

int main(int argc, char **argv) {

    LinkedList<Point> list, result;
    std::ifstream file;
    std::string line;
    Point p;
    std::istringstream number;

    GrahamScan mergeSort = GrahamScan(new MergeSort);
    GrahamScan insertionSort = GrahamScan(new InsertionSort);
    GrahamScan radixSort = GrahamScan(new RadixSort);
    JarvisMarch jm;
    clock_t times[4];
    clock_t t;

    int c;
    while ((c = getopt(argc, argv, "f:")) != -1) {
        switch (c) {
        case 'f':
            file.open(optarg);

            if (!file.is_open()) {
                std::cout << "Could not open the file!" << std::endl;
                return -1;
            }

            try {
                while (getline(file, line)) {
                    number = std::istringstream(line);

                    number >> line;
                    p.set_x(std::stoi(line));
                    number >> line;
                    p.set_y(std::stoi(line));
                    list.push_back(p);
                }
                file.close();
            } catch (const std::invalid_argument &e) {
                file.close();
                std::cout << "Error read file!" << std::endl;
                break;
            }

            t = clock();
            mergeSort.convex_hull(list, result);
            times[0] = clock() - t;

            result.clear();
            t = clock();
            insertionSort.convex_hull(list, result);
            times[1] = clock() - t;

            result.clear();
            t = clock();
            radixSort.convex_hull(list, result);
            times[2] = clock() - t;

            result.clear();
            t = clock();
            jm.convex_hull(list, result);
            times[3] = clock() - t;

            std::cout << "FECHO CONVEXO:" << std::endl;
            for (int i = 0; i < result.size(); i++) {
                std::cout << result[i] << std::endl;
            }
            std::cout << std::endl;

            std::cout << std::fixed << std::setprecision(3);
            std::cout << "GRAHAM+MERGESORT: " << (float)times[0] / CLOCKS_PER_SEC << 's' << std::endl;
            std::cout << "GRAHAM+INSERTIONSORT: " << (float)times[1] / CLOCKS_PER_SEC << 's' << std::endl;
            std::cout << "GRAHAM+RADIXSORT: " << (float)times[2] / CLOCKS_PER_SEC << 's' << std::endl;
            std::cout << "JARVIS: " << (float)times[3] / CLOCKS_PER_SEC << 's' << std::endl;
            break;

        default:
            break;
        }
    }

    return 0;
}

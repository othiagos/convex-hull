#pragma once

#include "Sort.hpp"
#include "Point.hpp"

class MergeSort : public Sort {
  private:
    void mergeSort(LinkedList<Point> &vector, const int &left, const int &middle, const int &right, const Point &p);

    void sort(LinkedList<Point> &vector, const int &left, const int &right, const Point &p) ;

  public:
    void sort(LinkedList<Point> &vector) override ;
};

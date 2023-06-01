#include "MergeSort.hpp"

void MergeSort::mergeSort(LinkedList<Point> &vector, const int &left, const int &middle, const int &right, const Point &p) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    Point L[n1];
    Point R[n2];

    for (i = 0; i < n1; i++)
        L[i] = vector.get_item(left + i);
    for (j = 0; j < n2; j++)
        R[j] = vector.get_item(middle + 1 + j);

    i = 0;
    j = 0;
    k = left;
    while (i < n1 || j < n2) {
        if (j >= n2 || (i < n1 && L[i].angle(p) < R[j].angle(p))) {
            vector.set_item(L[i], k);
            i++;
        } else {
            vector.set_item(R[j], k);
            j++;
        }
        k++;
    }
}

void MergeSort::sort(LinkedList<Point> &vector, const int &left, const int &right, const Point &p) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        sort(vector, left, middle, p);
        sort(vector, middle + 1, right, p);
        mergeSort(vector, left, middle, right, p);
    }
}

void MergeSort::sort(LinkedList<Point> &vector) {
    sort(vector, 0, vector.get_size() - 1, vector.get_item(0));
}

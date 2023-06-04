#include "RadixSort.hpp"

Point RadixSort::getMaxElement(LinkedList<Point> &vec) {
    Point max = vec[0];
    Point p = vec[0];

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].angle(p) > max.angle(p))
            max = vec[i];
    }
    return max;
}

int RadixSort::calculateNumBits(float angle) {
    int count, angleB = angle * 100;
    for (count = 0; angleB > 0; count++) {
        angleB >>= 1;
    }
    return count;
}

int RadixSort::digit(float angle, int pos) {
    int angleB = angle * 100;
    return (angleB >> pos) & 1;
}

void RadixSort::quicksortB(LinkedList<Point> &vec, const int &left, const int &right, const int &position) {
    int i = left, j = right;
    Point p = vec[0];

    if (right <= left || position < 0)
        return;

    while (j != i) {
        while (digit(vec[i].angle(p), position) == 0 && (i < j))
            i++;
        while (digit(vec[i].angle(p), position) == 1 && (j > i))
            j--;

        Point temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    if (digit(vec[right].angle(p), position) == 0)
        j++;

    quicksortB(vec, left, j - 1, position - 1);
    quicksortB(vec, j, right, position - 1);
}

void RadixSort::sort(LinkedList<Point> &vector) {
    int num_bit = calculateNumBits(getMaxElement(vector).angle(vector[0]));
    quicksortB(vector, 0, vector.size() - 1, num_bit);
}

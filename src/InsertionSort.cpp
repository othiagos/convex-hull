#include "InsertionSort.hpp"

void InsertionSort::sort(LinkedList<Point> &vector) {
    int i, j;
    Point aux, p = vector[0];

    for (i = 1; i < vector.size(); i++) {
        aux = vector[i];
        j = i - 1;

        while (j >= 0 && aux.angle(p) <= vector.get_item(j).angle(p)) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;
    }
}

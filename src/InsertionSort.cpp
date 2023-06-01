#include "InsertionSort.hpp"

void InsertionSort::sort(LinkedList<Point> &vector) {
    int i, j;
    Point aux, p = vector.get_item(0);

    for (i = 1; i < vector.get_size(); i++) {
        aux = vector.get_item(i);
        j = i - 1;

        while (j >= 0 && aux.angle(p) <= vector.get_item(j).angle(p)) {
            vector.set_item(vector.get_item(j), j + 1);
            j--;
        }
        vector.set_item(aux, j + 1);
    }
}

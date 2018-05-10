//
// Created by tony on 09/05/18.
//

#include "BubbleSort.h"

void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void BubbleSort::bubbleSort(int *array, int high) {
    int last = 0;
    bool pasada = true;
    while (pasada) {
        pasada = false;
        for (int i = 1; i < high - last; i++) {
            if (array[i - 1] > (array[i])) {
                swap(array, i, i - 1);
                pasada = true;
            }
        } last += 1;
    }
}
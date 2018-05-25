//
// Created by tony on 09/05/18.
//

#include "BubbleSort.h"

void swap(LinkedList<Song*> *array, int i, int j) {
    Song *temp = array->getIn(i);
    array->editIn(i,array->getIn(j));
    array->editIn(j,temp);
}

void BubbleSort::bubbleSort(LinkedList<Song*> *array, int high) {
    int last = 0;
    bool pasada = true;
    while (pasada) {
        pasada = false;
        for (int i = 1; i < high - last; i++) {
            if (array->getIn(i - 1)->getAlbum().compare(array->getIn(i)->getAlbum()) > 0) {
                swap(array, i, i - 1);
                pasada = true;
            }
        } last += 1;
    }
}
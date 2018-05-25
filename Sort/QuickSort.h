//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_QUICKSORT_H
#define SERVIDORPROYECTO2_QUICKSORT_H

#include "../MusicManager/Song.h"
#include "../Trees/LinkedList.h"

class QuickSort {
public:
    void quickSort(LinkedList<Song*> *array, int low, int high);

};


#endif //SERVIDORPROYECTO2_QUICKSORT_H

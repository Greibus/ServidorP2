//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_BUBBLESORT_H
#define SERVIDORPROYECTO2_BUBBLESORT_H

#include "../Trees/LinkedList.h"
#include "../MusicManager/Song.h"
#include <string>

class BubbleSort {
public:
    void bubbleSort(LinkedList<Song*> *array, int high);

};


#endif //SERVIDORPROYECTO2_BUBBLESORT_H

//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_RADIXSORT_H
#define SERVIDORPROYECTO2_RADIXSORT_H

#include "../MusicManager/Song.h"
#include "../Trees/LinkedList.h"

class RadixSort {
public:
    void radixSort(LinkedList<Song*> *a, int length);

};


#endif //SERVIDORPROYECTO2_RADIXSORT_H

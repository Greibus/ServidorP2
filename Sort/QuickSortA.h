//
// Created by kisung on 28/05/18.
//

#ifndef SERVIDORP2_QUICKSORTA_H
#define SERVIDORP2_QUICKSORTA_H

#include "../MusicManager/Song.h"
#include "../Trees/LinkedList.h"

class QuickSortA {
public:
    void quickSortA(LinkedList<Song*> *array, int low, int high);
};


#endif //SERVIDORP2_QUICKSORTA_H

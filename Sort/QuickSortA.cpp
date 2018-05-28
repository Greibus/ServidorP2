//
// Created by kisung on 28/05/18.
//

#include "QuickSortA.h"

void QuickSortA::quickSortA(LinkedList<Song*> *array, int low, int high)
{
    int i = low;
    int j = high;
    std::string pivot = array->getIn((i + j) / 2)->getArtist();
    Song *temp;

    while (i <= j)
    {
        while (array->getIn(i)->getArtist().compare(pivot)<0)
            i++;
        while (array->getIn(j)->getArtist().compare(pivot)>0)
            j--;
        if (i <= j)
        {
            temp = array->getIn(i);
            array->editIn(i,array->getIn(j));
            array->editIn(j, temp);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSortA(array, low, j);
    if (i < high)
        quickSortA(array, i, high);
}
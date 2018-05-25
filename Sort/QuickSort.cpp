//
// Created by tony on 09/05/18.
//

#include "QuickSort.h"

void QuickSort::quickSort(LinkedList<Song*> *array, int low, int high)
{
    int i = low;
    int j = high;
    std::string pivot = array->getIn((i + j) / 2)->getSongName();
    Song *temp;

    while (i <= j)
    {
        while (array->getIn(i)->getSongName().compare(pivot)<0)
            i++;
        while (array->getIn(j)->getSongName().compare(pivot)>0)
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
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}
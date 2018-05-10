//
// Created by tony on 09/05/18.
//

#include "RadixSort.h"
#include <iostream>
#include <queue>
using namespace std;

int selectDigit (int number, int place)
{ return number/place % 10; }

void RadixSort::radixSort(int a[], int length) {

    const int MAX_DIGIT = 6;
    const int NUM_BINS = 10;
    const int RADIX = 10;
    queue<int> bins[NUM_BINS];

    for (int d = 1, place = 1; d <= MAX_DIGIT; place *= RADIX, ++d) {
        for (int i = 0; i < length; ++i) {
            bins[selectDigit(a[i], place)].push(a[i]);
        }

        int a_pos = 0;
        for (int i = 0; i < NUM_BINS; ++i) {
            while (!bins[i].empty()) {
                a[a_pos++] = bins[i].front();
                bins[i].pop();
            }
        }
    }
}
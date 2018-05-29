//
// Created by tony on 09/05/18.
//
/*
#include "RadixSort.h"
#include <iostream>
#include <queue>
using namespace std;

//// A utility function to get maximum value in arr[]
//long getMax(LinkedList<Song*> arr, int n)
//{
//    long mx = arr.getIn(0)->getArtist().length();
//    for (int i = 1; i < n; i++)
//        if (arr.getIn(i)->getArtist().length() > mx)
//            mx = arr.getIn(i)->getArtist().length();
//    return mx;
//}
//
//// A function to do counting sort of arr[] according to
//// the digit represented by exp.
//void countSort(LinkedList<Song*> *arr, int n, int exp)
//{
////    int output[n]; // output array
//    int i;
//    string count[10] = {0};
//
//    // Store count of occurrences in count[]
//    for (i = 0; i < n; i++)
//        count[i] =  (arr->getIn(i)->getArtist()[exp]) ;
//
//    // Change count[i] so that count[i] now contains actual
//    //  position of this digit in output[]
////    for (i = 1; i < 10; i++)
////        count[i] += count[i - 1];
//
//    // Build the output array
//    for (i = n - 1; i >= 0; i--)
//    {
//        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
//        count[ (arr[i]/exp)%10 ]--;
//    }
//
//    // Copy the output array to arr[], so that arr[] now
//    // contains sorted numbers according to current digit
//    for (i = 0; i < n; i++)
//        arr[i] = output[i];
//}

<<<<<<< Updated upstream
//// The main function to that sorts arr[] of size n using
//// Radix Sort
//void RadixSort::radixSort(LinkedList<Song *> *a, int length) {
//    // Find the maximum number to know number of digits
//    long m = getMax(*a, length);
//
//    // Do counting sort for every digit. Note that instead
//    // of passing digit number, exp is passed. exp is 10^i
//    // where i is current digit number
//    for (int exp = 0; exp < m ; exp ++)
//        countSort(a, length, exp);
//}
=======
// The main function to that sorts arr[] of size n using
// Radix Sort
void RadixSort::radixSort(LinkedList<Song *> *a, int length) {
    // Find the maximum number to know number of digits
    long m = getMax(*a, length);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 0; exp < m ; exp ++)
        countSort(a, length, exp);
}*/

#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop) {
    int minValue = array[start];
    int minIndex = start;
    for (int i = start; i < stop; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
            minIndex = i;
        }
    }
    return minIndex; // modify to return the index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print) {
    // loop through the array
    for (int i = 0; i < size; i++) { 
        if(print) {
            printIntArray(array, size);
        }
        // find the index of the smallest value in the array
        int smallestIndex = findMinimum(array, i, size);
        // swap the smallest value with the current index
        swap(&array[smallestIndex], &array[i]);

    }
    // does not have a return, but sorts array in place. 
    // References used: Grokking Algorithms: Chapter 2, selection sort
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print) {

    for (int i = 0; i < size; i++) {
        int key = array[i];
        int j = i; 
        // while the value of j is greater than 0 (lowest index) and
        // while the value to the left is greater than the key
        // keep swapping with the value to the left
        while(j > 0 && array[j - 1] > key) {
            swap(&array[j-1], &array[j]);
            j = j - 1;
        }
        array[j] = key; // finally set the j index to the value of the key
        if(print) {
            printIntArray(array, size);
        }
    }

}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print) {
    for(int i = 0; i < size; i++) {
        if(print) {
            printIntArray(array, size);
        }
        bool swapped = false;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

// =============== Sort Function ===============
// Name: bubblesort
// param(1): 'arr' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2): 'temp' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will use temporarily.
// param(3)  'l' the start of the first array
// param(4) 'm' the midpoint
// param(5) 'r' the end of the second array
// Output:   No value is returned, but 'arr' should
//           be modified a sorted array.
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int leftSize = m - l + 1; // the size of the left subarray
    int rightSize = r - m; // the size of the right subarray

    int *leftArray = temp; // point to beginning of left
    int *rightArray = temp + leftSize; // uses pointer math to get beginning of R

    // copy using memcpy based on video walkthru. this is more memory efficient 
    // but accomplishes the same thing as looping through and copying
    memcpy(leftArray, arr + l, sizeof(int) * leftSize);
    memcpy(rightArray, arr + m + 1, sizeof(int) * rightSize);

    // merge back together

    int i = 0;    // initialize first subarray index to 0
    int j = 0;    // initialize second subarray index to 0
    int k = l;    // initialize merged subarray to start of left array

    while (i < leftSize && j < rightSize) {
        // if left less than or equal to right
        // then copy left value into arr[k] and inc i
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else { // otherwise, copy the right value and inc j
            arr[k] = rightArray[j];
            j++;
        }
        k++; 
    }

    // if there are still elements in the left, copy into arr
    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    // if there are still elements in the right, copy into arr
    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r) {
   if (l < r) {
        // find the mid point
        // we use this method instead of the more intuitive 
        // m = l + r / 2 because it is more defensive and will 
        // not result in overflow if the ints are large
        int m = l + (r - l) / 2;
        merge_sort(arr, temp, l, m);      // recursively sort through left half
        merge_sort(arr, temp, m + 1, r);  // recursively sort through right half
        merge(arr, temp, l, m, r); // merge sorted sections back together
    }
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif
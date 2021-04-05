#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/*
	Author: Shibaji Paul, shibaji.paul@gmail.complex
	Created for Udemy Course.
*/

/*
  function prototypes
*/


void quickSort(int array[], int lb, int ub);

/**
    
    Description: Helper function for quick sort that will choose the pivot and will place 
    the pivot at exact position where it should be in the sorted array by moving all the
    numbers less than equals pivot to the left and all larger than pivot to the right of 
    the array. Partition performs the task in the range lb:ub, both inclusive.
    lb: lower bound of the array, partition starts from here
    ub: upper bounfd of the array, partition ends at this index.

    Return value: returns the index such that, lb<=index<=ub where it places the pivot.
*/
int partition(int array[], int lb, int ub);

/**
 Description: to check if the array is sorted or not.
 Input Parameters:
    array[]: array of integers
    n: number of elements in the array
    order: for order of sorting, if 1 will check if the array is sorted in ascending
           order, if 0 will check for descending order.
 return value: 1 if the array is sorted as per supplied order, 0 if not.

*/

int isSorted(int array[], int n, int order);

/**
 Description: to input integers from console and assign them into the elements of array
 Input Parameters:
    array[]: array of integers
    n: number of elements in the array
 return value: Nothing

*/
void inputDataFromConsole(int array[], int n);

/**
 Description: To print the content of the array into output console
 Input Parameters:
    array[]: array of integers
    n: number of elements in the array
 return value: Nothing

*/
void printDataToConsole(int array[], int n);

/**
 Description: Randomly generates n integer using the rand function and assigns them
              into the array element.
 Input Parameters:
    array[]: array of integers
    n: number of elements in the array
 return value: Nothing

*/
void fillRandomData(int array[], int n);

/**
    Description: Helper function to get time difference in milli-seconds.
    Input Parameters:
        struct timeval start: start time
        struct timeval end: end time
    Return value: elapsed time in milli sec (float).
*/
float timediff(struct timeval start, struct timeval end);


int * copyArray( int src[], int size);


/*
    Implementation of quick sort
*/

void quickSort(int array[], int lb, int ub){
    if (lb >= ub)
        return;
    int j = partition(array, lb, ub);
    // There are 2 unsorted sections, lb to j-1 and j+1 to ub.
    // Sorting lb to j-1 using quick sort
    quickSort(array, lb, j-1);
    // sorting j+1 to ub using quick sort.
    quickSort(array, j+1, ub);
}

/*
    Implementation of Partition Function.
*/

int partition(int array[], int lb, int ub){
    int down, up, pivot, temp;
    down = lb;
    up = ub;
    pivot = array[lb];
    while(down < up){
        while(array[down] <= pivot && down < ub)
            down++;

        while(array[up] > pivot)
            up--;
        if (down < up){
            temp = array[down];
            array[down] = array[up];
            array[up] = temp;
        }
    }
    // Now place the pivot at index up, so exchange the pivot index(lb) with the up
    array[lb] = array[up];
    array[up] = pivot;
    return up;

}

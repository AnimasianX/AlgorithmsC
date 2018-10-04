/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 3, 2018, 4:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 * Quick Sort algorithm
 * **** quick sort performs slower on sorted input
 * worst case O(n^2)
 * Average case O(nlogn)
 * spacial complexity O(logn)
 */

int partition(int array[], int lower, int upper){
    //in this case of quicksort, we choose the leftmost element to be the pivot
    int pivot = array[lower];
    int down = lower;
    int up = upper;
    
    
    while(down < up){
        //we use (down < upper) to prevent index *down* from exceeding the max array size
        while(array[down] <= pivot && down < upper){
            down++;
        }
        
        while(array[up] > pivot){
            up--;
        }
        //after the while loops, we know that
        //array[down] is greater than the pivot & array[up] is less than the pivot
        //therefore we will swap the two while the indexes are down < up.
        if(down < up){
            int temp = array[down];
            array[down] = array[up];
            array[up] = temp;   
        }
        
    }
    //at the end of the while loop, we have to swap 
    //the elements since our loop terminates
    
    array[lower] = array[up];
    array[up] = pivot;
    return up;
   
}
void quickSort(int array[], int lower, int upper){
    //check if one element or empty
    if(lower >= upper){
        return;
    }
    
    
    int j = partition(array, lower, upper);
    //recursively calls quicksort on subarrays created from partition.
    
    //checks n/2... n/4... and so on until lower>=upper
    //lower bound sorting
    quickSort(array, lower, j-1);
    //upper bound sorting
    quickSort(array, j+1, upper);
    
    
}
void inputDataFromConsole(int array[], int n){
    int i;
    printf("Please enter integer numbers\n");
    printf("You will need to input %d integers in total\n\n", n);
    
    for(i = 0; i < n; i++)
    {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void printDataToConsole(int array[], int n){
    int i;
    printf("Content of array:\n");
    printf("-------------------\n");
    for(i = 0; i < n; i++)
    {
        printf("%6d", array[i]);
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
    printf("\n\n");
}

void fillRandomData(int array[], int n){
    int i;
    srand(time(NULL));
    
    for(i = 0; i < n; i++){
        array[i] = rand() % 10000;
    }
}

float timediff(struct timeval start, struct timeval end){
    return (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec)/ 1000.0f;
}




int main(int argc, char** argv) {

    struct timeval start;
    struct timeval end;
    float elapsed;
    
    
    int n = 100000;
    int upper = n-1;
    int lower = 0;
    int *array = (int *)malloc(sizeof(int) * n);
    if(array == NULL){
        printf("Unable to allocate dynamic memory.\n");
    }
    
    fillRandomData(array, n);
    //printf("Unsorted array: \n");
    //printDataToConsole(array,n);
    
//        if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    gettimeofday(&start, 0);
    quickSort(array,lower, upper);
    gettimeofday(&end,0);
    
    
    
    elapsed = timediff(start,end);
    printf("Time taken to sort %d numbers using Quick sort is: %f msec\n", n, elapsed);
    
    //printDataToConsole(array,n);
    
//    if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    
    return (EXIT_SUCCESS);
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 4, 2018, 4:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 * Merge Sort Algorithm
 * 
 */
//for this function to work, the lists must be sorted from each bound.
void merge(int array[], int temp[], int lower, int mid, int upper){
    int i,j,k;
    for(i = lower, j = mid + 1, k = lower; i <= mid && j <= upper; k++){
        if(array[i] <= array[j]){
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }
        //copy the remaining elements from i to mid bound
        //and copy remaining elements from mid+1 to upper bound
        //** if any **
        while(i <= mid){
            temp[k] = array[i];
            i++;
            k++;
            
        }
        while(j<= upper){
            temp[k] = array[j];
            j++;
            k++;
        }
        //copy back to original array
        for(i = lower; i <= upper; i++){
            array[i] = temp[i];
        }
    
}

void mergeSort(int array[], int temp[],int lower, int upper){
    if(lower >= upper){
        return;
    }
    int mid = (lower + upper)/2;
    
    mergeSort(array, temp, lower, mid);
    mergeSort(array, temp, mid + 1, upper);
    merge(array, temp, lower, mid, upper);
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
    
    
    int n = 10;
    int* array = (int *)malloc(sizeof(int)*n);
    int* temp = (int *)malloc(sizeof(int)*n);
    
    
    if(array == NULL){
        printf("Unable to allocate dynamic memory.\n");
    }
    
    fillRandomData(array, n);
    printf("Unsorted array: \n");
    printDataToConsole(array,n);
    
//        if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    gettimeofday(&start, 0);
    mergeSort(array,temp,0,n-1);
    gettimeofday(&end,0);
    
    
    
    elapsed = timediff(start,end);
    printf("Time taken to sort %d numbers using Merge sort is: %f msec\n", n, elapsed);
    
    printDataToConsole(array,n);
    
//    if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    
    return (EXIT_SUCCESS);
}


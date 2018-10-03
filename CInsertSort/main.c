/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on September 30, 2018, 7:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * Insertion sort
 * Worst case complexity: O(n^2)
 * Best case is O(n) if sorted
 * Memory complexity O(1)
 */



void insertionSort(int array[],int n){
    int i, j, current;
    for(i = 1; i<n; i++){
        current = array[i];
        //This also checks if the array is sorted
        //so the time complexity will be O(n) since it will
        //traverse the array once due to the condition.
        for(j = i - 1; j >= 0 && current < array[j]; j--){
            array[j+1] = array[j];
        }
        array[j+1] = current;
    }
}

int isSorted(int array[], int n, int order){
    int i;
    int sorted = 1;
    //if order is not 0, we check for ascending order
    for(i = 0; i< n-1 && sorted; i++){
        if(order != 0 && array[i] > array[i+1]){
            sorted = 0;
        }
        //if order is 0, we check for descending order
        if(order == 0 && array[i] < array[i+1]){
            sorted = 0;
        }
    }
    return sorted;
    
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
    int *array = (int *)malloc(sizeof(int) * n);
    if(array == NULL){
        printf("Unable to allocate dynamic memory.\n");
    }
    
    fillRandomData(array, n);
    printf("Unsorted array: \n");
    //printDataToConsole(array,n);
    
        if(isSorted(array,n,1)){
        printf("Array is sorted in ascending order\n");
    }
    else{
        printf("Array is not sorted.\n");
    }
    
    gettimeofday(&start, 0);
    insertionSort(array,n);
    gettimeofday(&end,0);
    
    
    
    elapsed = timediff(start,end);
    printf("Time taken to sort %d numbers using selection sort is: %f msec\n", n, elapsed);
    
    //printDataToConsole(array,n);
    
    if(isSorted(array,n,1)){
        printf("Array is sorted in ascending order\n");
    }
    else{
        printf("Array is not sorted.\n");
    }
    
    
    return (EXIT_SUCCESS);
}


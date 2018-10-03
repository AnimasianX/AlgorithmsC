/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on October 3, 2018, 3:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * Shell sort algorithm
 * 
 */

void shellSort(int array[], int n){
    int i,j,gap, current;
    
   for(gap = n/2; gap >=1 ; gap = gap/2)
   {
       for(i = gap; i < n; i++){
           current = array[i];
         for(j = i; j >= gap && current < array[j-gap]; j = j-gap){
           array[j] = array[j - gap];
            }
       array[j] = current;
       
       }
   }
   
}

void shellSortSedgewick(int array[], int n){
    int gap, i, j, k, current;
    int gaps[] = {16577, 4193, 1073, 281, 77, 23, 8, 1};
    
    for(k = 0; k < 8; k++){
        gap = gaps[k];
        for(i = gap; i < n; i++){
            current = array[i];
            for(j = i; j >= gap && current < array[j - gap]; j = j-gap){
                array[j] = array[j - gap];
            }
            array[j] = current;
        }
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

int* copyArray(int src[], int size){
    int i = 0;
    int *dest = (int*)malloc(sizeof(int) * size);
    if(dest == NULL){
        printf("Unable to allocate memory for array copy\n");
    }
    for(i = 0; i < size; i++){
        dest[i] = src[i];
    }
    return dest;
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
    
    
    int n = 20000;
    int *array = (int *)malloc(sizeof(int) * n);
    if(array == NULL){
        printf("Unable to allocate dynamic memory.\n");
    }
    
    fillRandomData(array, n);
    
    int* array2 = copyArray(array,n);
    printf("Unsorted array: \n");
    //printDataToConsole(array,n);
    
        if(isSorted(array,n,1)){
        printf("Array is sorted in ascending order\n");
    }
    else{
        printf("Array is not sorted.\n");
    }
    
    gettimeofday(&start, 0);
    shellSort(array,n);
    gettimeofday(&end,0);
    
    
    
    elapsed = timediff(start,end);
    printf("Time taken to sort %d numbers using shell sort is: %f msec\n", n, elapsed);
    
    //printDataToConsole(array,n);
    
//    if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    
    //printDataToConsole(array,n);
    
//        if(isSorted(array2,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    gettimeofday(&start, 0);
    shellSortSedgewick(array2,n);
    gettimeofday(&end,0);
    
    
    
    elapsed = timediff(start,end);
    printf("Time taken to sort %d numbers using shell sort Sedgewick sequence is: %f msec\n", n, elapsed);
    
    //printDataToConsole(array2,n);
    
//    if(isSorted(array,n,1)){
//        printf("Array is sorted in ascending order\n");
//    }
//    else{
//        printf("Array is not sorted.\n");
//    }
    
    
    return (EXIT_SUCCESS);
}



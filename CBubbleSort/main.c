/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: animasian
 *
 * Created on September 27, 2018, 5:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
/*
 * Bubble Sort
 */

//void bubbleSort(int array[], int n){
//    int sorted = 0;
//    for(int i = 0; i < n-1 && !sorted; i++)
//    {
//        sorted = 1;
//        for(int j = 0; j< n-1-i; j++){
//            if(array[j] > array[j+1]){
//                int temp = array[j];
//                array[j] = array[j+1];
//                array[j+1] = temp;
//                sorted = 0;
//            }
//        }
//    }
//}
//
//int isSorted(int array[], int n, int order){
//    int i;
//    int sorted = 1;
//    //if order is not 0, we check for ascending order
//    for(i = 0; i< n-1 && sorted; i++){
//        if(order != 0 && array[i] > array[i+1]){
//            sorted = 0;
//        }
//        //if order is 0, we check for descending order
//        if(order == 0 && array[i] < array[i+1]){
//            sorted = 0;
//        }
//    }
//    return sorted;
//    
//}
//
//void inputDataFromConsole(int array[], int n){
//    int i;
//    printf("Please enter integer numbers\n");
//    printf("You will need to input %d integers in total\n\n", n);
//    
//    for(i = 0; i < n; i++)
//    {
//        printf("array[%d]: ", i);
//        scanf("%d", &array[i]);
//    }
//}
//
//void printDataToConsole(int array[], int n){
//    int i;
//    printf("Content of array:\n");
//    printf("-------------------\n");
//    for(i = 0; i < n; i++)
//    {
//        printf("%6d", array[i]);
//        if((i+1) % 10 == 0){
//            printf("\n");
//        }
//    }
//    printf("\n\n");
//}
//
//void fillRandomData(int array[], int n){
//    int i;
//    srand(time(NULL));
//    
//    for(i = 0; i < n; i++){
//        array[i] = rand() % 10000;
//    }
//}
//
//float timediff(struct timeval start, struct timeval end){
//    return (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec)/ 1000.0f;
//}
//int main(int argc, char** argv) {
//
//    struct timeval start;
//    struct timeval end;
//    float elapsed;
//    
//    int n;
//    n = 100000;
//    
//    int *array = (int *)malloc(sizeof(int) * n);
//    if(array == NULL){
//        printf("Unable to allocate dynamic memory.");
//        return 1;
//    }
//    
//    fillRandomData(array,n);
//    
//    //printDataToConsole(array, n);
//    
//    printf("Calling bubble sort, please wait...\n");
//    
//    
//    if(isSorted(array, n , 1)){
//        printf("Array is sorted in ascending order\n");
//        
//    }
//    else
//        printf("Array is not sorted in ascending order\n");
//    
//    gettimeofday(&start, 0);
//    bubbleSort(array, n);
//    gettimeofday(&end,0);
//    
//    elapsed = timediff(start, end);
//    printf("Time taken to sort %d numbers using bubble sort is: %f msec\n", n, elapsed);
//    
//    if(isSorted(array, n , 1)){
//        printf("Array is sorted in ascending order\n");
//        
//    }
//    else
//        printf("Array is not sorted in ascending order\n");
//    
//    printf("Sorted array: \n");
//    //printDataToConsole(array, n);
//    
//    
//    
//    
//    free(array);
//    return (EXIT_SUCCESS);
//}


// Sort 

//void bubbleSort(int array[], int n){
//    int sorted = 0;
//    for(int i = 0; i < n-1 && !sorted; i++)
//    {
//        sorted = 1;
//        for(int j = 0; j< n-1-i; j++){
//            if(array[j] > array[j+1]){
//                int temp = array[j];
//                array[j] = array[j+1];
//                array[j+1] = temp;
//                sorted = 0;
//            }
//        }
//    }
//}
//
//int isSorted(int array[], int n, int order){
//    int i;
//    int sorted = 1;
//    //if order is not 0, we check for ascending order
//    for(i = 0; i< n-1 && sorted; i++){
//        if(order != 0 && array[i] > array[i+1]){
//            sorted = 0;
//        }
//        //if order is 0, we check for descending order
//        if(order == 0 && array[i] < array[i+1]){
//            sorted = 0;
//        }
//    }
//    return sorted;
//    
//}
//
//void inputDataFromConsole(int array[], int n){
//    int i;
//    printf("Please enter integer numbers\n");
//    printf("You will need to input %d integers in total\n\n", n);
//    
//    for(i = 0; i < n; i++)
//    {
//        printf("array[%d]: ", i);
//        scanf("%d", &array[i]);
//    }
//}
//
//void printDataToConsole(int array[], int n){
//    int i;
//    printf("Content of array:\n");
//    printf("-------------------\n");
//    for(i = 0; i < n; i++)
//    {
//        printf("%6d", array[i]);
//        if((i+1) % 10 == 0){
//            printf("\n");
//        }
//    }
//    printf("\n\n");
//}
//
//void fillRandomData(int array[], int n){
//    int i;
//    srand(time(NULL));
//    
//    for(i = 0; i < n; i++){
//        array[i] = rand() % 10000;
//    }
//}
//
//float timediff(struct timeval start, struct timeval end){
//    return (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec)/ 1000.0f;
//}
//int main(int argc, char** argv) {
//
//    struct timeval start;
//    struct timeval end;
//    float elapsed;
//    
//    int n;
//    n = 30000;
//    
//    int *array = (int *)malloc(sizeof(int) * n);
//    if(array == NULL){
//        printf("Unable to allocate dynamic memory.");
//        return 1;
//    }
//    
//    fillRandomData(array,n);
//    
//    //printDataToConsole(array, n);
//    
//    printf("Calling bubble sort, please wait...\n");
//    
//    
//    if(isSorted(array, n , 1)){
//        printf("Array is sorted in ascending order\n");
//        
//    }
//    else
//        printf("Array is not sorted in ascending order\n");
//    
//    gettimeofday(&start, 0);
//    bubbleSort(array, n);
//    gettimeofday(&end,0);
//    
//    elapsed = timediff(start, end);
//    printf("Time taken to sort %d numbers using bubble sort is: %f msec\n", n, elapsed);
//    
//    gettimeofday(&start, 0);
//    bubbleSort(array, n);
//    gettimeofday(&end,0);
//    elapsed = timediff(start, end);
//    printf("Time taken to sort %d numbers using bubble sort is: %f msec\n", n, elapsed);
//    
//    //printf("Sorted array: \n");
//    //printDataToConsole(array, n);
//    
//    
//    
//    
//    free(array);
//    return (EXIT_SUCCESS);
//}





//Ascending by using smallest to top instead of largest to bottom
void bubbleSort(int array[], int n){
    int sorted = 0;
    for(int i = 0; i < n-1 && !sorted; i++)
    {
        sorted = 1;
        for(int j = n; j > i; j--){
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                sorted = 0;
            }
            
        }
        for(int k = 0; k < n-1; k++)
        {
            if(array[k] > array[k+1]){
                int temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
                sorted = 0;
            }
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
    
    int n;
    n = 5;
    
    int *array = (int *)malloc(sizeof(int) * n);
    if(array == NULL){
        printf("Unable to allocate dynamic memory.");
        return 1;
    }
    
    fillRandomData(array,n);
    
    printDataToConsole(array, n);
    
    printf("Calling bubble sort, please wait...\n");
    
    
    if(isSorted(array, n , 1)){
        printf("Array is sorted in ascending order\n");
        
    }
    else
        printf("Array is not sorted in ascending order\n");
    
//    gettimeofday(&start, 0);
//    bubbleSort(array, n);
//    gettimeofday(&end,0);
//    
//    elapsed = timediff(start, end);
//    printf("Time taken to sort %d numbers using bubble sort is: %f msec\n", n, elapsed);
//    
//    gettimeofday(&start, 0);
    bubbleSort(array, n);
//    gettimeofday(&end,0);
//    elapsed = timediff(start, end);
//    printf("Time taken to sort %d numbers using bubble sort is: %f msec\n", n, elapsed);
    
    printf("Sorted array: \n");
    printDataToConsole(array, n);
    
    
    
    
    free(array);
    return (EXIT_SUCCESS);
}
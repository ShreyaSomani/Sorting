#include <math.h> 
#include <stdio.h> 
  

void insertionSort(int arr[], int n) 
{ 
    int i, value, hole; 
    for (i = 1; i < n; i++) { 
        value = arr[i]; 
        hole=i;
  
  
        while (hole> 0 && arr[hole-1] > value) { 
            arr[hole] = arr[hole-1]; 
            hole = hole - 1; 
        } 
        arr[hole] = value; 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int arr[] = { 12, 11, 13, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSort(arr, n); 
    printArray(arr, n); 
  
    return 0; 
} 

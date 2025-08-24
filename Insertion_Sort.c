#include<stdlib.h>
#include<stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {

    int arr[] = {45,66,23,12,90,8,21};
    int n= 7;
    
    printf("Before InsertionSort: ");
    print(arr, n);

    insertionSort(arr, n);

    printf("After InsertionSort: ");
    print(arr, n);
    return 0;
}
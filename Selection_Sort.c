#include<stdlib.h>
#include<stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {

    int arr[] = {5, 34, 24, 31, 56, 99, 87};
    int n= 7;

    printf("Before SelectionSort: ");
    print(arr,n);

    selectionSort(arr, n);

    printf("After SelectionSort: ");
    print(arr, n);
    return 0;
}
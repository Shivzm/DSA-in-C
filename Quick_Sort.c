#include <stdio.h>
#include <stdlib.h>

/* Quick Sort (Lomuto partition) - style consistent with your repo */

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof arr / sizeof arr[0];

    printf("Before QuickSort: ");
    PrintArray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("After  QuickSort: ");
    PrintArray(arr, n);

    return 0;
}
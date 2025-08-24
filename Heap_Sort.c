#include <stdio.h>
#include <stdlib.h>

/* Heap Sort (max-heap) - style consistent with your repo */

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/* heapify subtree rooted at i for heap size n */
void Heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    /* build max heap */
    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(arr, n, i);

    /* one by one extract elements from heap */
    for (int i = n - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);    /* move current root to end */
        Heapify(arr, i, 0);        /* heapify reduced heap */
    }
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof arr / sizeof arr[0];

    printf("Before HeapSort: ");
    PrintArray(arr, n);

    HeapSort(arr, n);

    printf("After HeapSort: ");
    PrintArray(arr, n);

    return 0;
}
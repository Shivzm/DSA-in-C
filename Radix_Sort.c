#include <stdio.h>
#include <stdlib.h>

/* Radix Sort (LSD) for non-negative integers - style consistent with your repo */

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int *output = malloc(n * sizeof *output);
    if (!output) { perror("malloc"); exit(1); }
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];

    free(output);
}

void RadixSort(int arr[], int n) {
    if (n <= 1) return;
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof arr / sizeof arr[0];

    printf("Before RadixSort: ");
    PrintArray(arr, n);

    RadixSort(arr, n);

    printf("After  RadixSort: ");
    PrintArray(arr, n);

    return 0;
}
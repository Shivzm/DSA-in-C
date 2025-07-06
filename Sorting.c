#include<stdlib.h>
#include<stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }

            int temp = arr[ min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertionSort(int arr[], int n ) {
     for(int i = 0; i<n; i++) {
        int prev = i-1;
        int curr = i;
        while (prev >= 0 && arr[prev] > arr[curr]) {
            // Swap arr[prev] and arr[curr]
            int temp = arr[prev];
            arr[prev] = arr[curr];
            arr[curr] = temp;
            curr = prev;
            // prev--;
            arr[prev + 1] = arr[prev];
            prev--;
        }
        
        arr[prev + 1] = curr;
     }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n= 7;

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int val;
    int Scount;
} Element;

void printswap(Element arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i].val, arr[i].Scount);
    }
}

void bubsort(Element arr[], int n) {
    int i, j, totalSwaps = 0;
    Element T;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].val > arr[j + 1].val) {
                T = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = T;
                arr[j].Scount++;
                arr[j + 1].Scount++;
                totalSwaps++;
            }
        }
    }

    printf("Bubble Sort - Total swaps: %d\n", totalSwaps);
    printswap(arr, n);
}

void selectionSort(Element arr[], int n) {
    int i, j, MinIn, totalSwaps = 0;
    Element T;

    for (i = 0; i < n - 1; i++) {
        MinIn = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].val < arr[MinIn].val)
                MinIn = j;
        }
        if (MinIn != i) {
            T = arr[i];
            arr[i] = arr[MinIn];
            arr[MinIn] = T;
            arr[i].Scount++;
            arr[MinIn].Scount++;
            totalSwaps++;
        }
    }

    printf("Selection Sort Total swaps: %d\n", totalSwaps);
    printswap(arr, n);
}

int main() {
    Element array1[9] = {{97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0}};
    Element array2[9] = {{90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0}};
    Element array1_copy[9], array2_copy[9];

    // Copy the original arrays
    memcpy(array1_copy, array1, sizeof(array1));
    memcpy(array2_copy, array2, sizeof(array2));

    printf("Bubble sort Array 1: ");
    bubsort(array1, 9);
    printf("\nBubble sort Array 2: ");
    bubsort(array2, 9);

    printf("\nSelection sort Array 1: ");
    selectionSort(array1_copy, 9);
    printf("\nSelection sort Array 2: ");
    selectionSort(array2_copy, 9);

    return 0;
}
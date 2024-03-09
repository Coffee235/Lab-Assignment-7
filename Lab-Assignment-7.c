#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;  
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swaps[arr[i]]++;  // Increment the count for the swapped value
    }
}

void printSwaps(int swaps[], int size) {
    int totalSwaps = 0;
    for (int i = 0; i < size; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d\n", i, swaps[i]);
            totalSwaps += swaps[i];
        }
    }
    printf("Total Swaps: %d\n", totalSwaps / 2);  // Divide by 2 to get half of the total swaps
}

int getMaxValue(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int max1 = getMaxValue(array1, sizeof(array1) / sizeof(array1[0]));
    int max2 = getMaxValue(array2, sizeof(array2) / sizeof(array2[0]));

    int* swaps1_bubble = (int*)calloc(max1 + 1, sizeof(int));
    int* swaps2_bubble = (int*)calloc(max2 + 1, sizeof(int));

    int* swaps1_selection = (int*)calloc(max1 + 1, sizeof(int));
    int* swaps2_selection = (int*)calloc(max2 + 1, sizeof(int));

    printf("array1 bubble sort:\n");
    bubbleSort(array1, sizeof(array1) / sizeof(array1[0]), swaps1_bubble);
    printSwaps(swaps1_bubble, max1 + 1);

    printf("\narray2 bubble sort:\n");
    bubbleSort(array2, sizeof(array2) / sizeof(array2[0]), swaps2_bubble);
    printSwaps(swaps2_bubble, max2 + 1);

    printf("\narray1 selection sort:\n");
    selectionSort(array1, sizeof(array1) / sizeof(array1[0]), swaps1_selection);
    printSwaps(swaps1_selection, max1 + 1);

    printf("\narray2 selection sort:\n");
    selectionSort(array2, sizeof(array2) / sizeof(array2[0]), swaps2_selection);
    printSwaps(swaps2_selection, max2 + 1);

    free(swaps1_bubble);
    free(swaps2_bubble);
    free(swaps1_selection);
    free(swaps2_selection);

    return 0;
}

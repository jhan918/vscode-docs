#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reverseArray(int array[], int size);
int searchElement(int array[], int size, int element);
void calculateStatistics(int array[], int size, float *mean, float *median, int *mode);
void countOddEven(int array[], int size, int *oddCount, int *evenCount);
void calculateSumAverage(int array[], int size, int *sum, float *average);

int main() {
    int choice, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMain Menu\n");
        printf("1. Reverse an array\n");
        printf("2. Search an element in an array\n");
        printf("3. Calculate the Mean, Median, Mode\n");
        printf("4. Count Odd and Even numbers\n");
        printf("5. Sum and Average\n");
        printf("6. EXIT\n");
        printf("Enter your choice, even though he doesn't chose you.eme: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverseArray(arr, size);
                printf("Reversed array: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                int position = searchElement(arr, size, element);
                if (position != -1) {
                    printf("Element found at position: %d\n", position);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;
            }
            case 3: {
                float mean, median;
                int mode;
                calculateStatistics(arr, size, &mean, &median, &mode);
                printf("Mean: %.2f, Median: %.2f, Mode: %d\n", mean, median, mode);
                break;
            }
            case 4: {
                int oddCount, evenCount;
                countOddEven(arr, size, &oddCount, &evenCount);
                printf("Odd numbers: %d, Even numbers: %d\n", oddCount, evenCount);
                break;
            }
            case 5: {
                int sum;
                float average;
                calculateSumAverage(arr, size, &sum, &average);
                printf("Sum: %d, Average: %.2f\n", sum, average);
                break;
            }
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function definitions
void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void calculateStatistics(int arr[], int size, float *mean, float *median, int *mode) {
    int sum = 0, maxCount = 0;
    int count[101] = {0};  // Assuming the elements are between 0 and 100

    // Calculate mean and frequency of elements
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        count[arr[i]]++;
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            *mode = arr[i];
        }
    }
    *mean = (float)sum / size;

    // Calculate median
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        *median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        *median = arr[size / 2];
    }
}

void countOddEven(int arr[], int size, int *oddCount, int *evenCount) {
    *oddCount = 0;
    *evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
    }
}

void calculateSumAverage(int arr[], int size, int *sum, float *average) {
    *sum = 0;
    for (int i = 0; i < size; i++) {
        *sum += arr[i];
    }
    *average = (float)(*sum) / size;

return;
}
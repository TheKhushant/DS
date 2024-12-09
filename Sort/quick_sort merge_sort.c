#include<stdio.h>
#define max 10

void input_array(int[], int);
void print_array(int[], int);
void quick_sort(int[], int, int);
int partition(int[], int, int);
void merge_sort(int[], int, int);
void merge(int[], int, int, int);

void main() {
    int arr[max], n;

    printf("Enter the size of the array (max 10): ");
    scanf("%d", &n);

    if (n > max) {
        printf("Size exceeds maximum limit of %d.\n", max);
        return;
    }

    // Input array
    input_array(arr, n);

    printf("\nBefore sorting:");
    print_array(arr, n);

    // Quick Sort
    quick_sort(arr, 0, n - 1);
    printf("\nSorted by Quick Sort:");
    print_array(arr, n);

    // Input array again for Merge Sort
    printf("\nRe-enter array for Merge Sort:");
    input_array(arr, n);

    // Merge Sort
    merge_sort(arr, 0, n - 1);
    printf("\nSorted by Merge Sort:");
    print_array(arr, n);
}

// Input array function
void input_array(int arr[], int n) {
    int i;
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Print array function
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");
}

// Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index
        quick_sort(arr, low, pi - 1); // Sort left part
        quick_sort(arr, pi + 1, high); // Sort right part
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = low - 1; // Index of smaller element
    int j, temp;

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and pivot
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Merge Sort
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort left and right halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];
    int i, j, k;

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

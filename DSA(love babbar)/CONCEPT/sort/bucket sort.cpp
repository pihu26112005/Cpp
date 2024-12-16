#include <iostream>
using namespace std;

void insertionSort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    int bucketSize = 10; // Assume a bucket size. Adjust based on needs and data analysis.
    float b[n][bucketSize];
    int count[n] = {0}; // To keep track of the number of elements in each bucket

    // Initialize each bucket
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            b[i][j] = 0.0;
        }
    }

    // Place array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        if (count[bi] < bucketSize) {
            b[bi][count[bi]++] = arr[i];
        }
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i], count[i]);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

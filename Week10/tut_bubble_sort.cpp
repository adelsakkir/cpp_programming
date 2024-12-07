#include <iostream>
#include <chrono> // For timing
using namespace std;

// Bubble Sort function for C-style arrays
template <typename T>
void bubble_sort(T A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                T temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Utility function to print a C-style array
template <typename T>
void print_array(const T A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    const int N = 10000; // Array size
    int A[N];

    // Fill the array with a series from 1000 to 1
    for (int i = 0; i < N; i++) {
        A[i] = N - i; // Series in descending order from 1000 to 1
    }

    // cout << "Original array: " << endl;
    // print_array(A, N); // Comment this line if you want to skip printing the entire array

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Perform Bubble Sort
    bubble_sort(A, N);

    // End timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate and display elapsed time in microseconds
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken to sort C++: " << duration.count() << " milliseconds" << endl;

    // cout << "Sorted array: " << endl;
    // print_array(A, N); // Comment this line if you want to skip printing the entire array

    return 0;
}

#include <iostream>
#include <chrono>
using namespace std;

// Bubble Sort function for C-style arrays
extern "C" {
    void bubble_sort(int A[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    // A function to measure time taken for sorting
    extern "C" long long measure_bubble_sort_time(int A[], int size) {
        auto start = chrono::high_resolution_clock::now();
        bubble_sort(A, size);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        return duration.count();
    }
}

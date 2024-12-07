#include <iostream>
#include <chrono>  // Include the chrono library

using namespace std;

int main() {
    int n = 0;

    // Start timing
    auto start = chrono::high_resolution_clock::now();

    // Your original loop
    while (n < 1000000000) {
        n++;
    }

    // Stop timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    chrono::duration<double> elapsed = end - start;

    // Output the elapsed time
    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}

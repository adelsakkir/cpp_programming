#include <iostream>
#include <chrono>
#include <stdexcept>

void function_with_exception() {
    // Function that simulates exception handling overhead
    try {
        throw std::runtime_error("Simulated Exception");
    } catch (const std::exception& e) {
        // Catch and handle the exception (no-op)
    }
}

void function_without_exception() noexcept {
    // Function that does not throw any exceptions
    // No try-catch, no exception handling overhead
    int x = 42;
    int y = 84;
    int result = x + y;  // Some computation
}

int main() {
    const int num_iterations = 1000000;  // Large number of iterations for timing

    // Timing function_with_exception
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        function_with_exception();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time_with_exception = end - start;
    
    // Timing function_without_exception
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        function_without_exception();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time_without_exception = end - start;

    // Output the times
    std::cout << "Time with exception handling: " << elapsed_time_with_exception.count() << " seconds" << std::endl;
    std::cout << "Time without exception handling (noexcept): " << elapsed_time_without_exception.count() << " seconds" << std::endl;

    return 0;
}

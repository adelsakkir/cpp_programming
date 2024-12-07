#include <iostream>
#include <chrono>

// Runtime Fibonacci function (slow for large n)
int fibonacci_runtime(int n) {
    if (n <= 1) return n;
    return fibonacci_runtime(n - 1) + fibonacci_runtime(n - 2);
}

// Compile-time Fibonacci function
constexpr int fibonacci_compile_time(int n) {
    if (n <= 1) return n;
    return fibonacci_compile_time(n - 1) + fibonacci_compile_time(n - 2);
}

int main() {
    int n = 10;  // Fibonacci number to calculate
    constexpr int n2 =10;

    // Measure runtime Fibonacci
    auto start_runtime = std::chrono::high_resolution_clock::now();
    int result_runtime = fibonacci_runtime(n);  // Calculated at runtime
    auto end_runtime = std::chrono::high_resolution_clock::now();
    auto duration_runtime = std::chrono::duration_cast<std::chrono::microseconds>(end_runtime - start_runtime);

    std::cout << "Fibonacci (runtime) result: " << result_runtime << std::endl;
    std::cout << "Runtime Fibonacci duration: " << duration_runtime.count() << " microseconds" << std::endl;

    // Measure compile-time Fibonacci (it will be evaluated at compile time)
    auto start_compile = std::chrono::high_resolution_clock::now();
    constexpr int result_compile = fibonacci_compile_time(n2);  // Computed at compile time
    auto end_compile = std::chrono::high_resolution_clock::now();
    auto duration_compile = std::chrono::duration_cast<std::chrono::microseconds>(end_compile - start_compile);

    std::cout << "Fibonacci (compile-time) result: " << result_compile << std::endl;
    std::cout << "Compile-time Fibonacci duration: " << duration_compile.count() << " microseconds" << std::endl;

    return 0;
}

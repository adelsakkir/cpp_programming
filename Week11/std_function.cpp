#include <iostream>
#include <vector>
#include <functional>

class Add {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};

int multiply(int a, int b) {
    return a * b;
}

int main() {
    std::vector<std::function<int(int, int)>> operations;

    // Store a function pointer, lambda, and function object
    operations.push_back(multiply);
    operations.push_back([](int a, int b) { return a + b; });
    operations.push_back(Add());

    // Apply operations
    for (const auto& op : operations) {
        std::cout << op(3, 4) << std::endl;  // Outputs 12 (multiply), 7 (lambda), 7 (Add)
    }

    return 0;
}

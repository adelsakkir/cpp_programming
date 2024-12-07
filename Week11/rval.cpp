#include <iostream>

int calcVal() {
    return 42;  // Produces an rvalue of type int
}

void process(int&& r) {
    std::cout << "Rvalue reference: " << r << std::endl;
}

void process(const int& r) {
    std::cout << "Lvalue reference: " << r << std::endl;
}

int main() {
    auto&& v1 = calcVal();  // v1 is deduced as int&&
    
    // v1 behaves as an lvalue here:
    process(v1);  // Calls the lvalue overload
    // process(std::move(v1));  // Calls the rvalue overload

    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Class that simulates a resource-heavy object
class LargeObject {
public:
    int val = 15;
    LargeObject() {
        // Simulate a large allocation (e.g., a large array)
        data = new int[10000000];  // 10 million integers
        std::cout << "LargeObject created.\n";
    }

    // Destructor to clean up the allocated memory
    ~LargeObject() {
        delete[] data;
        std::cout << "LargeObject destroyed.\n";
    }

    // Copy constructor (deep copy)
    LargeObject(const LargeObject& other) {
        data = new int[10000000];
        std::copy(other.data, other.data + 10000000, data);
        std::cout << "LargeObject copied.\n";
    }

    // Move constructor (steal data)
    LargeObject(LargeObject&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Leave 'other' in a valid but empty state
        std::cout << "LargeObject moved.\n";
    }

    // Copy assignment operator
    LargeObject& operator=(const LargeObject& other) {
        if (this != &other) {
            delete[] data;  // Release old data
            data = new int[10000000];
            std::copy(other.data, other.data + 10000000, data);
            std::cout << "LargeObject copy-assigned.\n";
        }
        return *this;
    }

    // Move assignment operator
    LargeObject& operator=(LargeObject&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Release old data
            data = other.data;
            other.data = nullptr;  // Leave 'other' in a valid but empty state
            std::cout << "LargeObject move-assigned.\n";
        }
        return *this;
    }

private:
    int* data;  // Simulate large data
};

void test_copy_semantics() {
    std::cout << "\nTesting Copy Semantics\n";
    std::vector<LargeObject> vec;

    // Adding LargeObject using copy
    for (int i = 0; i < 5; ++i) {
        LargeObject obj;
        cout << obj.val << endl;
        vec.push_back(obj);  // This uses the copy constructor
        obj.val= 16;
        cout << "Changed!" << obj.val << endl;
        cout << "In vector -" << vec[i].val << endl;
    }
}

// void test_move_semantics() {
//     std::cout << "\nTesting Move Semantics\n";
//     std::vector<LargeObject> vec;

//     // Adding LargeObject using move
//     for (int i = 0; i < 5; ++i) {
//         LargeObject obj;
//         vec.push_back(std::move(obj));  // This uses the move constructor
//     }
// }

int main() {
    // Measure time for copy semantics
    auto start = std::chrono::high_resolution_clock::now();
    test_copy_semantics();
    auto end = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Copy semantics time: " << copy_duration.count() << " ms\n";

    // Measure time for move semantics
    // start = std::chrono::high_resolution_clock::now();
    // test_move_semantics();
    // end = std::chrono::high_resolution_clock::now();
    // auto move_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout << "Move semantics time: " << move_duration.count() << " ms\n";

    return 0;
}

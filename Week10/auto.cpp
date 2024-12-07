#include <iostream>

int main() {
    float data[10] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.0f};
    auto& v = data;  // v is a reference to the array data
    auto v2 = data;

    // Access elements through v
    v[0] = 0.0f;
    v2[3] = 10;

    // Output elements of data to see the change
    for (int i = 0; i < 10; i++) {
        std::cout << "data[" << i << "] = " << data[i] << std::endl;
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
        std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
    }

    std::cout << sizeof(v)<< std::endl;
    std::cout << sizeof(v2)<< std::endl;

    return 0;
}

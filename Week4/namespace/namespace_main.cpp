// main.cpp
#include <iostream>
#include "namespace_header.h"

// void publicFunction();
// void anotherPublicFunction();

int main() {
    publicFunction();         // Calls function from file1.cpp
    anotherPublicFunction(); // Calls function from file2.cpp
    return 0;
}

// file2.cpp
#include <iostream>
#include "namespace_header.h"

// Unnamed namespace in file2.cpp
namespace {
    int internalVar = 99;

    void internalFunction() {
        std::cout << "This is an internal function in file2.cpp." << std::endl;
    }
}

void anotherPublicFunction() {
    std::cout << "Internal variable from unnamed namespace in file2.cpp: " << internalVar << std::endl;
    internalFunction();
}

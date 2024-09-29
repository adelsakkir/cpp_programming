// file1.cpp
#include <iostream>
#include "namespace_header.h"

// Unnamed namespace in file1.cpp
namespace {
    int internalVar = 42;

    void internalFunction() {
        std::cout << "This is an internal function in file1.cpp." << std::endl;
    }
}

void publicFunction() {
    std::cout << "Internal variable from unnamed namespace: " << internalVar << std::endl;
    internalFunction();
}


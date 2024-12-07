#include <iostream>
using namespace std;

int main() {
    
    float a = 1.3;
    int b = 3;

    auto c = a*b;
    decltype(c)::_;

    return 0;

}

#include <iostream>
using namespace std;

int main() {
    auto fact = [](auto &&self, int n) -> int { 
        return n > 1 ? n * self(self, n - 1) : 1; 
    };
    cout << fact(fact, 10);  // Output: 3628800
    return 0;
}

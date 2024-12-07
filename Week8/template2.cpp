#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// #define INT_MAX 2147483647
// #include <exception>
using namespace std;
template<class T> T& Max(T &x, T &y){
    return x>y?x:y;
}

int main() {
    int a = 3, b =5;
    double c=2.1, d= 3.7;

    cout << "Max of a and b: " << Max(a, b) << endl;
    cout << "Max of c and d: " << Max(c, d) << endl;
    cout << INT_MAX+100 << endl;
}
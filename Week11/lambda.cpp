#include <iostream>
using namespace std;

int main(){
    [](){cout<<"hello";}();
    int n =15;
    [&]()-> float {n++;n++;}();
    cout<<n;
}
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void * operator new(size_t n){
    cout << "Overloaded new " << endl;
    void *ptr = malloc(n);
    return ptr;
}

void* operator new [] (size_t os, int val){
    void* t = malloc(os);

    // for (int i = 0; i < os; ++i) {
    //     *(t+(i*4)) = val;  // Set each integer (4 bytes) to 'value'
    // }
    memset(t, val, os);
    return t;
}


int main(){
    // individual element allocation
    int *p = new int(5);
    cout << "Address of allocated memory: " << p <<endl;
    cout << "Value in allocated memory: " << *p <<endl;

    // array new

    int *q = new (5) int[5];
    q[1]= 5;
    for(int i = 0; i<5; i++){
        cout << "Element" << i+1 << ": "<< *(q+i) << endl;
    }

    delete[] p;

}
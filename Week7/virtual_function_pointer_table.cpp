#include <iostream>
using namespace std;

class A {
    public:
        // virtual void f(int) {}
        int h(A*){cout << "hello A"<< endl;}
};

class B: public A{
    public:
        // void f(int){}
        virtual int h(B*) {cout << "hello B"<< endl;}
};

int main(){
    A a; B b;
    A *pA; B *pB = &b;
    pB->h(&b);
}
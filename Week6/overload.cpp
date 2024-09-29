#include <iostream>
using namespace std;

class A {
    public:
        void f() {cout << "A::f()"<< endl;}
};

class B : public A {
    public:
        using A::f;  //required for clling member function of A
        void f(int i){
            cout << "B::f()"<< endl;
        }
}; 

int main(){
    B b;
    b.f(3);
    b.f();
}
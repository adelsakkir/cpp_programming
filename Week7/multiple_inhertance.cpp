#include <iostream>
using namespace std;

class Base1 {
    public:
        void h(double j){
            cout << "B1::h()"<< endl;
        }
};

class Child : public Base1 {
    public:
        // using Base1::h;
        void h(int i){
            cout << "C::h()"<< endl;
        }
};

int main(){
    Base1 b; Child c;

    int i_ = 10;
    double j_ =15.46;
     c.h(j_);
    c.Base1::h(j_);
}
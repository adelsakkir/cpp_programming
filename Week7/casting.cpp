#include <iostream>
using namespace std;

class A { 
    public :
        int i_;

        A(int i = 15) : i_(i) {};

};

class B: public A {
    public:
        int j_;
        B(int j) : j_(j) {};
};


int main(){
    A a;
    B b(10);

    
    cout<< a.i_ << endl;
    cout<< b.i_ << endl;
    cout<< b.j_ << endl;

    A *pb = &b;
    cout<< pb->i_ << endl;
    cout<< pb->j_ << endl;

}


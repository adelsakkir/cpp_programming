#include <iostream>
using namespace std;

class B {
    public:
        int i_, j_;

        B(int i, int j): i_(i), j_(j) {}
        virtual void print() {cout << "B::print()"<<endl;}
};

class D: public B {
    public:
        int k_;

        D(int i, int j, int k): B(i,j), k_(k) {}
        virtual void print() {cout << "D::print()"<<endl;}
};

int main(){
    // B b(3,4);
    // D d(12, 15 ,10);

    B *p = new B(7,8);
    B *q = new D(5,6,7);

    // cout << b.i_ << b.j_ << endl;
    // cout << d.k_ <<endl;
    cout << q->i_ << endl;
    p->print();
    q->print();
}
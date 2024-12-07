#include <iostream>
using namespace std;

class A {
    public:
        virtual ~A(){}

};

class B: public A {

};

class C {
    public:
        virtual ~C(){}

};

int main (){
    int i =10;
    double d;
    double d2;

    d=i;
    d2 =static_cast<double>(i);

    cout << i << endl;
    cout << d << endl;
    cout << d2 << endl << endl;

    const int j =3;
    int* pj = const_cast<int*>(&j); // &j give const * int, we convert it to int *
    *pj = 6;
    cout << j<< " " << *pj <<endl; // compiler creates new object with new address

    cout<< "Next Section!" <<endl;

    A a; B b; C c;
    B* pB = &b;
    A* pA = dynamic_cast<A*>(pB);
    cout << pB << " casts to " << pA << ": Upcast Valid! " << endl;

}
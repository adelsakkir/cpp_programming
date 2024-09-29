#include <iostream>
using namespace std;

class A {public: int i;};
class B {public:  double d;};

int main(){
    A a;
    B b;
    a.i = 5;
    b.d = 7.2;

    A *p = &a;
    B *q = &b;

    p->i = 15;

    p = (A*)&b;
    q = (B*)&a;

    cout << "Int value of class B: " << p->i << endl;
    cout << "Int value of a: " << a.i << endl;
}






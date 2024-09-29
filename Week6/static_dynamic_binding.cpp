#include <iostream>
using namespace std;

class B {
    public:
        void f() {cout << "B::f()"<< endl;}
        virtual void g() {cout << "B::g()" <<endl;}
};

class D : public B {
    public:
        void f(){cout << "D::f()"<< endl;}
        virtual void g() {cout << "D::g()" <<endl;}
}; 

int main(){
    B b;
    D d;

    B *ptrB = &b;
    B *ptrD = &d; // UPCAST D ISA B

    b.f(); //static
    b.g(); //static
    d.f(); //static
    d.g(); //static 
    
    cout << "Second section !!"<< endl;

    ptrB->f();
    ptrB->g();
    ptrD->f();
    ptrD->g(); //virtual function gets dynamically bound, i.e., since ptrD is is defined as a B object, 
                //it checks in B if g() is virtual, since it is, it uses the definition of the actaul object ptrD is pointing to, which is a D objects


}
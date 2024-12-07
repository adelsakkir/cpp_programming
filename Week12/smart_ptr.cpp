#include <iostream>
#include <memory>
using namespace std;

struct Foo{
    Foo() {cout<<"Foo::Foo\n";}
    ~Foo() {cout<<"Foo::~Foo\n";}
    void bar() {cout << "Foo::bar\n";}
};

int main(){
    unique_ptr<Foo> p1 = make_unique<Foo>();
    // unique_ptr<Foo> p1(new Foo);
    // unique_ptr<Foo> p1 = new Foo;
    if (p1) p1->bar();
    {
        unique_ptr<Foo> p2(move(p1));
        p1 = move(p2);
    }
}
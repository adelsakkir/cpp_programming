#include <iostream>
#include <exception>
using namespace std;


class MyException: public exception {};
class MyClass {public: ~MyClass() {}};

void h() {
    MyClass h_a;

    // throw 1;
    // throw 2.5;
    throw MyException();
    throw exception();
    throw MyClass();

}

void g(){
    MyClass g_a;
    try{
        h();
        bool okay = true;
    }
    catch(int) { cout<< "int\n";}
    catch(double) {cout << "double\n";}
    // catch(...) {throw;}
}

void f(){
    MyClass f_a;
    try{
        g();
        bool okay = true;
    }

    catch(MyException) { cout<< "MyException\n";}
    catch(exception) {cout << "exception\n";}
    catch(...) {throw;}
}

int main() {
    try {f();
    bool okay =true;
    }
    
    catch(...) {cout << "Unknown\n";}
}
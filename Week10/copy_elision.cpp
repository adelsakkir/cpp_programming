#include <iostream>
using namespace std;

int n =0;
struct C{
    int i;
    C():i(0){}
    explicit C(int i): i(i){cout<< i << ' ';}
    C(const C& c): i(c.i) {cout<< ++i << ' '; ++n;}
    C& operator=(const C& c){
        i=c.i;
        cout<< "hello" <<++i << ' '; ++n;}
    // C(const C&) = delete;
    ~C() {cout << "~" << i << ' ' ;}
};

int main(){
    C c1(42);
    C c2 = C(77); // since c2 is not created yet, copy constructor will get called, not operator=(), compiler sees this as C c2(77)
    // C c2;
    // c2 = C(77);
    C c3 = c1; //lvalue
    cout<< n << endl;
    // cout << c2.i <<endl;
}

//"use of deleted function 'C::C(const C&)'",
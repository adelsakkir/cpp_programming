#include <iostream>
using namespace std;

extern void (*func)();
void g(); 

void f(){
    cout<< "Hi" << endl;
}

int main(){
    func = &f;
    g();
}

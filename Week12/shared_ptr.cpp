#include <iostream>
#include <memory>
using namespace std;

int main(){
    shared_ptr<int> p1 = make_shared<int>();
    // shared_ptr<int> p1(new int);
    *p1 =72;
    cout<< "p1 RC = " << p1.use_count()<< endl;
    shared_ptr<int> p2(p1);
    cout<< "p1 RC = " << p1.use_count()<< endl;
    cout<< "p2 RC = " << p2.use_count()<< endl;
    p1.reset();
    cout<< "p1 RC = " << p1.use_count()<< endl;
    cout<< "p2 RC = " << p2.use_count()<< endl;

}
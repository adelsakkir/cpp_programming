#include <iostream>
#include <memory>

using namespace std;

weak_ptr<int> gw;

void f(){
    // cout << *gw << "\n";
    if (auto spt = gw.lock()){ //copied into shared ptr before use
        cout << *spt << "\n";
    }
    else {cout<< "gw is expired!";}
}

int main(){
    {
        auto sp = make_shared<int>(42);
        gw = sp;
        f();
    }
    f();
}


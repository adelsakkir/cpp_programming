#include <iostream>
using namespace std;

class X{
    public:
    ~X(){delete p;}
    private: int *p;
};

int main(){
    X x1;
    X x2(x1);
}
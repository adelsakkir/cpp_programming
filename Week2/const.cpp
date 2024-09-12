#include <iostream>
using namespace std;
 
int main(){
    int m = 5, n=2;
    int const *p = &m;
    p=&n;
}


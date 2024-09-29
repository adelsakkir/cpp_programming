#include <iostream>
using namespace std;

int a= 300;

namespace adel {
    int a =3;
    int b= 5;
}

namespace nihal {
    int a = 10;
    int b =15;
}

// using namespace nihal;
// using namespace adel;


int main(){
    using adel::a;
    cout << a<< endl;
    cout << ::a<< endl;
}

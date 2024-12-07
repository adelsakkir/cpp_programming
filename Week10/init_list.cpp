#include <iostream>
using namespace std;

class Widget{
    public:
        int data;
        explicit Widget(int a): data{a}{};
};

Widget w1(10);
Widget w2{10};
// Widget w3 = w2;
// Widget w4 ={10};
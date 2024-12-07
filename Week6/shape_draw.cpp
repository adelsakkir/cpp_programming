#include <iostream>
using namespace std;

class Shapes {
    public:
        virtual void draw() = 0;
};

class Triangle: public Shapes {
    public:
        void draw() {cout << "Triangle draw!" << endl;}
};

class Circle: public Shapes {
    public:
        void draw() {cout << "Circle draw!" << endl;}
};

int main() {
    Shapes *arr[] ={new Triangle, new Circle};

    for (int i =0; i<sizeof(arr)/sizeof(Shapes*); ++i){
            arr[i] -> draw();
    }
}
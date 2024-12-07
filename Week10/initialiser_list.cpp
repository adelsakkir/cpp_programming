#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class MyClass{
    public:
        vector<int> data;

        MyClass(initializer_list<int> list): data({list}){
            // for (int value:list){
            //     data.push_back(value);
            // }
            show();
        };

        MyClass(int i, initializer_list<int> list): data{list}{
            show();
        };

        void show(){
            for (auto first = data.begin(); first!=data.end();first++){
                cout<<*first<< endl;
            }
        };
};

int main(){
    auto a = {1,2,3,4};
    MyClass obj = {a};
    MyClass obj2 = a;
    MyClass obj3 = {10, a};
    
}


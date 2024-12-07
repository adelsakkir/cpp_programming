#include <iostream>
#include <algorithm> //for_each
#include <functional> //std::function
#include <vector>

using namespace std;

struct machine{
    vector<function<int(int)>> to_do;

    template<typename T>
    void add(T f){
        to_do.push_back(f);
    }

    int run(int v){
        for_each(to_do.begin(), to_do.end(), [&v](std::function<int(int)> f){ v= f(v);});
        return v;
    }
};

int foo(int i){
    return i+5;
}

int main(){
    machine m;
    m.add([](int i){return i*3;});
    m.add(foo);
    m.add([](int i){return i/5;});

    cout<< m.run(15) << endl;

}



#include <iostream>
using namespace std;
#include <vector>

template <class T>
T find (const vector<T> arr, const T &element){
    for (int i =0; i< arr.size(); ++i){
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
};

int main(){
    vector<int> vec = {10, 20, 30, 40};
    int search_val = 90;
    int out = find<int>(vec, search_val);
    cout << "Search Log: " << out; 

}
#include <iostream>
using namespace std;
 
int main(){
    int i = 5;
    int &j = i;
    const int& k =5;
    const int& l = j+k;

    cout << i << ", " << &i << endl; 
    cout << j << ", " << &j << endl; 
    cout << k << ", " << &k << endl; 
    cout << l << ", " << &l << endl; 

    j=6;

    cout << "After updation!" << endl;
    cout << i << ", " << &i << endl;  
    cout << j << ", " << &j << endl; 
    cout << k << ", " << &k << endl; 
    cout << l << ", " << &l << endl; 


}


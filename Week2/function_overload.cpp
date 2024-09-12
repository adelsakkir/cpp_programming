#include <iostream>
using namespace std;

int& addi(int *a){
    // cout << "x= " << " &x = "<< &x << endl;
    // int k = 60;
    return *a;
}
 
int main(){
    int b = 10;
    int c= addi(&b);
    cout << "c= " << c<< endl;
    return c;

}
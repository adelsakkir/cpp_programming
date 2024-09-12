#include <iostream>
using namespace std;

int& addi(int &x){
    cout << "x= " << " &x = "<< &x << endl;
    int k = 60;
    return(x);
}
 
int main(){
    int a=10;
    const int c= 15;
    cout << "a= " << " &a = "<< &a << endl;
    const int& b= addi(a);
    cout << "b= " << " &b = "<< &b << endl;

    const int *m = &c;

}
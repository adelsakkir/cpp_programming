#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main(){
    char str[12]= "Adelisgod@1";
    stack<char> s;

    for(int i=0;i<strlen(str);i++){
        s.push(str[i]);
    }

    cout << "Reversed String:";
    while(!s.empty()){
        cout << s.top(); s.pop();
    }
}

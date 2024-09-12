#include <iostream>
#include<cstring>
#include<stack>
using namespace std;

int main(void){
    stack<int> s;
    char str[] = "123*+4-";

    for(int i =0; i < strlen(str); i++){
        s.push(str[i]-'0');
    }

    int out;
    for(int i =0; i < strlen(str); i++){
        if (isdigit(str[i])){s.push(str[i]-'0');}
        else{
            switch (str[i])
            {
            case '+': 
            out = s.top(); s.pop(); out += s.top(); s.pop(); s.push(out); break;
            case '*': 
            out = s.top(); s.pop(); out *= s.top(); s.pop(); s.push(out); break;
            case '-': 
            out = s.top(); s.pop(); out -= s.top(); s.pop(); s.push(-1*out); break;
            case '/': 
            out = s.top(); s.pop(); out /= s.top(); s.pop(); s.push(out); break;

            }
        }
    }
    cout << s.top();
}

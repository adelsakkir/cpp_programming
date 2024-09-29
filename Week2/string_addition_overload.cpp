#include <iostream>
#include <cstring>
using namespace std;
#include <malloc.h>  // For _msize

struct String{char *str;};

String operator+(String& s1, String& s2){
    String s;
    
    // s.str = new char[strlen(s1.str) + strlen(s2.str) + 1]; 
    s.str = new char[100000];
    size_t allocated_size = _msize(s.str);
    cout << "Size of new string1: " << allocated_size << endl;
    strcpy(s.str, s1.str);
    strcat(s.str, s2.str);

    // String a;
    // a.str = strdup(s1.str);
    // strcat(a.str, s2.str);

    // cout << "Full Name: " << a.str << endl;
    // size_t allocated_size2 = _msize(a.str);
    // cout << "Size of new string2: " << allocated_size2 << endl;
    // cout << "Size of new string2: " << sizeof(a.str) << endl;
    return s;

} 
int main(){
    String fname;
    String lname;
    String name;
    // char *name;

    fname.str = strdup("Adel");
    lname.str = strdup("Sakkir");
    name = fname + lname;

    cout << "First Name: " << fname.str << endl;
    cout << "Last Name: " << lname.str << endl;
    cout << "Full Name: " << name.str << endl;


}
#include <iostream>
#include <cstring>
using namespace std;

class String {
    public:
        char* str_;
        size_t len_;

        // Constructor 
        String(const char*s): str_(strdup(s)), len_(strlen(s)){}

        // copy constructor
        String(const String& s) : str_(strdup(s.str_)), len_(s.len_){}

        // assignment constructor
        ~String() { 
            cout << "Dtor: " << str_ << endl;
            free(str_);}

        String& operator=(const String& s){
            free(str_);
            str_ = strdup(s.str_);
            len_ = s.len_;
            return *this;
        }
        void print() {cout << "(" << str_ << ": " << len_ << ")" <<endl; }
};

int main(){
    String s1("Football"), s2("Cricket"); s1.print(); s2.print(); s2 = s1; s2.print(); s1.print();
}
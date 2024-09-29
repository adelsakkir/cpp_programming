#include <iostream>
#include <cstring>
using namespace std;

class String_{
    size_t len_;
    char* str_;
    

    public:
        String_(const char*s) : str_(strdup(s)) , len_(strlen(str_)) {cout << "ctor: "; print(); }
        ~String_() {cout << "dtor: "; print(); free(str_);}
        void print() {cout << "(" <<str_ << ": "<< len_ <<") "<<endl;}
};

int main(){
    String_ s("Partha");
    s.print();
}
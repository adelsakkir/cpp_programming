#include <iostream>
#include <cstring>
using namespace std;


class String{
    public: 
        char *str_;
        size_t len_;

        String(const char *s): str_(strdup(s)), len_(strlen(str_)) {}

        //copy constructor
        String(const String& s): str_(strdup(s.str_)), len_(s.len_){}
        ~String(){
            cout << "Dtor: " << str_ << endl;
            free(str_);
        }

        void print(){
            cout << "(" << str_ << ": " <<len_ << ")" <<endl;
        }
};

void strToUpper(String a){// copy constructor called
    for (int i =0; i<a.len_;++i){
        a.str_[i] = toupper(a.str_[i]);
    }
    cout <<"strToUpper:  "; a.print();

}
int main(){
    String s = "Partha"; s.print(); strToUpper(s); s.print();
}
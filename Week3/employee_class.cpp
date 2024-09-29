#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class Employee {
    private:
    string name;
    string address;
    double sal_fixed;
    double sal_variable;

    public:
    Employee() {sal_fixed = 1200; sal_variable = 10;} // intialise
    string get_name(){return name;}
    void set_name(string name){this->name = name;}
    void set_addr(string address)  {(*this).address = address;}
    double get_sal_fixed(){return sal_fixed;}
    double salary(){return sal_fixed + sal_variable;}


};


int main(){
    Employee e1; e1.set_name("Ram"); e1.set_addr("Kolkata");
    cout << e1.get_name() << endl; 
    cout << e1.get_sal_fixed() <<endl << e1.salary() << endl;

}
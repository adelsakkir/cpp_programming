#include <iostream>
#include <string>
using namespace std;

class Engineer {
    protected:
        int salary;
    public:
        string name;
        Engineer(string s ="Nihal"): name(s){}
        void set_salary(int sal){
            salary = sal;
        }

        virtual void get_salary(){
            cout << "Engineer Salary: " << salary <<endl;
        }
};

class Manager: public Engineer {
    public:
        Manager(string s): Engineer(s){}
        // void set_salary(int sal){
        //     salary = sal;
        // }

        void get_salary(){
            cout << "Manager Salary: " << salary << endl;
        }
};

int main(){
    Engineer e1("Adel");
    Manager e2("Sakkir");

    Engineer* pE = &e1;
    Engineer* pM = &e2;

    pE->set_salary(1000);
    pM->set_salary(1000);

    pE->get_salary();
    pM->get_salary();

    cout << pE->name << endl;
    cout << pM->name << endl;

}
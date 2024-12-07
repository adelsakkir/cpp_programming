#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee{
    protected:
        string name_;
        vector <Employee*> reports;
    public:
        virtual void ProcessSalary() =0;
        virtual ~Employee(){}
        static vector<Employee*> staffs;
        void AddStaff(Employee* e){staffs.push_back(e);};

};

class Engineer : public Employee {
    public:
        Engineer(const string& name){name_ = name; AddStaff(this);}
        void ProcessSalary() {cout << name_ << ": Process Salary for Engineer"<< endl;}
};

class Manager : public Engineer {
    public:
        Manager(const string& name): Engineer(name){}
        void ProcessSalary(){
            cout << name_ << ": Process Salary for Manager"<< endl;
        }
};

class Director : public Manager {
    public:
        Director(const string& name): Manager(name){}
        void ProcessSalary(){
            cout << name_ << ": Process Salary for Director"<< endl;
        }
};

class Sales : public Employee{
    public:
        Sales(const string& name) {name_= name; AddStaff(this);}
        void ProcessSalary(){
            cout << name_ << ": Process Salary for SALES"<< endl;
        }
};

vector<Employee*>Employee::staffs;

int main(){
    Engineer e1("Adel"), e2("Fathima"), e3("Shibi");
    Manager m1("Kamala"), m2("Rajiv");
    Sales s1("Hari"), s2("Imbrahim");
    Director d("Chacko");

    vector<Employee*>::const_iterator it;

    for(it =Employee::staffs.begin(); it < Employee::staffs.end(); ++it){
        (*it)->ProcessSalary();
    }
}

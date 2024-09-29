#include <iostream>
using namespace std;

class Primeminister{
    int age_;
    Primeminister(int age): age_(age) {
        cout << "Prime Minister elected! " <<endl;
    }

    // static Primeminister *elected;

    public:

    // Access function
    static const Primeminister& pm(int age =50){
        // if (!elected){elected = new Primeminister(age);}
        // elected = new Primeminister(age);
        static Primeminister elected(age); // not executed the second time
        // return *elected;
        return elected;
    }
    void print() const { cout << "Primeminister age set!: "<< age_ <<endl;}

};

// pointer to Prime minister,  pointer 
// Primeminister * Primeminister::elected = 0;

int main(){
    int age1 =50, age2 =60;
    Primeminister::pm(age1).print();
    Primeminister::pm(age2).print();
}

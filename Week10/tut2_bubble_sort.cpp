#include <iostream>
#include <chrono> // For timing
using namespace std;

// int nCtor =0 ;
// int nC_Ctor = 0;
// int nDtor = 0;

struct R {
    int i;
    R(int i): i(i){nCtor++;}
    R(const R& r): i(r.i){nC_Ctor++;}
    ~R(){++nDtor;}

    static unsigned int nCtor;
    static unsigned int nC_Ctor;
    static unsigned int nDtor;
};

struct D{
    R* r;
    D(): r(nullptr){}
    D(int i): r(new R(i)){} // parametric constructor
    D(const D& d): r(new R(*(d.r))){} //copy constructor
    D& operator=(const D& d){
        // cout<<"=Ctor"<< " ";
        if (this!=&d){
            delete r;
            r= new R(*(d.r));
        }
        return *this;
    }
    ~D(){delete r;}
    friend bool operator>(const D& c1, const D& c2){
        return c1.r->i > c2.r->i;
    }

    friend ostream& operator<<(ostream& os, const D& d){
        os << d.r->i << ' ';
        return os;
    }
};

template<typename T>
void swap1(T& a, T&b){
    T t = a; //copy created from a
    a=b; //copy-assigned from b
    b=t; //copy-assigned from t
}

template <typename T>
void bubble_sort(T A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap1(A[j], A[j+1]);
            }
        }
    }
}

// Utility function to print a C-style array
template <typename T>
void print_array(const T A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
unsigned int R::nCtor = 0;
unsigned int R::nC_Ctor =0 ;
unsigned int R::nDtor= 0;

struct Stat{
    Stat(){cout << "Program Start: " << "R obj Created = "<< R::nCtor << " R obj Copy Created = " << R::nC_Ctor << " R obj Destroyed = " << R::nDtor << endl;}
    ~Stat(){cout << "Program End: " << "R obj Created = "<< R::nCtor << " R obj Copy Created = " << R::nC_Ctor << " R obj Destroyed = " << R::nDtor << endl;}
} extremeStat;


int main(){
    const int N =10;
    D arr[N];

    for (int i = N-1; i >=0;--i){
        arr[i] = D(N-i);
    }
    cout << "After Init: " << "R obj Created = "<< R::nCtor << " R obj Copy Created = " << R::nC_Ctor << " R obj Destroyed = " << R::nDtor << endl;
    print_array(arr, N);
    bubble_sort(arr, N);
    cout << "After Sort: " << "R obj Created = "<< R::nCtor << " R obj Copy Created = " << R::nC_Ctor << " R obj Destroyed = " << R::nDtor << endl;
    print_array(arr, N);
    
}
// cout << "After Program : " << "R obj Created = "<< nCtor << " R obj Copy Created = " << nC_Ctor << " R obj Destroyed = " << nDtor << endl;

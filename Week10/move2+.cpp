#include <iostream>
#include <cstring>
#include <vector>
#include <chrono>

using namespace std;

// Resource Management class to track Creation and release of resources
class ResMgr{
    static unsigned int nCreated, nReleased;

    public:
        ResMgr(){}
        ~ResMgr(){
            cout << "\n\n Resources Created = " << nCreated <<endl;
            cout << "\n\n Resources Released = " << nReleased <<endl;
        }

        inline static char *Create(const char*s)
        {return ((s) ? ++nCreated, strdup(s) :nullptr);} // If s is not null, copy and increment counter 

        inline static void Release(char*s) // If s is not null, increment counter and release the resource 
        {(s) ? free(s) , ++nReleased: 0;}

        inline static void Stat()
        {cout << "Stat = (" << nCreated <<", " << nReleased << ")\n\n";}
};

class MyResource{
    char *str =nullptr;
    public:
        MyResource(const char* s = nullptr) : str(ResMgr::Create(s)) //Param and default constructor
        {cout <<"Ctor[R] ";}

        MyResource(const MyResource& s): str(ResMgr::Create(s.str)) //Copy Ctor
        {cout << "C-Ctor[R]";}

        MyResource(MyResource&& s) noexcept: str(s.str) //Move Ctor
        {cout << "M-Ctor[R]"; s.str = nullptr;}

        MyResource& operator=(const MyResource& s){ // Copy Assignment
            cout << "C=[R] ";
            if (this != &s){ // this is the address and *this is the object
                ResMgr::Release(str);
                str = ResMgr::Create(s.str);
                return *this; // to allow for chaining a=b=c;
            }
        }

        MyResource& operator=(MyResource&& s) noexcept { // Copy Assignment
            cout << "C=[R] ";
            if (this != &s){ // this is the address and *this is the object
                ResMgr::Release(str);
                str = s.str;
                s.str =nullptr;
                return *this; // to allow for chaining a=b=c;
            }
        }

        ~MyResource(){
            cout << "Dtor[R] ";
            ResMgr::Release(str);
        }

        friend ostream& operator <<(ostream& os, const MyResource& s){
            cout << ((s.str) ? s.str:"null"); return os;
        }
};

MyResource f(MyResource s){ //global function. Uses call by value, return by value
    cout << "f[R] "; return s;
}
unsigned int ResMgr::nCreated = 0;
unsigned int ResMgr::nReleased = 0;

ResMgr m;

int main(){
    MyResource r1{"ppd"}; // constructed with parameter
    cout << "r1=" <<r1;
    ResMgr::Stat();

    MyResource r2{r1}; // copy-constructor used
    cout << "r2=" << r2 << " r1= " << r1; 
    ResMgr::Stat();

    MyResource r3{f(r2)};
    cout << "r3= " <<r3 << " r2= " << r2;
    ResMgr::Stat();

    MyResource r4;
    cout << "r4= " << r4;
    ResMgr::Stat(); // default ctor

    r4 = f(r3);
    cout <<"r4= " << r4;
    ResMgr::Stat();

}

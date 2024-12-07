#include <iostream>
using namespace std;

void (*func)();

void g(){
    (*func)();
}
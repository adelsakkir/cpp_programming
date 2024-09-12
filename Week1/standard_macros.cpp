#include <iostream>
using namespace std;

int main()
{
    cout << "This is line number " << __LINE__;
    cout << " of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The complier gives a __cplusplus value of " << __cplusplus;
    return 0;
}
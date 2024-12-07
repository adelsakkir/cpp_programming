#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "Hello, I am Adel. I am the sexiest cookie in town." << endl;
    myfile << "I am not in town. ";
    myfile.close();

}
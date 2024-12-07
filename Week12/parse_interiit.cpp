#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;

class Corner{
    public:
    int x,y,z;
    Corner(int a, int b, int c): x(a), y(b), z(c){}

};

class Package{
    public:
    bool picked;
    string package_id;
    string uld;
    Corner c1,c2;

    Package(bool pick_status, string package_id, string uld, int x1, int y1, int z1, int x2, int y2, int z2): picked(pick_status), package_id(package_id), uld(uld),c1(Corner(x1,y1,z1)), c2(Corner(x2,y2,z2)){}


};

int main(){
    ifstream file("sample.txt");

    if (!file.is_open()) { // Check if file was opened successfully
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    int cost, picked, p_uld;
    char ch;
    string line;
    getline(file, line);
    stringstream ss(line);
    ss >> cost >> ch >> picked >> p_uld;
    cout << "cost: "<<cost << ", picked: "<<picked << ", Priority ULDs: " << p_uld <<endl;

    string package; string uld; int x1, y1, z1, x2, y2, z2;
    vector<Package> packages;
    while (getline(file, line)) { // Read file line by line
        cout << line << endl;    // Output the line

        stringstream ss(line);
        getline(ss, package, ',');
        getline(ss, uld, ',');


        ss>> x1>>ch >>y1>>ch >>z1>>ch >>x2>>ch >> y2>>ch >> z2;
        cout <<package << ' ' << uld <<endl;
        cout << x1 << y1 <<z1 <<x2<<y2<<z2<<endl;
        

        if (x1!= -1){
            cout<<"Package " << package << " is selected!"<<endl;
            Package p1 = {true, package, uld, x1,y1,z1, x2, y2, z2};
            // packages.push_back(Package(true, package, uld, x1,y1,z1, x2, y2, z2));
            packages.push_back(p1);
            }
        else{
            cout<<"Package " << package << " is not selected!"<<endl;
            packages.push_back(Package(false, package, uld, x1,y1,z1, x2, y2, z2));
            }

        
    }
    cout <<"Checking - " << "Id: " << packages[2].package_id << ", ULD: " << packages[2].uld<< endl;
    cout <<"Checking - " << "Id: " << packages[11].package_id << ", ULD: " << packages[11].uld <<endl;
    file.close(); // Close the file
    return 0;

}
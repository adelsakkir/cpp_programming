#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

void parseInts(stringstream& ss, vector<int>& vec) {
    string token;
    while (getline(ss, token, ',')) { // Split the input by ','
        int num = stoi(token);       // Convert token to an integer
        vec.push_back(num);          // Add the integer to the vector
    }
}

int main() {
    string inp;
    cin >> inp;                      // Read the input string
    stringstream ss(inp);            // Create a stringstream
    vector<int> result;              // Create an empty vector
    parseInts(ss, result);           // Populate the vector by reference

    for (int num : result) {         // Output the integers
        cout << num << endl;
    }
    
    return 0;
}

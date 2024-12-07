#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

void f(vector<double>& vd, int* p, int n){
    double sum = accumulate(vd.begin(), vd.end(), 0.0);

    int si = accumulate(p, p+n, 0);
    double s1 = accumulate(p, p+n, 0.0);

    cout << sum <<endl;
    cout << si <<endl;
    cout << s1 <<endl;
}

int main(){
    vector<int> v = {1,2,3,4};
    vector<double> vd = {1.5, 2.7, 3.2, 4.9};
    f(vd, &v[0], v.size());
}
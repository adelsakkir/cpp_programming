#include<iostream>
#include<vector>
#include<numeric>
#include<functional>

using namespace std;

class addi{
    public:
        double operator()(const double& a, const double& b){
            return a+b; 
        };
};

int main(){
    vector<int> v = {1,2,3,4};
    vector<double> vd = {1.5, 2.7, 3.2, 4.9};
    addi a,b;
    // int summ = accumulate(vd.begin(), vd.end(), )
    double in = inner_product(vd.begin(), vd.end(), v.begin(), 0.0);
    double in2 = inner_product(vd.begin(), vd.end(), v.begin(), 0.0, plus<double>() , multiplies<double>());
    double in3 = inner_product(vd.begin(), vd.end(), v.begin(), 0.0, plus<double>() , plus<double>());
    double in4 = inner_product(vd.begin(), vd.end(), v.begin(), 0.0, addi(), addi());
    double in5 = inner_product(vd.begin(), vd.end(), v.begin(), 0.0, a, b);
    cout<< in << endl;
    cout<<in2 <<endl;
    cout <<in3 <<endl;
    cout << in4 <<endl;
    cout << in5 <<endl;
    // f(vd, &v[0], v.size());
}
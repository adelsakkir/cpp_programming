#include <iostream>
using namespace std;
#include <cmath>

template <typename T = int, unsigned int N = 4>
class Int_{
    public:
    T v_;

    Int_(T a): v_(a){};
    // static const int MaxInt = (1 << (N - 1)) - 1;
    // static const int MinInt = -(1 << (N - 1));

    static const Int_<T,N> MaxInt;
    static const Int_<T,N> MinInt;

    Int_ operator+(const T &b){
        T result = this->v_ + b;

        // Handle overflow/underflow based on N-bit integer range
        if (result > MaxInt.v_) {
            result = result - (1 << N);
        } else if (result < MinInt.v_) {
            result = result + (1 << N);
        }

        return Int_(result);
    }
};
typedef Int_<int, 4> Int;

template <typename T, unsigned int N>
const Int_<T, N> Int_<T, N>::MaxInt((1 << (N - 1)) - 1);  // Max value for N-bit signed int

template <typename T, unsigned int N>
const Int_<T, N> Int_<T, N>::MinInt(-(1 << (N - 1)));

int main(){
    Int x = Int(15);
    Int y = x +3; 
    cout << y.v_<< endl;
}
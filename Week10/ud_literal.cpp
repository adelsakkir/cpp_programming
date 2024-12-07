#include <iostream>
#include <complex>
#include <cmath>  // Optional, for math functions if needed
using namespace std;

constexpr complex<double> operator"" _i(const long double d){
    return complex<double>{0.0, static_cast<double>(d)};
};

constexpr  double operator"" _km(const long double d){
    return d*1000;
};

template<typename T> class KnowType;
// #include <iostream>
#include <typeinfo> // For typeid

int main() {
    auto x = 42.0_km;  // auto deduces x as int
    std::cout << "Type of x: " << typeid(x).name() << std::endl;
    // KnowType<decltype(x)> arr_type;
    
    auto y = 42.5+ 3.0_i; // auto deduces y as double
    std::cout << "Type of y: " << typeid(y).name() << std::endl;
    // KnowType<decltype(y)> arr_type;

    return 0;
}


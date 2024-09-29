#include <iostream>
using namespace std;
#include <cmath>

class Complex {
private:
    double real;    // Real part
    double imag;    // Imaginary part

public:
    // Constructors
    Complex() : real(0), imag(0) {}              // Default constructor
    Complex(double r, double i) : real(r), imag(i) {}  // Parameterized constructor

    // Getter functions
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Setter functions
    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    // Overload the addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    

    // Overload the subtraction operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload the multiplication operator
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,  // Real part
            real * other.imag + imag * other.real   // Imaginary part
        );
    }

    // Overload the division operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,  // Real part
            (imag * other.real - real * other.imag) / denominator   // Imaginary part
        );
    }

    // Overload the output stream operator (<<) to print complex numbers
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << fabs(c.imag) << "i";
        return os;
    }

    // Overload the input stream operator (>>) to input complex numbers
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }

    friend Complex operator+(const int first, const Complex& second);
};

Complex operator+(const int first, const Complex& second) {
        return Complex(first + second.real, second.imag);
    }

int main() {
    Complex c1(3, 4);  // Complex number 3 + 4i
    Complex c2(1, -2); // Complex number 1 - 2i
    Complex c3;

    // Addition
    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    Complex c7 = 6+ c1;
    cout << "6+c1 = " << c7 << endl;

    // Subtraction
    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << endl;

    // Multiplication
    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3 << endl;

    // Division
    c3 = c1 / c2;
    cout << "c1 / c2 = " << c3 << endl;

    // Input a complex number
    cout << "Enter a complex number: ";
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    return 0;
}

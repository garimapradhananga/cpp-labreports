#include <iostream>
using namespace std;
class Complex {
private:
    int real, imag;
public:
    void input(){
        cout << "Enter Real Part: ";
        cin >> real;
        cout << "Enter Imaginary Part: ";
        cin >> imag;
    }
    void add(Complex c){
        cout << "Sum = "<< real + c.real << " + "<< imag + c.imag << "i" << endl;
    }
    void subtract(Complex c){
        cout << "Difference = "<< real - c.real << " + "<< imag - c.imag << "i" << endl;
    }
    void multiply(Complex c) {
        int r = real * c.real - imag * c.imag;
        int i = real * c.imag + imag * c.real;
        cout << "Product = "<< r << " + " << i << "i" << endl;
    }
    ~Complex() {
        cout << "Object Destroyed." << endl;
    }
};
int main() {
    Complex c1, c2;
    cout << "Enter First Complex Number:\n";
    c1.input();
    cout << "\nEnter Second Complex Number:\n";
    c2.input();
    cout << endl;
    c1.add(c2);
    c1.subtract(c2);
    c1.multiply(c2);
    return 0;
}
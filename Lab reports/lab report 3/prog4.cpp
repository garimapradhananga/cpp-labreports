#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;
public:
    Complex(){
        real = 0;
        imag = 0;
    }
    void input(){
        cout << "Enter real and imaginary part: ";
        cin >> real >> imag;
    }
    Complex add(Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    Complex subtract(Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    Complex multiply(Complex c)
    {
        Complex temp;
        temp.real = real * c.real - imag * c.imag;
        temp.imag = real * c.imag + imag * c.real;
        return temp;
    }
    void display()
    {
        if(imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};
int main()
{
    Complex c1, c2, sum, diff, prod;
    cout << "Enter First Complex Number:\n";
    c1.input();
    cout << "Enter Second Complex Number:\n";
    c2.input();
    sum = c1.add(c2);
    diff = c1.subtract(c2);
    prod = c1.multiply(c2);
    cout << "\nSum = ";
    sum.display();
    cout << "\nDifference = ";
    diff.display();
    cout << "\nProduct = ";
    prod.display();
    return 0;
}
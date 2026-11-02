/*taking two complex numbers and calculate sum and product 
#include<iostream>
using namespace std;

class Complex {
    int real;
    int imag;

public:
    // Constructor
    Complex(int r, int i) {
        this->real = r;   // using this pointer
        this->imag = i;
    }

    // Function to add two complex numbers
    void add(Complex c1, Complex c2) {
        this->real = c1.real + c2.real;
        this->imag = c1.imag + c2.imag;
    }

    // Function to multiply two complex numbers
    void multiply(Complex c1, Complex c2) {
        this->real =(c1.real*c2.real)-(c1.imag*c2.imag);
        this->imag =(c1.real*c2.imag)+(c1.imag*c2.real);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    // Destructor
    ~Complex() {
        cout << "Object destroyed (out of scope)\n";
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex result(0, 0);

    cout << "First Complex: ";
    c1.display();

    cout << "Second Complex: ";
    c2.display();

    result.add(c1, c2);
    cout << "Sum: ";
    result.display();

    result.multiply(c1, c2);
    cout << "Product: ";
    result.display();

    return 0;
}
    

#include<iostream>
using namespace std;
class sample{
    int x;
   // float x;
};
int main(){
    sample obj;
    cout<<"the size of the object: "<<sizeof(obj);
    return 0;
}
*/
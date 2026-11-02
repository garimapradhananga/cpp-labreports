#include <iostream>
using namespace std;
class Fahrenheit;
class Celsius {
    float c;
public:
    Celsius(float temp) {
        c = temp;
    }
    operator Fahrenheit();
};
class Fahrenheit {
    float f;
public:
    Fahrenheit(float temp = 0) {
        f = temp;
    }
    void display() {
        cout << "Temperature in Fahrenheit = " << f << " F" << endl;
    }
};
Celsius::operator Fahrenheit() {
    return Fahrenheit((c * 9.0 / 5.0) + 32);
}
int main() {
    float temp;
    cout << "Enter temperature in Celsius: ";
    cin >> temp;
    Celsius c(temp);
    Fahrenheit f;
    f = c;
    f.display();
    return 0;
}
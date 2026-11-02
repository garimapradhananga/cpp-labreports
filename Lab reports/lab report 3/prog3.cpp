#include <iostream>
using namespace std;
class temperature
{
private:
    float temp;
public:
    void input(){
        cout<<"Enter temperature: ";
        cin>>temp;
    }
    void celsiusToFahrenheit(){
        cout<<"Temperature in Fahrenheit = "<< (temp * 9 / 5) + 32 << endl;
    }
    void fahrenheitToCelsius() {
        cout << "Temperature in Celsius = "<< (temp - 32) * 5 / 9 << endl;
    }
};
int main()
{
    temperature t;
    int choice;
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter your choice: ";
    cin >> choice;
    t.input();
    if (choice == 1)
        t.celsiusToFahrenheit();
    else if (choice == 2)
        t.fahrenheitToCelsius();
    else
        cout << "Invalid Choice";
    return 0;
}
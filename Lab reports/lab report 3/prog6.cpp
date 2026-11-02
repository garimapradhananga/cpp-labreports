#include <iostream>
using namespace std;

class ABC
{
public:
    ABC() // constructor
    {
        cout << "Constructor called" << endl;
    }

    ~ABC() // destructor
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    ABC A; // Constructor Called

    int x = 10;
    if (x == 10)
    {
        ABC A1; // Constructor Called
    } // Destructor Called for A1

} // Destructor called for A
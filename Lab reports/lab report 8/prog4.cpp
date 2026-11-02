//4. Write a program to implement the exception handling with uncaught exception.

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (b == 0)
        throw b;     // Exception is thrown but not caught

    cout << "Result = " << a / b << endl;

    return 0;
}
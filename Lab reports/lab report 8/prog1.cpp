//Write a program to implement the exception handling with multiple catch statement.
#include<iostream>
using namespace std;
int main()
{
    int choice;
    cout << "Choose an operation:" << endl;
    cout << "1. Division" << endl;
    cout << "2. Array Access" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    try
    {
        if (choice == 1){
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (b == 0)
                throw b;
            cout << "Result = " << a / b << endl;
        }
        else if (choice == 2){
            int arr[5] = {10, 20, 30, 40, 50};
            int index;
            cout << "Enter array index (0-4): ";
            cin >> index;
            if (index < 0 || index > 4)
                throw 'A';
            cout << "Element = " << arr[index] << endl;
        }
        else{
            cout << "Invalid choice!" << endl;
        }
    }
    catch (int){
        cout << "Exception: Division by zero is not allowed." << endl;
    }
    catch (char){
        cout << "Exception: Array index out of bounds." << endl;
    }

    return 0;
}
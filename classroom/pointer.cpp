#include <iostream>
using namespace std;

class Student {
public:
    string name;
    void display() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student *ptr = new Student();  // pointer to object

    ptr->name = "Alice";           // access using ->
    ptr->display();

    delete ptr; // free memory
    return 0;
}
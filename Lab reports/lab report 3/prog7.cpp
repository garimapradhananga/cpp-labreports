#include <iostream>
using namespace std;
class Student {
private:
    int roll_no;
    string name;
    int age;
public:
    Student() {
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }
    void display() {
        cout << "\nStudent Details:\n";
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    ~Student() {
        cout << "\nDestructor Called." << endl;
    }
};
int main() {
    Student s;
    s.display();
    return 0;
}
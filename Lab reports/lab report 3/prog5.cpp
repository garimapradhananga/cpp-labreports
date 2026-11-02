#include <iostream>
using namespace std;
class Employee {
private:
    string name;
    int joiningYear;
    string address;
    int salary;
public:
    void input(string n, int y, string a, int s) {
        name = n;
        joiningYear = y;
        address = a;
        salary = s;
    }
    void display() {
        cout << name << "\t"
             << joiningYear << "\t\t"
             << address << "\t\t"
             << salary << endl;
    }
};
int main() {
    Employee e1, e2, e3;
    e1.input("Aastik", 2020, "Patan", 2500);
    e2.input("Aman", 2024, "Biratnagar", 2400);
    e3.input("Sabira", 2005, "Bhaktapur", 5500);
    cout << "Name\tJoining Year\tAddress\t\tSalary\n";
    e1.display();
    e2.display();
    e3.display();
    return 0;
}
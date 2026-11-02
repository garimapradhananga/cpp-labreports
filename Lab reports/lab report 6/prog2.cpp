#include<iostream>
using namespace std;
class employee
{
protected:
    char name[50];
    char address[50];
public:
    void getdata(){
        cout << "Enter employee name and address: ";
        cin >> name >> address;
    }
    void showdata(){
        cout << "Employee Name = " << name << endl;
        cout << "Employee Address = " << address << endl;
    }
};
class student{
protected:
    char name[50];
    char address[50];
public:
    void getdata(){
        cout << "Enter student name and address: ";
        cin >> name >> address;
    }
    void showdata(){
        cout << "Student Name = " << name << endl;
        cout << "Student Address = " << address << endl;
    }
};
class manager : public employee, public student{
protected:
    int id;
public:
    void getmanager(){
        employee::getdata();
        student::getdata();
        cout << "Enter manager ID: ";
        cin >> id;
    }
    void showdata()
    {
        cout << "\nManager Details" << endl;
        cout << "Manager ID = " << id << endl;
        employee::showdata();
        student::showdata();
    }
};
int main()
{
    manager m;
    m.getmanager();
    m.showdata();
    return 0;
}
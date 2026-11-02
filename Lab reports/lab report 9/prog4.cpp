/*SEARCHING USING CRN (FILE HANDLING)*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Student{
private:
    char name[30];
    int age;
    char crn[20];
public:
    void getdata(){
        cout << "Enter name, age and CRN: ";
        cin >> name >> age >> crn;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CRN: " << crn << endl;
    }
    void writetofile(ofstream &out){
        out << name << " " << age << " " << crn << endl;
    }
    void readfromfile(ifstream &in){
        in >> name >> age >> crn;
    }
    char* getcrn(){
        return crn;
    }
};
int main(){
    int n;
    char searchCRN[20];
    bool found = false;
    cout << "Enter number of students: ";
    cin >> n;
    Student s[n];
    ofstream out("students.txt");
    if (!out){
        cout << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++){
        cout << "\nEnter details of student " << i + 1 << ":" << endl;
        s[i].getdata();
        s[i].writetofile(out);
    }
    out.close();
    ifstream in("students.txt");
    if (!in){
        cout << "Error opening file!" << endl;
        return 1;
    }
    cout << "\nEnter CRN to search: ";
    cin >> searchCRN;
    Student temp;
    for (int i = 0; i < n; i++){
        temp.readfromfile(in);
        if (strcmp(temp.getcrn(), searchCRN) == 0){
            cout << "\nStudent record found:" << endl;
            temp.display();
            found = true;
            break;
        }
    }
    in.close();
    if (!found) {
        cout << "Student record not found." << endl;
    }
    return 0;
}
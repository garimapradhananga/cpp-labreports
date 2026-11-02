/*wap that stores info of a students in a file and display the file content
in descending order according to their marks obtained*/
#include <iostream>
#include <fstream>
using namespace std;
class student{
private:
    char name[20];
    int rollno;
    float marks;
public:
    void getdata(){
        cout << "Enter name, roll number and marks: ";
        cin >> name >> rollno >> marks;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: " << marks << endl;
    }
    float getmarks(){
        return marks;
    }
    void writetofile(ofstream &out){
        out << name << " " << rollno << " " << marks << endl;
    }
    void readfromfile(ifstream &in){
        in >> name >> rollno >> marks;
    }
};
int main(){
    int no;
    cout << "Enter number of students: ";
    cin >> no;
    student s[no];
    ofstream out("students.txt", ios::out);
    if (!out)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 0; i < no; i++)
    {
        cout << "Enter details of student " << i + 1 << ":" << endl;
        s[i].getdata();
        s[i].writetofile(out);
    }
    out.close();
    ifstream in("students.txt", ios::in);
    if (!in)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    student students[no];
    for (int i = 0; i < no; i++){
        students[i].readfromfile(in);
    }
    in.close();
    for (int i = 0; i < no - 1; i++) {
        for (int j = i + 1; j < no; j++)
        {
            if (students[i].getmarks() < students[j].getmarks()){
                student temp;
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    cout << "\nStudent information in descending order of marks:" << endl;
    for (int i = 0; i < no; i++){
        students[i].display();
    }
    return 0;
}
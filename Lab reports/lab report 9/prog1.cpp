/*class with members (name, roll number, director and file name and other member function as required. all the objects of that  class will share
two members directory and file name where the info of student is stored)*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student{
    string name;
    int rn;
    static string directory; //since all the members of the class will share the same directory and file name
    static string filename;
    public:
        void getdata(){
            cout<<"Enter name and roll number: "<<endl;
            cin>>name>>rn;
        }
        void savetofile(){
            ofstream out;
            out.open(directory + filename, ios::app);
            if (!out){
                cout<<"Error opening file!"<<endl;
                return;
            }
        out <<"Name: "<<name<<endl;
        out <<"Roll Number: "<<rn<<endl;
        out.close();
        }
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<rn<<endl;
        }
};
string student::directory=""; //initialize static member directory
string student::filename=""; //initialize static member filename
int main(){
    student s1, s2;
    s1.getdata();
    s1.savetofile();
    s2.getdata();
    s2.savetofile();
    cout<<"Student information saved to file."<<endl;
    cout<<"Displaying student information:"<<endl;
    s1.display();
    s2.display();
    return 0;
}
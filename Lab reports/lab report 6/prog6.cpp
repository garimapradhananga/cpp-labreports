#include<iostream>
using namespace std;

class Person{
protected:
    char name[30];
    int age;

public:
    void getData(){
        cout<<"Enter name and age: "<<endl;
        cin>>name>>age;
    }

    void showData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Student : public Person{
    int roll;

public:
    void getStudent(){
        getData();
        cout<<"Enter roll number: ";
        cin>>roll;
    }

    void showStudent(){
        showData();
        cout<<"Roll Number: "<<roll<<endl;
    }
};

class Teacher : public Person{
    char subject[30];

public:
    void getTeacher(){
        getData();
        cout<<"Enter subject: ";
        cin>>subject;
    }

    void showTeacher(){
        showData();
        cout<<"Subject: "<<subject<<endl;
    }
};

class Doctor : public Person{
    char specialization[30];

public:
    void getDoctor(){
        getData();
        cout<<"Enter specialization: ";
        cin>>specialization;
    }

    void showDoctor(){
        showData();
        cout<<"Specialization: "<<specialization<<endl;
    }
};

int main(){

    Student s;
    Teacher t;
    Doctor d;

    cout<<"Student "<<endl;
    s.getStudent();
    s.showStudent();

    cout<<"\nTeacher "<<endl;
    t.getTeacher();
    t.showTeacher();

    cout<<"\nDoctor "<<endl;
    d.getDoctor();
    d.showDoctor();

    return 0;
}
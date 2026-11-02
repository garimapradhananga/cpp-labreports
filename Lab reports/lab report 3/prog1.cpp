#include <iostream>
using namespace std;
class Student {
private:
int roll_no;
string name;
int age;
public:
void input(){
cout<<"Enter your Roll_no: ";
cin>>roll_no;
cout<<"Enter your name: ";
cin>>name;
cout<<"Enter your age: ";
cin>>age;
}
void display(){
cout<<"Full Detail of Student: "<<endl;
cout<<"Roll No.: "<<roll_no<<"\nName:"<<name<<"\nAge: "<<age;
}
};
int main() {
Student s;
s.input();
s.display();
return 0;
}


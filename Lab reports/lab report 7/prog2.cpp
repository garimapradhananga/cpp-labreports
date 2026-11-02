#include<iostream>
using namespace std;
class student {
    public:
    virtual void display()=0; //pure virtual function 
};
class engineering : public student{
    public:
    void display(){
            cout<<"Engineering student"<<endl;
        }
};
class science: public student{
    public:
    void display(){
            cout<<"Science student"<<endl;
        }
};
class medical : public student{
    public:
    void display(){
            cout<<"Medical student"<<endl;
        }
};

int main(){
    student *ptr;
    engineering e;
    science s;
    medical m;
    ptr=&e;
    ptr->display();
    ptr=&s;
    ptr->display();
    ptr=&m;
    ptr->display();
    return 0;
}
#include<iostream>
using namespace std;

class A{
public:
    A(int x){
        cout<<"Parameterized constructor of A: "<<x<<endl;
    }
    ~A(){
        cout<<"Destructor of A"<<endl;
    }
};

class B{
public:
    B(){
        cout<<"Constructor of B"<<endl;
    }
    ~B(){
        cout<<"Destructor of B"<<endl;
    }
};

class C: public A, public B{
public:
    C() : A(10){
        cout<<"Constructor of C"<<endl;
    }
    ~C(){
        cout<<"Destructor of C"<<endl;
    }
};

int main(){
    C obj;
    return 0;
}
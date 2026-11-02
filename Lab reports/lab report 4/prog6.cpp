#include<iostream>
using namespace std;
class A{
    int x;
    public:
    A(){
        x=0;
    }
    friend class B;
};
class B{
    public:
    void display(A &a){
        cout<<"value of x:"<<a.x<<endl;
    }
};
int main(){
    A a1;
    B b1;
    b1.display(a1);
    return 0;
}
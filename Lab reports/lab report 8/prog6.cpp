//6.	Write a program illustrating the exception on inheritance level.
#include<iostream>
using namespace std;
class Exception{
    public:
    virtual void display(){
        cout<<"Base exception"<<endl;
    }
};
class dividebyzero:public Exception{
    public:
    void display(){
        cout<<"Exception: Division by zero is not allowed."<<endl;
    }
};
int main(){
    int a,b;
    cout<<"enter two numbers:";
    cin>>a>>b;
    try{
        if (b==0){
            throw dividebyzero();
        }
        cout<<"Result = "<<a/b<<endl;
    }
    catch (Exception &obj){
        obj.display();
    }
    return 0;
}
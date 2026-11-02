//5.Write a program illustrating the exception on object level.
#include<iostream>
using namespace std;
class DivideByZero{
    public:
    void display(){
            cout<<"Exception: Division by zero is not allowed."<<endl;
        }
};
int main(){
    int a,b;
    cout<<"enter two numbers: ";
    cin>>a>>b;
    try{
        if (b==0){
            throw DivideByZero();
        }
        cout<<"Result = "<<a/b<<endl;
    }
    catch (DivideByZero obj){
        obj.display();
    }
    return 0;
}
//Write a program to implement the exception handling with rethrowing in exception
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two numbers: ";
    cin>>a>>b;
    try{
        try{
            if (b==0)
                throw b;
            cout<<"Result = "<<a/b<<endl;
        }
        catch(int){
            cout<<"Exception: Division by zero is not allowed."<<endl;
            cout<<"Rethrowing the exception..."<<endl;
            throw; // Rethrow the exception
        }
    }
    catch(int){
        cout<<"Exception caught in outer try block: Division by zero is not allowed."<<endl;
    }
    return 0;
}
      
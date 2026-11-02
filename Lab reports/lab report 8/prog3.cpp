//3.Write a program to implement the exception handling with the functionality of testing the throw restrictions
#include<iostream>
using namespace std;
void divide (int a, int b) throw (int){
    if (b==0){
        throw b;
    }
    cout<<"Result = "<<a/b<<endl;
}
int main(){
    int a,b;
    cout<<"enter two numbers: ";
    cin>>a>>b;
    try{
        divide(a,b);
    }
    catch(int){
        cout<<"Exception: Division by zero is not allowed."<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
template <class T>
void display (T a){
    cout<<"Template function: "<<a<<endl;
}
void display(int a){
    cout<<"Normal function:"<<a<<endl;
}
int main(){
    display(5);
    display(3.14);
    display (4.5f);
    display("Hello");
    return 0;
}
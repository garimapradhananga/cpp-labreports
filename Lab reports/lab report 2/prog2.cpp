//WAP to calculate and display the cube of integer, float and double number using function overloading
#include<iostream>
using namespace std;
void cube (int n){
    cout<<"cube of int:"<<n*n*n<<endl;
}
void cube (float n){
    cout<<"cube of float:"<<n*n*n<<endl;
}
void cube(double n) {
    cout << "Cube of double:"<<n* n*n <<endl;
}
int main(){
    int a;
    float b;
    double c;
    cout<<"enter an integer: ";
    cin>>a;
    cout<<"enter a float:";
    cin>>b;
    cout<<"enter a double:";
    cin>>c;
    cube(a);
    cube(b);
    cube(c);
    return 0;
}
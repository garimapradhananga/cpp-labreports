#include<iostream>
using namespace std;
class complex{
    float real;
    float imaginary;
    public:
    complex(){
        real=0;
        imaginary=0;
    }
    complex (float r, float i){
        real=r;
        imaginary=i;
    }
    void showdata(){
        cout<<"the resultant number is: "<<real<<"+i"<<imaginary;
    }
    friend complex multiply(complex, complex);
};
complex multiply(complex cc1,complex cc2){
    complex temp;
    temp.real=(cc1.real*cc2.real)-(cc1.imaginary*cc2.imaginary);
    temp.imaginary=(cc1.real*cc2.imaginary)+(cc2.real*cc1.imaginary);
    return temp;
}
int main(){
    complex c1(1.1,2.2),c2(2,4),c3;
    c3=multiply(c1,c2);
    c3.showdata();
    return 0;
}
#include <iostream>
using namespace std;
// function with two parameter
void add(int num1, int num2) {
cout<< "Hey!! You are calling function with two parameter of type int, int..... "<<endl;
cout << "Sum of num1 and num2 is: " << num1+num2 <<endl<<endl;
}
// function with three parameters
void add(int num1,int num2, float num3) {
cout<< "Hey!!You are calling function with three parameter of type int, int ,int...... "<<endl;
cout << "Sum of num1, num2 and num3 is: " <<num1+num2+num3<<endl<<endl;
}
// function with two parameter
void add(int num1, float num2) {
cout<< "Hey!!You are calling function with two parameter of type int, float...... "<<endl;
cout << "Sum of num1 and num2 is: " << num1+num2 <<endl<<endl;
}
int main() {
int a=10, b=20;
float c=10.10;
add(a,b);
add(a,b,c);
add(a,c);
return 0;
}
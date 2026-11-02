#include <iostream>
using namespace std;
// Program to demonstrate Function overloading in Default Arguments....
int add(int a, int b, int c = 10, int d= 20)
{
cout<<"Calling first function"<<endl;
return (a + b + c + d);
}
double add(int a, double b, double c = 10.1, double d= 20.1)
{
cout<<"Calling second function"<<endl;
return (a + b + c + d);
}
int main()
{
cout << add(10, 15) << endl;
cout << add(10, 15.1, 25.1) << endl;
cout << add(10, 15, 25, 30) << endl;
return 0;
}

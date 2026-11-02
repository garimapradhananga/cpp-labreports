#include <iostream>
using namespace std;
int add(int a, int b, int c= 10, int d = 20)
{
return (a + b + c + d);
}
int main()
{
cout << add(30, 20) << endl;
cout << add(20, 30, 40) << endl;
cout << add(20, 10, 30, 40) << endl;
return 0;
}

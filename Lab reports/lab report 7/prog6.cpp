//add two numbers using function template to pass interger, char, float and double
#include <iostream>
using namespace std;
template <class T>
T add (T a, T b){
    return a+b;
};
int main(){
    int a=5, b=10;
    char x = 'x', y = 'y';
    float e=3.14, f=2.71;
    double g=1.23456789, h=9.87654321;
    cout<<"Sum of integers: "<<add(a,b)<<endl;
    cout << "Sum of characters (ASCII): "<< add ((int)x, (int)y) << endl;
    cout<<"Sum of characters: "<<add(x,y)<<endl;
    cout<<"Sum of floats: "<<add(e,f)<<endl;
    cout<<"Sum of doubles: "<<add(g,h)<<endl;
    return 0;
}   
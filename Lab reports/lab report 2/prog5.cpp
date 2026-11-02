#include<iostream>
#include<math.h>
using namespace std;
class area{
    public:
    float calc(float length, float breadth=1){
        return length*breadth;
    }
    float calc (float a,float b, float c){
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main(){
    area obj;
    float length,breadth;  
    float a,b,c; 
    cout << "Enter rectangle length and breadth: ";
    cin >> length >> breadth;
    cout<<"area of rectangle="<<obj.calc(length,breadth)<<endl;
    cout << "\nEnter triangle's three sides: ";
    cin >> a >> b >> c;
    cout<<"area of triangle="<<obj.calc(a,b,c)<<endl;  
    return 0;
}
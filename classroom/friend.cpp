#include<iostream>
using namespace std;
class B; //class b cha bhanera prototype
class A{
    int x,y;
    public:
    void get_A(){
        x=3;
        y=4;
    }
    friend int common_fun(A,B);
};
class B{
    int x,y;
    public:
    void get_B(){
        x=10;
        y=20;
    }
     friend int common_fun(A,B);
};
int common_fun(A obja, B objb){
    return (obja.x*objb.x+obja.y*objb.y); //out of class(violates the rule of encapsulation)
}
int main(){
    A obja;
    B objb;
    int result; 
    obja.get_A();
    objb.get_B();
    result=common_fun(obja,objb);
    cout<<result;

}

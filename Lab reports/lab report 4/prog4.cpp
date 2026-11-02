#include<iostream>
using namespace std;
class Sample{
    int x;
    public:
    Sample(){
        x=0;
    }
    void display(){
        cout<<"value of x is"<<x<<endl;
    }
    friend void add (Sample &s);
};
void add (Sample &s){
    s.x=s.x+4;
}
int main(){
    Sample s1;
    s1.display();
    add (s1);
    s1.display();
    return 0;
}
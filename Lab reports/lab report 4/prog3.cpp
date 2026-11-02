#include<iostream>
using namespace std;
class Demo{
    private:
    static int count;
    public:
    Demo(){ //constructor
        count++;
        cout<<"constructor called. object count="<<count<<endl;
    }
    ~Demo(){
        cout<<"destructor called. object count="<<count<<endl;
        count--;
    }
    static void showcount(){
        cout<<"current object count="<<count<<endl;
    }
};
 int Demo::count=0;
 int main(){
    cout<<"creating objects....\n";
    Demo d1;
    Demo::showcount();
    Demo d2;
    Demo::showcount();
    Demo d3;
    Demo::showcount();
    cout<<"end of main function.\n";
    return 0;
 }
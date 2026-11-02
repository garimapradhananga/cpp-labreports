#include<iostream>
using namespace std;
class Sample{
    private: 
    int x;
    static int y;
    public:
    static void display(){ //static member function or class member function
        cout<<y<<endl;
    }
};
int Sample::y=10;
int main(){
    Sample::display();
    Sample s1;
    s1.display();
    return 0;
}
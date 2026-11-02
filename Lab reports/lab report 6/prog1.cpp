#include<iostream>
#include<string.h>
using namespace std;
class cricket{
    public:
    string name;
    int age;
    int no;
    void get(){
        cout<<"enter name, age and number of match: ";
        cin>>name>>age>>no;
    }
    void display(){
        cout<<"name: "<<name<<" age: "<<age<<" number of matches: "<<no<<endl;
    }
};
class bowler: public cricket{
    public:
    int no_w;
    void getbo(){
        cout<<"enter the number of wicket: ";
        cin>>no_w;
    }
    void displaybowler(){
        cout<<"no of wickets= "<<no_w<<endl;
    }
};
class batsman: public cricket{
    public:
    int no_r;
    void getba(){
        cout<<"enter the number of runs: ";
        cin>>no_r;
    }
    void displaybatsman(){
        cout<<"no of runs= "<<no_r<<endl;
    }
};
int main(){
    bowler b;
    batsman ba;
    cricket c;
    cout<<"cricket player details: "<<endl;
    c.get();
    cout<<"bowler details: "<<endl;
    b.get();
    b.getbo();
    b.display();
    b.displaybowler();
    cout<<"batsman details: "<<endl;
    ba.get();
    ba.getba();
    ba.display();
    ba.displaybatsman();
}
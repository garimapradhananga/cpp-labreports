#include<iostream>
using namespace std;
//abstract class
class polygon{
    protected:
        float length, height;
    public:
        void getdata(){
            cout<<"enter length and height of polygon: ";
            cin>>length>>height;
        }
        virtual void Area()=0; //pure virtual function
};
class rectangle: public polygon{
    public:
        void Area(){
            cout<<"Area of rectangle: "<<length*height<<endl;
        }
};
class triangle: public polygon{
    public:
        void Area(){
            cout<<"Area of triangle: "<<0.5*length*height<<endl;
        }
};
int main(){
    rectangle r;
    triangle t;
    cout<<"rectangle:"<<endl;
    r.getdata();
    r.Area();       
    cout<<"triangle:"<<endl;
    t.getdata();
    t.Area();
    return 0;
}

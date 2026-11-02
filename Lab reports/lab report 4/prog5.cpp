#include<iostream>
using namespace std;
class Distance{
int feet;
float inches;
public:
Distance(int f=0,float i=0){
feet=f;
inches=i;
}
void display(){
cout<<feet<<" feet "<<inches<<" inches"<<endl;
}
friend Distance addDistance(Distance,Distance);
};
Distance addDistance(Distance d1,Distance d2){
Distance temp;
temp.feet=d1.feet+d2.feet;
temp.inches=d1.inches+d2.inches;
if(temp.inches>=12){
temp.feet+=(int)temp.inches/12;
temp.inches=(int)temp.inches%12;
}
return temp;
}
int main(){
int f1,f2;float i1,i2;
cout<<"Enter 1st distance (feet inches): ";
cin>>f1>>i1;
cout<<"Enter 2nd distance (feet inches): ";
cin>>f2>>i2;
Distance d1(f1,i1),d2(f2,i2);
Distance d3=addDistance(d1,d2);
cout<<"First: ";d1.display();
cout<<"Second: ";d2.display();
cout<<"Sum: ";d3.display();
return 0;
}